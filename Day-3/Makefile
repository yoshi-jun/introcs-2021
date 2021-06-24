# CXX = clang++
# CXXFLAGS := -Wall -ansi -pedantic -O2 とほぼ同義だが
# CXXFLAGS := $(CXXFLAGS) -march=pentium
# ↑こういった自己参照が可能
CXXFLAGS = -fPIC -Wall -pedantic -O2 
# CPPFLAGS += -DDEBUG

.PHONY: all clean

all: zoo_main.exe \
	calc_tmpl_main.exe \
	particle_table.exe \
	dict_particle_mass-c++98.exe \
	dict_particle_mass-c++11.exe \
	dict_particle_mass-c++17.exe \
	file_main-c++11.exe \
	file_main-c++17.exe \
	variable_arguments.exe

%.o: %.cpp
	$(CXX) -std=c++11 $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

zoo_main.o: zoo_main.cpp
Zoo.o: Zoo.cpp Zoo.h Animal.h
Animal.o: Animal.cpp Animal.h
Tiger.o: Tiger.cpp Tiger.h Animal.h
Donkey.o: Donkey.cpp Donkey.h Animal.h
Giraffe.o: Giraffe.cpp Giraffe.h Animal.h
calc_tmpl_main.o: calc_tmpl_main.cpp ThreeVector.h CalculatorT.h CalculatorT.tpp
particle_table.o: particle_table.cpp Particle.h unit.h
ThreeVector.o: ThreeVector.cpp ThreeVector.h
Particle.o: Particle.cpp Particle.h ThreeVector.h
file_main.o: file_main.cpp

File-c++11.o: File.cpp File.h
	$(CXX) -std=c++11 -DCXXSTD=11 $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
File-c++17.o: File.cpp File.h
	$(CXX) -std=c++17 -DCXXSTD=17 $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

%.exe:
	$(CXX) -std=c++11 $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

zoo_main.exe: zoo_main.o Zoo.o Animal.o Tiger.o Donkey.o Giraffe.o
calc_tmpl_main.exe: calc_tmpl_main.o ThreeVector.o
particle_table.exe: particle_table.o Particle.o ThreeVector.o
variable_arguments.exe: variable_arguments.cpp

dict_particle_mass-c++98.exe: dict_particle_mass.cpp unit.h
	$(CXX) -std=c++98 -DCXXSTD=98 -ansi $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $<
dict_particle_mass-c++11.exe: dict_particle_mass.cpp unit.h
	$(CXX) -std=c++11 -DCXXSTD=11 $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $<
# For GCC, required gcc-c++ 7.1 or later
dict_particle_mass-c++17.exe: dict_particle_mass.cpp unit.h
	$(CXX) -std=c++17 -DCXXSTD=17 $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $<
file_main-c++11.exe: file_main.o File-c++11.o
	$(CXX) -std=c++11 -DCXXSTD=11 $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^
# For GCC, required gcc-c++ 7.1 or later
file_main-c++17.exe: file_main.o File-c++17.o
	$(CXX) -std=c++17 -DCXXSTD=17 $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f *~ *.o a.out core *.exe
