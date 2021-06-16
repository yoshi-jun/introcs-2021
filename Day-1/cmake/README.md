# Usage

```shell
% ls
CMakeLists.txt  zlib-read.cpp  zlib-write.cpp

# do not mess the working directory up
% mkdir build
% cd build

# target: the directory where CMakeLists.txt is
% cmake ..
-- The CXX compiler...
...snip
-- Build files have been written to:...

% ls
CMakeCache.txt  CMakeFiles/  Makefile  cmake_install.cmake

% make
```
