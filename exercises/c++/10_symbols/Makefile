EXE = hello
GDIR=01_library

LDFLAGS = -lhello -L $(GDIR)

CXX = c++
CXXFLAGS = -I $(GDIR)/include -I -std=c++11

all: $(EXE)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(EXE): main.o 01_library/source/hello.o
	$(CXX) $^ -o $(EXE) $(LDFLAGS)

clean:
	rm -rf *.o $(EXE) *~ a.out*

.PHONY: all

