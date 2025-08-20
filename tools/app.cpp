// main.cpp

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <cstdio> // for std::snprintf

// ─────────── ImGui & Backend includes (SDL2 + OpenGL3 + GLEW) ───────────
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

#include <SDL.h>
#include <GL/glew.h> // Initialize with glewInit()

// ─────────── JSON_IO (Boost.Hana + nlohmann::json) ───────────
#include "json_io.hpp"

constexpr int win_width = 180;

// GUI by template metaprogramming ──────────────────────────────────
namespace hana = boost::hana;

template <typename T>
bool render_gui(T& obj) {
  bool modified = false;

  static std::unordered_map<std::string, std::array<char, 128>> string_buffers;

  hana::for_each(hana::accessors<T>(), [&](auto const& pair) {
    auto hana_name = hana::first(pair);
    auto name_str = hana::to<const char*>(hana_name);
    auto& field = hana::second(pair)(obj);

    using FieldT = std::decay_t<decltype(field)>;

    if constexpr (std::is_same_v<FieldT, std::string>) {
      auto& buf = string_buffers[name_str];
      std::strncpy(buf.data(), field.c_str(), buf.size());
      if (ImGui::InputText(name_str, buf.data(), buf.size())) {
        field = buf.data();
        modified = true;
      }
    } else if constexpr (std::is_same_v<FieldT, int>) {
      ImGui::SetNextItemWidth(80.0f);
      modified |= ImGui::InputInt(name_str, &field);
    } else if constexpr (std::is_same_v<FieldT, float>) {
      modified |= ImGui::InputFloat(name_str, &field);
    } else if constexpr (std::is_same_v<FieldT, bool>) {
      modified |= ImGui::Checkbox(name_str, &field);
    } else if constexpr (hana::Struct<FieldT>::value && std::is_class_v<FieldT>) {
      // Optional: support nested structs (recursive render_gui)
      ImGui::SeparatorText(name_str);
      render_gui(field);
    } else if constexpr (requires { field.begin(); field.end(); }) {
      using ElemT = typename FieldT::value_type;
      if (ImGui::TreeNode(name_str)) {
        for (size_t i = 0; i < field.size(); ++i) {
          std::string label = std::string(name_str) + "[" + std::to_string(i) + "]";
          if constexpr (std::is_same_v<ElemT, int>) {
            modified |= ImGui::InputInt(label.c_str(), &field[i]);
          } else if constexpr (std::is_same_v<ElemT, float>) {
            modified |= ImGui::InputFloat(label.c_str(), &field[i]);
          } else if constexpr (std::is_same_v<ElemT, bool>) {
            modified |= ImGui::Checkbox(label.c_str(), &field[i]);
          } else if constexpr (std::is_same_v<ElemT, std::string>) {
            static std::unordered_map<std::string, std::array<char, 128>> vec_buffers;
            auto& buf = vec_buffers[label];
            std::strncpy(buf.data(), field[i].c_str(), buf.size());
            if (ImGui::InputText(label.c_str(), buf.data(), buf.size())) {
              field[i] = buf.data();
              modified = true;
            }
          }

          ImGui::SameLine();
          if (ImGui::SmallButton(("Remove##" + label).c_str())) {
            field.erase(field.begin() + i);
            modified = true;
            break; // avoid invalidating iterator
          }
        }

        if (ImGui::Button(("Add##" + std::string(name_str)).c_str())) {
          field.push_back(ElemT{});
          modified = true;
        }

        ImGui::TreePop();
      }
    }
  });

  return modified;
}

// Helper: extract filename from a full path
static std::string filename_from_path(const std::string& fullpath) {
  return std::filesystem::path(fullpath).filename().string();
}

template <typename T>
struct Entry {
  std::string file_path;
  T data;
};

template <typename EntryT>
void render_struct_tabs(std::string const& tab_bar_id,
                        std::vector<EntryT>& entries,
                        std::function<void()> reload_func = nullptr) {
  using StructT = decltype(entries[0].data);

  if (ImGui::BeginTabBar(tab_bar_id.c_str(), ImGuiTabBarFlags_Reorderable)) {
    if (reload_func) {
      reload_func();
    }

    for (size_t i = 0; i < entries.size(); ++i) {
      const std::string tab_label = filename_from_path(entries[i].file_path);
      if (ImGui::BeginTabItem(tab_label.c_str())) {
        StructT& obj = entries[i].data;

        if (render_gui(obj)) {
          JsonIO::overwrite(entries[i].file_path, obj);
        }

        ImGui::EndTabItem();
      }
    }

    ImGui::EndTabBar();
  }
}

// Define our Skill struct and JSON (de)serialization glue
JSON_IO_STRUCT(Core,
               (int, Armor),
               (int, Hp),
               (int, Stress),
               (int, Hope),
               (int, Evasion),
               (int, Minor_Damage),
               (int, Major_Damage),
               (int, Severe_Damage));

