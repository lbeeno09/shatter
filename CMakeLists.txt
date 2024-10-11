cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME cpp_gui_template)
project(${PROJECT_NAME} VERSION 1.0)

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenGL REQUIRED)

# external stuff
set(GLFW_DIR ${CMAKE_SOURCE_DIR}/deps/glfw)
set(GLFW_INCLUDE_DIR ${GLFW_DIR}/include)
set(GLFW_LIB_DIR ${GLFW_DIR}/build/src)
set(IMGUI_SOURCE_DIR ${CMAKE_SOURCE_DIR}/deps/imgui)
set(IMGUI_BACKENDS_DIR ${IMGUI_SOURCE_DIR}/backends)

# project stuff
file(GLOB_RECURSE HEADER include/*.h)
file(GLOB_RECURSE SOURCE src/*.cpp)

set(SOURCE_FILES
	${SOURCE}
	${IMGUI_SOURCE_DIR}/imgui_demo.cpp
	${IMGUI_SOURCE_DIR}/imgui_draw.cpp
	${IMGUI_SOURCE_DIR}/imgui_tables.cpp
	${IMGUI_SOURCE_DIR}/imgui_widgets.cpp
	${IMGUI_SOURCE_DIR}/imgui.cpp
	${IMGUI_BACKENDS_DIR}/imgui_impl_glfw.cpp
	${IMGUI_BACKENDS_DIR}/imgui_impl_opengl3.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
	"include"
	${GLFW_INCLUDE_DIR}
	${IMGUI_SOURCE_DIR}
	${IMGUI_BACKENDS_DIR}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
	OpenGL::GL
	$<IF:$<CONFIG:Debug>,${GLFW_LIB_DIR}/Debug/glfw3dll.lib,${GLFW_LIB_DIR}/Release/glfw3dll.lib>
)