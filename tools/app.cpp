// main.cpp

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <cstdio>
#include <fstream>
#include <magic_enum.hpp>
#include <nlohmann/json.hpp>
#include <tuple>
#include <string_view>
#include <SDL.h>
#include <GL/glew.h>
#include <typeinfo>
#ifdef __has_include
#if __has_include(<boost/type_index.hpp>)
#include <boost/type_index.hpp>
#define HAVE_BOOST_TYPEINDEX 1
#endif
#endif
#if !defined(HAVE_BOOST_TYPEINDEX) && (defined(__GNUC__) || defined(__clang__))
#include <cxxabi.h>
#include <cstdlib>
#endif
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// ─────────── ImGui & Backend includes (SDL2 + OpenGL3 + GLEW) ───────────
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

// ─────────── JSON_IO (Boost.Hana + nlohmann::json) ───────────
#include "json_io.hpp"

constexpr int win_width = 250;
std::vector<ImTextureID> icon_textures;
std::vector<std::string> icon_paths;

// GUI by template metaprogramming ──────────────────────────────────
namespace hana = boost::hana;
namespace fs = std::filesystem;

enum class Subclass { warden_of_the_elements,
                      warden_of_renewal,
                      stalwart,
                      vengeance,
                      beastbound,
                      wayfinder,
                      nightwalker,
                      syndicate,
                      divine_wielder,
                      winged_sentinel,
                      primal_origin,
                      elemental_origin,
                      call_of_the_brave,
                      call_of_the_slayer,
                      school_of_knowledge,
                      school_of_war };

enum class damage_type { Magical,
                         Physical };

enum class Trait { Agility,
                   Strength,
                   Finesse,
                   Instinct,
                   Presence,
                   Knowledge };
enum class Range {
  Melee,     // touching distance
  VeryClose, // 5-10 feet
  Close,     // 10-30 feet
  Far,       // 30-100 feet
  VeryFar    // 100-300 feet
};

JSON_IO_STRUCT(Weapon,
               (std::string, Name),
               (Trait, trait),
               (Range, range),
               (std::string, damage),
               (damage_type, type),
               (std::string, feature));

JSON_IO_STRUCT(Armor,
               (std::string, name),
               (std::string, base_threshold),
               (std::string, base_score),
               (std::string, feature));

JSON_IO_STRUCT(Item,
               (std::string, name),
               (int, Amount));

JSON_IO_STRUCT(Gold,
               (int, handful),
               (int, bags),
               (int, chest));

JSON_IO_STRUCT(Bag,
               (std::vector<Weapon>, weapons),
               (std::vector<std::string>, items));

JSON_IO_STRUCT(Items,
               (Weapon, Primary),
               (Weapon, Secondary),
               (Armor, armor),
               (Bag, bag),
               (Gold, gold));

JSON_IO_STRUCT(Core_values,
               (int, value),
               (int, max));

JSON_IO_STRUCT(Damage,
               (int, minor),
               (int, major));

JSON_IO_STRUCT(Stats,
               (std::string, Name),
               (Subclass, subclass),
               (int, Level),
               (Core_values, Armor),
               (Core_values, Hp),
               (Core_values, Stress),
               (Core_values, Hope),
               (int, Evasion),
               (int, Agility),
               (int, Strength),
               (int, Finesse),
               (int, Instinct),
               (int, Presence),
               (int, Knowledge),
               (Damage, damage));

