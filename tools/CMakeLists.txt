cmake_minimum_required(VERSION 3.16)
project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set up dependencies
include(FetchContent)

# SDL2
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.28.2
)
FetchContent_MakeAvailable(SDL2)

# GLEW
find_package(GLEW REQUIRED)

# ImGui
include(FetchContent)
FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG v1.91.9b-docking
)
FetchContent_MakeAvailable(imgui)

# ImPlot
FetchContent_Declare(
  implot
  GIT_REPOSITORY https://github.com/epezent/implot.git
  GIT_TAG v0.16
)
FetchContent_MakeAvailable(implot)

include(FetchContent)
FetchContent_Declare(
  magic_enum
  GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
  GIT_TAG v0.9.5
)
FetchContent_MakeAvailable(magic_enum)

# ImGui core source files
add_library(imgui STATIC
  ${imgui_SOURCE_DIR}/imgui.cpp
  ${imgui_SOURCE_DIR}/imgui_demo.cpp
  ${imgui_SOURCE_DIR}/imgui_draw.cpp
  ${imgui_SOURCE_DIR}/imgui_tables.cpp
  ${imgui_SOURCE_DIR}/imgui_widgets.cpp
)

# ImPlot source files
add_library(implot STATIC
  ${implot_SOURCE_DIR}/implot.cpp
  ${implot_SOURCE_DIR}/implot_items.cpp
)

target_link_libraries(implot PUBLIC imgui)

target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})

# ImGui-SDL2-OpenGL3 backend integration (manually adding source files)
add_library(imgui_impl STATIC
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui_impl PUBLIC
  ${imgui_SOURCE_DIR}
  ${imgui_SOURCE_DIR}/backends
  ${SDL2_SOURCE_DIR}/include
)

target_link_libraries(imgui_impl PUBLIC imgui SDL2::SDL2)

# Main executable
add_executable(app app.cpp)

target_include_directories(app PUBLIC
  ${imgui_SOURCE_DIR}
  ${imgui_SOURCE_DIR}/backends
  ${implot_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(app PRIVATE
  imgui_impl
  imgui
  implot
  SDL2::SDL2
  SDL2::SDL2main
  OpenGL::GL
  GLEW::GLEW
  magic_enum::magic_enum)

# Find OpenGL
find_package(OpenGL REQUIRED)