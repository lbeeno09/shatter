# Add source files for library
add_library(cpp_lib_template STATIC
	myLib.cpp
)

# specify include directories
target_include_directories(cpp_lib_template PUBLIC
	${CMAKE_SOURCE_DIR}/include
)

# shared library
# add_library(cpp_lib_template SHARED myLib.cpp)