template <typename T>
bool render_gui(T& obj) {
  bool modified = false;

  static std::unordered_map<std::string, std::array<char, 128>> string_buffers;

  hana::for_each(hana::accessors<T>(), [&](auto const& pair) {
    auto hana_name = hana::first(pair);
    auto name_str = hana::to<const char*>(hana_name);
    auto& field = hana::second(pair)(obj);

    using FieldT = std::decay_t<decltype(field)>;

    ImGui::SetNextItemWidth(100);
    if constexpr (std::is_same_v<FieldT, std::string>) {
      auto& buf = string_buffers[name_str];
      std::strncpy(buf.data(), field.c_str(), buf.size());
      if (ImGui::InputText(name_str, buf.data(), buf.size())) {
        field = buf.data();
        modified = true;
      }
    } else if constexpr (std::is_same_v<FieldT, Core_values>) {
      ImGui::SetNextItemWidth(80);
      std::string label(name_str);
      if (label.size() < 8) {
        label.append(8 - label.size(), ' ');
      }
      modified |= ImGui::InputInt(label.c_str(), &field.value);
      ImGui::SameLine();
      ImGui::SetNextItemWidth(40);
      std::string max_label = "max##" + std::string(name_str);
      modified |= ImGui::InputInt(max_label.c_str(), &field.max, 0, 0);
    } else if constexpr (std::is_same_v<FieldT, Damage>) {
      ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Minor");
      ImGui::SameLine();
      ImGui::SetNextItemWidth(25);
      modified |= ImGui::InputInt(("##minor" + std::string(name_str)).c_str(), &field.minor, 0, 0);
      ImGui::SameLine();
      ImGui::TextColored(ImVec4(0.9f, 0.2f, 0.2f, 1.0f), "Major");
      ImGui::SameLine();
      ImGui::SetNextItemWidth(25);
      modified |= ImGui::InputInt(("##major" + std::string(name_str)).c_str(), &field.major, 0, 0);
      ImGui::SameLine();
      ImGui::TextColored(ImVec4(0.6f, 0.2f, 0.8f, 1.0f), "Severe"); // purple
    } else if constexpr (std::is_same_v<FieldT, Gold>) {
      ImGui::SetNextItemWidth(20);
      modified |= ImGui::InputInt("handful", &field.handful, 0, 0);
      ImGui::SameLine();
      ImGui::SetNextItemWidth(20);
      modified |= ImGui::InputInt("bags", &field.bags, 0, 0);
      ImGui::SameLine();
      ImGui::SetNextItemWidth(20);
      modified |= ImGui::InputInt("chest", &field.chest, 0, 0);
    } else if constexpr (std::is_same_v<FieldT, int>) {
      ImGui::SetNextItemWidth(25);
      modified |= ImGui::InputInt(name_str, &field, 0, 0);
    } else if constexpr (std::is_same_v<FieldT, float>) {
      modified |= ImGui::InputFloat(name_str, &field);
    } else if constexpr (std::is_same_v<FieldT, bool>) {
      modified |= ImGui::Checkbox(name_str, &field);
    } else if constexpr (hana::Struct<FieldT>::value && std::is_class_v<FieldT>) {
      if (ImGui::TreeNodeEx(name_str, ImGuiTreeNodeFlags_DefaultOpen)) {
        modified |= render_gui(field);
        ImGui::TreePop();
      }
    } else if constexpr (std::is_enum_v<FieldT>) {
      int index = static_cast<int>(field);
      std::vector<std::string> names;
      for (auto name : magic_enum::enum_names<FieldT>()) {
        names.push_back(std::string(name));
      }
      std::vector<const char*> c_names;
      for (auto& str : names) {
        c_names.push_back(str.c_str());
      }

      if (ImGui::Combo(name_str, &index, c_names.data(), static_cast<int>(c_names.size()))) {
        field = static_cast<FieldT>(index);
        modified = true;
      }
    } else if constexpr (requires { field.begin(); field.end(); }) {
      using ElemT = typename FieldT::value_type;
      if (ImGui::TreeNode(name_str)) {
        for (size_t i = 0; i < field.size(); ++i) {
          std::string label = std::to_string(i); // std::string(name_str) + "[" + std::to_string(i) + "]";
          ImGui::SetNextItemWidth(100);
          if constexpr (hana::Struct<ElemT>::value && std::is_class_v<ElemT>) {
            if (ImGui::TreeNode(label.c_str())) {
              modified |= render_gui(field[i]);
              ImGui::TreePop();
            }
          } else if constexpr (std::is_same_v<ElemT, int>) {
            modified |= ImGui::InputInt(label.c_str(), &field[i]);
          } else if constexpr (std::is_same_v<ElemT, float>) {
            modified |= ImGui::InputFloat(label.c_str(), &field[i]);
          } else if constexpr (std::is_same_v<ElemT, bool>) {
            modified |= ImGui::Checkbox(label.c_str(), &field[i]);
          } else if constexpr (std::is_same_v<ElemT, std::string>) {
            ImGui::SetNextItemWidth(140);
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
            break;
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

static void set_imgui_color_style(void) {
  ImGuiStyle& style = ImGui::GetStyle();
  ImVec4 black = ImVec4(0.05f, 0.05f, 0.05f, 1.0f);    // almost black
  ImVec4 yellow = ImVec4(1.0f, 0.9f, 0.0f, 1.0f);      // bright yellow
  ImVec4 dark_yellow = ImVec4(0.6f, 0.6f, 0.0f, 1.0f); // very dark, brownish yellow
  ImVec4 white = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);       // White
  ImVec4 gray = ImVec4(0.20f, 0.20f, 0.20f, 1.0f);
  ImVec4 yellowHover = ImVec4(0.4f, 0.4f, 0.0f, 1.0f); // muted olive yellow

  style.Colors[ImGuiCol_Text] = white;
  style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.5f, 0.5f, 0.2f, 1.0f);
  style.Colors[ImGuiCol_WindowBg] = black;
  style.Colors[ImGuiCol_ChildBg] = black;
  style.Colors[ImGuiCol_PopupBg] = black;
  style.Colors[ImGuiCol_Border] = black;
  style.Colors[ImGuiCol_BorderShadow] = black;

  style.Colors[ImGuiCol_FrameBg] = gray; // ImVec4(0.15f, 0.15f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_FrameBgHovered] = yellowHover;
  style.Colors[ImGuiCol_FrameBgActive] = dark_yellow;

  style.Colors[ImGuiCol_TitleBg] = black;
  style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.2f, 0.2f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_TitleBgCollapsed] = black;

  style.Colors[ImGuiCol_MenuBarBg] = black;

  style.Colors[ImGuiCol_ScrollbarBg] = black;
  style.Colors[ImGuiCol_ScrollbarGrab] = yellow;
  style.Colors[ImGuiCol_ScrollbarGrabHovered] = yellowHover;
  style.Colors[ImGuiCol_ScrollbarGrabActive] = dark_yellow;

  style.Colors[ImGuiCol_CheckMark] = yellow;
  style.Colors[ImGuiCol_SliderGrab] = yellow;
  style.Colors[ImGuiCol_SliderGrabActive] = yellowHover;

  style.Colors[ImGuiCol_Button] = gray; // ImVec4(0.2f, 0.2f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_ButtonHovered] = yellowHover;
  style.Colors[ImGuiCol_ButtonActive] = dark_yellow;

  style.Colors[ImGuiCol_Header] = ImVec4(0.2f, 0.2f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_HeaderHovered] = yellowHover;
  style.Colors[ImGuiCol_HeaderActive] = dark_yellow;

  style.Colors[ImGuiCol_Tab] = ImVec4(0.15f, 0.15f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_TabHovered] = yellowHover;
  style.Colors[ImGuiCol_TabActive] = dark_yellow;
  style.Colors[ImGuiCol_TabUnfocused] = black;
  style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.25f, 0.25f, 0.0f, 1.0f);

  style.Colors[ImGuiCol_Separator] = yellow;
  style.Colors[ImGuiCol_SeparatorHovered] = yellowHover;
  style.Colors[ImGuiCol_SeparatorActive] = dark_yellow;

  style.Colors[ImGuiCol_ResizeGrip] = yellow;
  style.Colors[ImGuiCol_ResizeGripHovered] = yellowHover;
  style.Colors[ImGuiCol_ResizeGripActive] = dark_yellow;

  style.Colors[ImGuiCol_PlotLines] = yellow;
  style.Colors[ImGuiCol_PlotLinesHovered] = yellowHover;
  style.Colors[ImGuiCol_PlotHistogram] = yellow;
  style.Colors[ImGuiCol_PlotHistogramHovered] = yellowHover;

  style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.0f, 1.0f, 0.2f, 0.35f);
  style.Colors[ImGuiCol_DragDropTarget] = yellow;
  style.Colors[ImGuiCol_NavHighlight] = yellow;
  style.Colors[ImGuiCol_NavWindowingHighlight] = yellow;
  style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0, 0, 0, 0.5f);
  style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0, 0, 0, 0.5f);
}