// Define our Item struct and JSON (de)serialization glue
JSON_IO_STRUCT(Stats,
               (int, Agility),
               (int, Strength),
               (int, Finesse),
               (int, Instinct),
               (int, Presence),
               (int, Knowledge));

// SDL error helper
static void sdl_die(const char* msg) {
  std::cerr << msg << "\nSDL_Error: " << SDL_GetError() << std::endl;
  std::exit(1);
}

static ImVec2 MeasureTabContent(std::function<void()> draw_tab_content) {
  ImGui::BeginChild("__measure__", ImVec2(0, 0),
                    ImGuiChildFlags_AutoResizeX | ImGuiChildFlags_AutoResizeY,
                    ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse |
                      ImGuiWindowFlags_NoBackground);
  draw_tab_content();
  ImGui::EndChild();
  return ImGui::GetItemRectSize();
}

int main(int, char**) {
  // ──────────────────────────────────────────────────────────────────────────
  // 1) Initialize SDL2 + create an OpenGL 3.3 context
  // ──────────────────────────────────────────────────────────────────────────
  SDL_SetHint(SDL_HINT_VIDEODRIVER, "x11"); // forces X11 backend if available
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
    sdl_die("Error: SDL_Init failed!");
  }

  // Request an OpenGL 3.3 Core profile context
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  // Enable double buffering
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  // 24-bit depth buffer
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  // 8-bit stencil buffer
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  // Create SDL window
  int win_w = win_width;
  int win_h = 180;
  SDL_Rect display_bounds;
  if (SDL_GetDisplayUsableBounds(0, &display_bounds) != 0) {
    SDL_Log("SDL_GetDisplayUsableBounds failed: %s", SDL_GetError());
    return 1;
  }
  int x = display_bounds.x + (display_bounds.w - win_w); // right aligned
  int y = display_bounds.y;                              // top aligned
  SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL |
                                                   SDL_WINDOW_ALWAYS_ON_TOP |
                                                   SDL_WINDOW_BORDERLESS |
                                                   SDL_WINDOW_ALLOW_HIGHDPI);
  SDL_Window* window = SDL_CreateWindow(
    "app",
    x, y,
    win_w, win_h,
    window_flags);
  SDL_ShowWindow(window);                     // make sure it's shown
  SDL_SetWindowAlwaysOnTop(window, SDL_TRUE); // enforce top-most
  SDL_RaiseWindow(window);                    // optional nudge to front
  if (!window) {
    sdl_die("Error: SDL_CreateWindow failed!");
  }

  // Create OpenGL context
  SDL_GLContext gl_context = SDL_GL_CreateContext(window);
  if (!gl_context) {
    sdl_die("Error: SDL_GL_CreateContext failed!");
  }

  // Enable vsync
  if (SDL_GL_SetSwapInterval(1) < 0) {
    std::cerr << "Warning: Unable to set VSync! SDL_Error: " << SDL_GetError() << std::endl;
  }

  // ──────────────────────────────────────────────────────────────────────────
  // 2) Initialize GLEW
  // ──────────────────────────────────────────────────────────────────────────
  glewExperimental = GL_TRUE;
  GLenum glew_err = glewInit();
  if (glew_err != GLEW_OK) {
    std::cerr << "Error: Failed to initialize GLEW! "
              << glewGetErrorString(glew_err) << std::endl;
    return 1;
  }
  // Clear any spurious GLEW error
  glGetError();

  // ──────────────────────────────────────────────────────────────────────────
  // 3) Setup Dear ImGui context
  // ──────────────────────────────────────────────────────────────────────────
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  // Enable Keyboard Controls + Docking
  // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  // Setup style
  ImGui::StyleColorsDark();

  // Setup Platform/Renderer backends
  ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
  ImGui_ImplOpenGL3_Init("#version 330");

  // ──────────────────────────────────────────────────────────────────────────
  // 4) Load all Skill JSON files from DATA_PATH/skills
  //    and all Item JSON files from DATA_PATH/items
  // ──────────────────────────────────────────────────────────────────────────
  std::string skill_dir = std::string(DATA_PATH) + "/skills";
  std::string item_dir = std::string(DATA_PATH) + "/items";
  // bool tokens[100] = {0};

  struct SkillEntry {
    std::string file_path;
    Core data;
  };
  std::vector<SkillEntry> skill_entries;

  struct ItemEntry {
    std::string file_path;
    Stats data;
  };
  std::vector<ItemEntry> item_entries;

  auto reload_skills = [&]() {
    skill_entries.clear();
    auto raw_skills = JsonIO::loadAllFromDir<Core>(skill_dir);
    skill_entries.reserve(raw_skills.size());
    for (auto& [path, skill_obj] : raw_skills) {
      skill_entries.push_back({path, std::move(skill_obj)});
    }
  };

  auto reload_items = [&]() {
    item_entries.clear();
    auto raw_items = JsonIO::loadAllFromDir<Stats>(item_dir);
    item_entries.reserve(raw_items.size());
    for (auto& [path, item_obj] : raw_items) {
      item_entries.push_back({path, std::move(item_obj)});
    }
  };

  reload_skills();
  reload_items();

  // ──────────────────────────────────────────────────────────────────────────
  // 5) Main loop
  // ──────────────────────────────────────────────────────────────────────────
  bool isMinimized = false;
  while (true) {
    // Poll and handle SDL events
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      ImGui_ImplSDL2_ProcessEvent(&event);
      if (event.type == SDL_QUIT) {
        goto cleanup;
      }
      if (event.type == SDL_WINDOWEVENT &&
          event.window.event == SDL_WINDOWEVENT_CLOSE &&
          event.window.windowID == SDL_GetWindowID(window)) {
        goto cleanup;
      }
    }

    // Start a new ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    // ───────────────────────────────────────────────────────────────
    // Top‐level tabs: “Skills” and “Items”
    // ───────────────────────────────────────────────────────────────
    // ImGuiIO& io = ImGui::GetIO();
    // ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    // ImGui::SetNextWindowSize(io.DisplaySize, ImGuiCond_Always);
    ImGuiStyle& st = ImGui::GetStyle();
    ImVec2 needed_content(win_width, 20);
    ImGuiViewport* vp = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(vp->Pos);
    ImGui::SetNextWindowSize(vp->Size); // includes space for the title bar
    ImGuiWindowFlags root =
      ImGuiWindowFlags_NoDecoration |
      ImGuiWindowFlags_NoMove |
      ImGuiWindowFlags_NoResize |
      ImGuiWindowFlags_NoSavedSettings |
      ImGuiWindowFlags_NoBringToFrontOnFocus;
    ImGui::Begin("daggerheart sheet", &isMinimized, root);
    if (ImGui::BeginTabBar("Tabs")) {
      SDL_SetWindowAlwaysOnTop(window, SDL_TRUE);
      // ─────────────── “Skills” Tab ───────────────
      if (ImGui::BeginTabItem("Core")) {
        needed_content = MeasureTabContent([&] {
          render_struct_tabs("CoreTabs", skill_entries, reload_skills);
        });
        ImGui::EndTabItem();
      }

      // ─────────────── “Items” Tab ───────────────
      if (ImGui::BeginTabItem("Stats")) {
        needed_content = MeasureTabContent([&] {
          render_struct_tabs("StatTabs", item_entries, reload_items);
        });
        ImGui::EndTabItem();
      }
      if (ImGui::BeginTabItem("Config")) {
        static bool windowed;
        needed_content = MeasureTabContent([&] {
          if (ImGui::Button("Windowed")) {
            SDL_SetWindowBordered(window, (SDL_bool)windowed);
            windowed = !windowed;
          }
          ImGui::SameLine();
          if (ImGui::Button("X")) {
            SDL_Event event;
            event.type = SDL_QUIT;
            SDL_PushEvent(&event);
          }
        });
        ImGui::EndTabItem();
      }

      ImGui::EndTabBar();
    }
    ImGui::End();

    if (isMinimized) {
      needed_content = ImVec2(win_width, 1);
    }

    // Outer window size we want = content + padding + tab bar height
    float tabbar_h = ImGui::GetFrameHeight() + st.ItemInnerSpacing.y;
    ImVec2 wanted_window(
      win_width, // Fixed width
      needed_content.y + st.WindowPadding.y * 2.0f + tabbar_h);

    // Only resize SDL when it actually changes
    static ImVec2 last;
    if (fabsf(wanted_window.x - last.x) > 0.5f || fabsf(wanted_window.y - last.y) > 0.5f) {
      // Adapt size
      SDL_SetWindowSize(window, (int)std::round(wanted_window.x), (int)std::round(wanted_window.y));
      last = wanted_window;
    }

    // Rendering
    ImGui::Render();
    int fb_w = 0, fb_h = 0;
    SDL_GL_GetDrawableSize(window, &fb_w, &fb_h);
    glViewport(0, 0, fb_w, fb_h);
    glClearColor(0.10f, 0.10f, 0.10f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
  }

cleanup:
  // ──────────────────────────────────────────────────────────────────────────
  // 6) Cleanup
  // ──────────────────────────────────────────────────────────────────────────
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();

  if (gl_context) {
    SDL_GL_DeleteContext(gl_context);
  }
  if (window) {
    SDL_DestroyWindow(window);
  }
  SDL_Quit();

  return 0;
}