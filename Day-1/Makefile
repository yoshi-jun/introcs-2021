CXX = g++

# CXXFLAGS := -Wall -ansi -pedantic -O2 とほぼ同義だが
# CXXFLAGS := $(CXXFLAGS) -march=pentium
# ↑こういった自己参照が可能
CXXFLAGS = -Wall -ansi -pedantic -O2
# CPPFLAGS = -DLINUX

.PHONY: all clean

all: hello.exe main.exe staticmain.exe sharedmain.exe debug.exe none-debug.exe make-main.exe program-0.1.0.exe program-0.2.0.exe

hello.exe: hello.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^

main.exe: add.o echo.o main.o
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -I. -o $@ $^

main.o: main.cpp prototypesdef.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -I. -o $@ -c $<

add.o: add.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -I. -o $@ -c $<

echo.o: echo.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -I. -o $@ -c $<

libstaticlib.a: add.o echo.o
	$(AR) rv $@ $^

staticmain.exe: main.o libstaticlib.a
	g++ -I. -o $@ $< -L. -lstaticlib

pic-add.o: add.cpp
	$(CXX) $(CXXFLAGS) -fPIC $(CPPFLAGS) -I. -o $@ -c $<

pic-echo.o: echo.cpp
	$(CXX) $(CXXFLAGS) -fPIC $(CPPFLAGS) -I. -o $@ -c $<

pic-main.o: main.cpp prototypesdef.h
	$(CXX) $(CXXFLAGS) -fPIC $(CPPFLAGS) -I. -o $@ -c $<

libsharedlib.so: pic-add.o pic-echo.o
	$(CXX) $(CXXFLAGS) -shared -fPIC $(CPPFLAGS) -o $@ $^

sharedmain.exe: pic-main.o libsharedlib.so
	$(CXX) -I. -o $@ $< -L. -lsharedlib

debug.exe: debug.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -DDEBUG -o $@ $^

none-debug.exe: debug.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^

# make-main.exe は
# make-main.o make-func1.o make-func2.o
# に依存している
# どれかひとつでも修正されたら make-main.exe
# を作り直す
# 作る場合は （タブ以降の）$(CXX)...を実行せよ
make-main.exe: make-main.o make-func1.o make-func2.o
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -I. -o $@ $^

# make-main.o は make-main.cpp と
# make-inc1.h に依存している
make-main.o: make-main.cpp make-inc1.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -I. -o $@ -c make-main.cpp

# make-func1.o は
# make-func1.cpp make-inc1.h make-inc2.h
# に依存している
make-func1.o: make-func1.cpp make-inc1.h make-inc2.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -I. -o $@ -c make-func1.cpp

# make-func2.o は
# make-func2.cpp make-inc2.h make-inc3.h
# に依存している
make-func2.o: make-func2.cpp make-inc2.h make-inc3.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -I. -o $@ -c make-func2.cpp

program-0.1.0.exe: program-0.1.0.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^

program-0.2.0.exe: program-0.2.0.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *~ *.o a.out core hello.exe main.exe staticmain.exe sharedmain.exe libstaticlib.a libsharedlib.so debug.exe none-debug.exe make-main.exe program-0.1.0.exe program-0.2.0.exe
