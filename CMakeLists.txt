cmake_minimum_required(VERSION 3.10.0)
project(github-activity VERSION 0.1.0 LANGUAGES C CXX)

find_package(CURL REQUIRED)

add_executable(github-activity src/main.cpp)
target_link_libraries(github-activity PRIVATE CURL::libcurl)

include(CTest)
enable_testing()

