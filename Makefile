.PHONY: clean all run

BIN_DIR = ./bin
BUILD_DIR = ./build
SRC_DIR = ./src
FLAGS =-Wall -Werror

all: $(BIN_DIR)/main

$(BIN_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/Func.o
	g++ $(FLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/Func.o -o $(BIN_DIR)/main

$(BUILD_DIR)/main.o:
	g++ $(FLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/Func.o:
	g++ $(FLAGS) -c $(SRC_DIR)/Func.cpp -o $(BUILD_DIR)/Func.o

run: 
	./bin/main

clean:
	rm -f build/*.o
	rm -f bin/main