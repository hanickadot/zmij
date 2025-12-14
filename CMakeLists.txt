cmake_minimum_required(VERSION 3.16)
project(zmij CXX)

add_library(zmij INTERFACE zmij.h)
target_compile_features(zmij INTERFACE cxx_std_23)

add_executable(example example.cc)
target_link_libraries(example zmij)

set(CMAKE_CTEST_ARGUMENTS "--output-on-failure")
enable_testing()
add_subdirectory(gtest)

add_executable(zmij-test zmij-test.cc)
target_link_libraries(zmij-test zmij gtest)
add_test(NAME zmij-test COMMAND zmij-test)

find_package(benchmark REQUIRED)

add_executable(benchmark benchmark.cc)
target_link_libraries(benchmark zmij benchmark::benchmark)
