# CXX = clang++
# CXXFLAGS := -Wall -ansi -pedantic -O2 とほぼ同義だが
# CXXFLAGS := $(CXXFLAGS) -march=pentium
# ↑こういった自己参照が可能
CXXFLAGS = -std=c++11 -fPIC -Wall -pedantic -O2 
# CPPFLAGS += -DDEBUG

.PHONY: all clean

all: bytelen_bitlen_types.exe max_min_types.exe enum_typedef.exe \
	vector_main.exe

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

bytelen_bitlen_types.o: bytelen_bitlen_types.cpp
enum_typedef.o: enum_typedef.cpp
max_min_types.o: max_min_types.cpp
vector_main.o: vector_main.cpp
ThreeVector.o: ThreeVector.cpp ThreeVector.h

%.exe:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

bytelen_bitlen_types.exe: bytelen_bitlen_types.o
enum_typedef.exe: enum_typedef.o
max_min_types.exe: max_min_types.o
vector_main.exe: vector_main.o ThreeVector.o

clean:
	rm -f *~ *.o a.out core *.exe file.out
