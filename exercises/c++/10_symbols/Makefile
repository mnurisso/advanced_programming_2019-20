EXE = hello
GDIR=01_library

LDFLAGS = -lhello -L $(GDIR)

CXX = c++
CXXFLAGS = -I $(GDIR)/include -std=c++11

all: $(EXE)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(EXE): main.o
	$(CXX) $^ -o $(EXE) $(LDFLAGS)

clean:
	rm -rf *.o $(EXE) *~ a.out*

.PHONY: all

