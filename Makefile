.PHONY: clean all run

BIN_DIR = ./bin
BUILD_DIR = ./build
SRC_DIR = ./src
FLAGS =-Wall -Werror -std=c++14

all: $(BIN_DIR)/main

$(BIN_DIR)/main: $(BUILD_DIR)/main.o
	g++ $(FLAGS) $(BUILD_DIR)/main.o -o $(BIN_DIR)/main

$(BUILD_DIR)/main.o:
	g++ $(FLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

run: 
	./bin/main

clean:
	rm -f build/*.o
	rm -f bin/main