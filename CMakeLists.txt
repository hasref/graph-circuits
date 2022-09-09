cmake_minimum_required(VERSION 3.24)
project(circuits VERSION 0.1 LANGUAGES CXX)

find_package(Catch2 REQUIRED)

add_library(circuits SHARED src/tarjan.cpp)
target_include_directories(circuits PRIVATE include)
target_compile_features(circuits PRIVATE cxx_std_20)
target_compile_options(circuits PRIVATE -g -fsanitize=address)
target_link_options(circuits PRIVATE -fsanitize=address)

add_executable(tests test/tests.cpp)
target_include_directories(tests PRIVATE src include)
target_compile_features(tests PRIVATE cxx_std_20)
target_compile_options(tests PRIVATE -g -fsanitize=address)
target_link_libraries(tests PRIVATE circuits)
target_link_options(tests PRIVATE -fsanitize=address)

include(CTest)
include(Catch)
catch_discover_tests(tests)

# copy compile commands to dir of this CMakeLists
add_custom_target(
  copy-compile-commands ALL
  ${CMAKE_COMMAND} -E copy_if_different
  ${CMAKE_BINARY_DIR}/compile_commands.json
  ${CMAKE_CURRENT_LIST_DIR}
  )
