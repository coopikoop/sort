UNAME_S = $(shell uname -s)

CC = g++

CCFLAGS  = -std=c++20 -O2 -g -Wall

SRC  = $(shell find src -name "*.cpp")
OBJ  = $(SRC:.cpp=.o)
BIN = bin

all: run

run: build
	$(BIN)/sort

build: $(OBJ)
	mkdir -p $(BIN)
	$(CC) -o $(BIN)/sort $(filter %.o,$^)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CCFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)
