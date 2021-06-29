cmake_minimum_required(VERSION 3.20)
project(zlib-read-write
  VERSION 1.2.3
  LANGUAGES CXX
)
add_executable(zlib-read.exe zlib-read.cxx)
add_executable(zlib-write.exe zlib-write.cxx)

find_package(ZLIB REQUIRED)
if (ZLIB_FOUND)
  add_compile_definitions(HAVE_ZLIB_H)
  include_directories(${ZLIB_INCLUDE_DIRS})
  target_link_libraries(zlib-read.exe ZLIB::ZLIB)
  target_link_libraries(zlib-write.exe ZLIB::ZLIB)
endif(ZLIB_FOUND)