static void UseDefaultDarkWithYellowAccents() {
  ImGui::StyleColorsDark(); // reset to default dark

  ImGuiStyle& style = ImGui::GetStyle();

  // Hue ranges (0..1): blue≈0.55..0.72, yellow target≈0.13
  const float blue_min = 0.50f;
  const float blue_max = 0.75f;
  const float yellow_h = 0.13f; // golden/yellow hue

  for (int i = 0; i < ImGuiCol_COUNT; ++i) {
    ImVec4& c = style.Colors[i];

    // Convert RGB->HSV
    float h, s, v;
    ImGui::ColorConvertRGBtoHSV(c.x, c.y, c.z, h, s, v);

    // Only retint "blue-ish" accent colors; keep neutral grays/blacks as-is.
    // Also skip very desaturated/very dark colors (they're likely neutrals).
    if (s > 0.10f && v > 0.10f && h >= blue_min && h <= blue_max) {
      h = yellow_h; // swap just the hue, preserve saturation/value
      ImGui::ColorConvertHSVtoRGB(h, s, v, c.x, c.y, c.z);
      // keep c.w (alpha) unchanged
    }
  }

  // Optional: a few explicit touches that commonly use the accent color
  // (these ensure good look even if upstream style changes)
  style.Colors[ImGuiCol_NavHighlight].w = 0.80f;   // keep nav highlight visible
  style.Colors[ImGuiCol_TextSelectedBg].w = 0.35f; // same alpha as default
                                                   // If you prefer a yellow checkmark instead of white:
                                                   // style.Colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.90f, 0.00f, 1.00f);
  // style.Colors[ImGuiCol_Text] = ImVec4(0.6f, 0.2f, 0.8f, 1.0f); // purple
}

