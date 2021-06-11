cmake_minimum_required(VERSION 3.20)
project(zlib-read-write
  VERSION 1.2.3
  LANGUAGES CXX
)
add_executable(zlib-read.exe zlib-read.cpp)
target_link_libraries(zlib-read.exe z)
add_executable(zlib-write.exe zlib-write.cpp)
target_link_libraries(zlib-write.exe z)
