cmake_minimum_required(VERSION 3.5)

project(
  practiceQt0x01
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/gui)
add_subdirectory(src/main)