// Strip namespaces from type name
static std::string short_type_name(std::string s) {
  // strip leading qualifiers like "struct ", "class ", "enum "
  for (const char* pre : {"struct ", "class ", "enum "}) {
    if (s.rfind(pre, 0) == 0) {
      s.erase(0, std::strlen(pre));
    }
  }
  // strip namespaces
  if (auto pos = s.rfind("::"); pos != std::string::npos) {
    s.erase(0, pos + 2);
  }
  return s;
}

template <class T>
static std::string type_display_name() {
#ifdef HAVE_BOOST_TYPEINDEX
  std::string pretty = boost::typeindex::type_id<T>().pretty_name();
  return short_type_name(std::move(pretty));
#elif defined(__GNUC__) || defined(__clang__)
  int status = 0;
  std::string mangled = typeid(T).name();
  char* dem = abi::__cxa_demangle(mangled.c_str(), nullptr, nullptr, &status);
  std::string pretty = (status == 0 && dem) ? dem : mangled;
  std::free(dem);
  return short_type_name(std::move(pretty));
#else
  std::string pretty = typeid(T).name(); // MSVC already human-ish
  return short_type_name(std::move(pretty));
#endif
}

// One “tab bound to a single file” for type T
template <class T>
struct SingleFileTab {
  std::string name; // "Core", "Stats", ...
  std::string path; // DATA_PATH/<name>.json
  T data{};         // live data

  explicit SingleFileTab(const std::string& dir) {
    name = type_display_name<T>();
    path = dir + "/" + name + ".json";
    load_single_json_or_create(path, data);
  }

  // Render one tab and persist on edit; returns height measured
  ImVec2 render_and_measure() {
    ImVec2 ret;
    if (ImGui::BeginTabItem((name).c_str())) {
      ret = MeasureTabContent([&] {
        if (render_gui(data)) {
          JsonIO::overwrite(path, data);
        }
      });
      ImGui::EndTabItem();
    }
    return ret;
  }
};

// Render a tab bar with one tab per type in Ts...
template <class... Ts>
ImVec2 render_auto_tabs(const std::string& data_dir) {
  static std::tuple<SingleFileTab<Ts>...> tabs{SingleFileTab<Ts>(data_dir)...};
  ImVec2 max_size{};
  std::apply([&](auto&... tab) {
    (([&] {
       ImVec2 sz = tab.render_and_measure();
       max_size.x = std::max(max_size.x, sz.x);
       max_size.y = std::max(max_size.y, sz.y);
     }()),
     ...);
  },
             tabs);
  return max_size;
}

template <typename T>
struct Entry {
  std::string file_path;
  T data;
};

// (kept in case you want to reuse for multi-file types)
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

ImTextureID LoadTextureFromFile(const char* filename, int* out_width = nullptr, int* out_height = nullptr) {
  int width, height, channels;
  unsigned char* data = stbi_load(filename, &width, &height, &channels, 4);
  if (!data) {
    std::cerr << "Failed to load image: " << filename << std::endl;
    return 0; // <--- not nullptr
  }

  GLuint tex_id;
  glGenTextures(1, &tex_id);
  glBindTexture(GL_TEXTURE_2D, tex_id);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
               0, GL_RGBA, GL_UNSIGNED_BYTE, data);

  stbi_image_free(data);

  if (out_width) {
    *out_width = width;
  }
  if (out_height) {
    *out_height = height;
  }

  return tex_id; // GLuint is implicitly ImTextureID here
}

