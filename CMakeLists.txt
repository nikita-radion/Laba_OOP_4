cmake_minimum_required(VERSION 3.10)
project(figures)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR}/include)

enable_testing()
add_executable(tests tests/tests.cpp)
target_link_libraries(tests GTest::gtest_main)

add_executable(figures_app src/main.cpp)

include(GoogleTest)
gtest_discover_tests(tests) 