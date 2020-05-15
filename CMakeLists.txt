cmake_minimum_required(VERSION 3.11)
project(spisok)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB SOURCE_FILES "source/*.cpp")
add_executable(spisok ${SOURCE_FILES})