void LoadAllIcons(const std::string& dir) {
  namespace fs = std::filesystem;
  icon_textures.clear();

  // check directory first
  if (!fs::exists(dir) || !fs::is_directory(dir)) {
    printf("Icon directory not found: %s\n", dir.c_str());
    return; // continue gracefully
  }

  for (const auto& entry : fs::directory_iterator(dir)) {
    if (entry.is_regular_file()) {
      auto path = entry.path();
      if (path.extension() == ".png") {
        ImTextureID tex = LoadTextureFromFile(path.string().c_str());
        if (tex != 0) {
          icon_textures.push_back(tex);
          printf("Loaded %s as texture %u\n",
                 path.filename().string().c_str(),
                 (unsigned)tex);
          icon_paths.push_back(path.string());
        }
      }
    }
  }

  if (icon_textures.empty()) {
    printf("No .png icons found in directory: %s\n", dir.c_str());
  }
}

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

// ───────────────────────────────────────────────────────────────
// NEW: single-file load helper (creates default if missing)
// ───────────────────────────────────────────────────────────────
template <class T>
static void load_single_json_or_create(const std::string& path, T& out) {
  using nlohmann::json;

  try {
    if (fs::exists(path)) {
      std::ifstream f(path);
      if (f) {
        json j;
        f >> j;
        out = j.get<T>(); // uses JSON_IO_STRUCT from_json glue
        return;
      }
    }
    // If file missing or unreadable, create it with current default `out`
    fs::create_directories(fs::path(path).parent_path());
    JsonIO::overwrite(path, out);
  } catch (...) {
    // On any error, keep defaults in `out` and try to write a fresh file
    try {
      fs::create_directories(fs::path(path).parent_path());
      JsonIO::overwrite(path, out);
    } catch (...) {
      // Swallow—UI can still edit and later save
    }
  }
}

