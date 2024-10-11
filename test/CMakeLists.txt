add_executable(testMyLib testMyLib.cpp)

# link text exe to library
target_link_libraries(testMyLib PRIVATE cpp_lib_template)

# add test
add_test(NAME LibTest COMMAND testMyLib)