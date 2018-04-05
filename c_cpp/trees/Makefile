CXX := g++
CFLAG := -std=c++11
EXE := Main
SRC_FILE := $(wildcard *.cpp)
OBJ_FILE := tree.o binary_search_tree.o main.o

.PHONY: clean

all: $(OBJ_FILE)
	$(CXX) $(CFLAG) -o $(EXE) $(OBJ_FILE)

%.o: %.cpp
	$(CXX) $(CFLAG) -c $<

clean:
	rm -rf *.o $(EXE)