int main(int argc, char** argv) {
  std::string data_dir;
  if (argc > 1) {
    data_dir = argv[1];
  } else {
    data_dir = fs::current_path().string(); // get full path
  }

  std::cout << "Using data dir: " << data_dir << std::endl;
  // ──────────────────────────────────────────────────────────────────────────
  // 1) SDL + GL init (unchanged)
  // ──────────────────────────────────────────────────────────────────────────
  SDL_SetHint(SDL_HINT_VIDEODRIVER, "x11");
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
    sdl_die("Error: SDL_Init failed!");
  }
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  int win_w = win_width;
  int win_h = 180;
  SDL_Rect display_bounds;
  if (SDL_GetDisplayUsableBounds(0, &display_bounds) != 0) {
    SDL_Log("SDL_GetDisplayUsableBounds failed: %s", SDL_GetError());
    return 1;
  }
  int x = display_bounds.x + (display_bounds.w - win_w);
  int y = display_bounds.y;
  SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL |
                                                   SDL_WINDOW_ALWAYS_ON_TOP |
                                                   SDL_WINDOW_BORDERLESS |
                                                   SDL_WINDOW_ALLOW_HIGHDPI);
  SDL_Window* window = SDL_CreateWindow("app", x, y, win_w, win_h, window_flags);
  SDL_ShowWindow(window);
  SDL_SetWindowAlwaysOnTop(window, SDL_TRUE);
  SDL_RaiseWindow(window);
  if (!window) {
    sdl_die("Error: SDL_CreateWindow failed!");
  }

  SDL_GLContext gl_context = SDL_GL_CreateContext(window);
  if (!gl_context) {
    sdl_die("Error: SDL_GL_CreateContext failed!");
  }
  if (SDL_GL_SetSwapInterval(1) < 0) {
    std::cerr << "Warning: Unable to set VSync! SDL_Error: " << SDL_GetError() << std::endl;
  }

  glewExperimental = GL_TRUE;
  GLenum glew_err = glewInit();
  if (glew_err != GLEW_OK) {
    std::cerr << "Error: Failed to initialize GLEW! "
              << glewGetErrorString(glew_err) << std::endl;
    return 1;
  }
  glGetError();

  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  ImGui::StyleColorsDark();
  ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
  ImGui_ImplOpenGL3_Init("#version 330");

  // ──────────────────────────────────────────────────────────────────────────
  // 4) Single-file Core & Stats under DATA_PATH
  // ──────────────────────────────────────────────────────────────────────────
  //LoadAllIcons((data_dir + "/cards").c_str());
  // set_imgui_color_style();
  // UseDefaultDarkWithYellowAccents();

  // ──────────────────────────────────────────────────────────────────────────
  // 5) Main loop (tabs now edit a single object/file each)
  // ──────────────────────────────────────────────────────────────────────────
  bool isMinimized = false;
  while (true) {
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

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    ImGuiStyle& st = ImGui::GetStyle();
    ImVec2 needed_content(win_width, 20);
    ImGuiViewport* vp = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(vp->Pos);
    ImGui::SetNextWindowSize(vp->Size);
    ImGuiWindowFlags root =
      ImGuiWindowFlags_NoDecoration |
      ImGuiWindowFlags_NoMove |
      ImGuiWindowFlags_NoResize |
      ImGuiWindowFlags_NoSavedSettings |
      ImGuiWindowFlags_NoBringToFrontOnFocus;
    ImGui::Begin("daggerheart sheet", &isMinimized, root);
    if (ImGui::BeginTabBar("Tabs")) {
      SDL_SetWindowAlwaysOnTop(window, SDL_TRUE);

      // ⬇️ Auto-generate one tab per listed struct type:
      needed_content = render_auto_tabs<Stats, Items>(data_dir);

/*      if (icon_textures.size() > 0) {
        if (ImGui::BeginTabItem("Cards")) { //---- Cards TAB ----------//
          static bool windowed;
          static int selected_index;
          needed_content = MeasureTabContent([&] {
            // 1) Left button (fixed)
            if (ImGui::Button("<")) {
              selected_index = (selected_index > 0) ? selected_index - 1 : icon_textures.size() - 1;
            }
            ImGui::SameLine();

            // 2) Middle fixed-width slot (child) to keep the ">" from moving
            //    Pick a width that works for your longest expected label.
            //    (Optionally compute it once from your filenames — shown below.)
            float label_slot_w = 140.0f;            // <-- tune or compute
            float slot_h = ImGui::GetFrameHeight(); // match button height
            if (ImGui::BeginChild("label_slot", ImVec2(label_slot_w, slot_h),
                                  false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse)) {
              // Extract filename without path or extension
              std::string label = icon_paths[selected_index];
              label = label.substr(label.find_last_of("/\\") + 1);
              label = label.substr(0, label.find_last_of('.'));

              // Center text inside the fixed slot
              ImVec2 text_sz = ImGui::CalcTextSize(label.c_str());
              float x = (label_slot_w - text_sz.x) * 0.5f;
              float y = (slot_h - text_sz.y) * 0.5f;
              // Guard: avoid negative cursor pos if label wider than slot
              x = x < 0.0f ? 0.0f : x;
              y = y < 0.0f ? 0.0f : y;

              ImGui::SetCursorPos(ImVec2(x, y));
              ImGui::TextColored(ImVec4(1, 1, 0, 1), "%s", label.c_str());
            }
            ImGui::EndChild();

            ImGui::SameLine();

            // 3) Right button stays at a fixed X
            if (ImGui::Button(">")) {
              selected_index = (selected_index + 1) % icon_textures.size();
            }

            ImGui::Image(icon_textures[selected_index], ImVec2(300, 420));
          });
          ImGui::EndTabItem();
        }
      }*/

      if (ImGui::BeginTabItem("...")) { //---- More Options TAB ----------//
        static bool windowed;
        needed_content = MeasureTabContent([&] {
          if (ImGui::Button("Windowed")) {
            SDL_SetWindowBordered(window, (SDL_bool)windowed);
            windowed = !windowed;
          }
          ImGui::SameLine();
          if (ImGui::Button("Close")) {
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

    float tabbar_h = ImGui::GetFrameHeight() + st.ItemInnerSpacing.y;
    ImVec2 wanted_window(
      win_width,
      needed_content.y + st.WindowPadding.y * 2.0f + tabbar_h);

    static ImVec2 last;
    if (fabsf(wanted_window.x - last.x) > 0.5f || fabsf(wanted_window.y - last.y) > 0.5f) {
      SDL_SetWindowSize(window, (int)std::round(wanted_window.x), (int)std::round(wanted_window.y));
      last = wanted_window;
    }

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
