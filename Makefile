.PHONY: clean all run

BIN_DIR = ./bin
BUILD_DIR = ./build
SRC_DIR = ./src
TEST = ./test
TESTFL = -I thirdparty -I src
FLAGS =-Wall -Werror -std=c++14

all: $(BIN_DIR)/main

test: $(BIN_DIR)/test
	./$(BIN_DIR)/test

$(BIN_DIR)/test: $(BUILD_DIR)/test.o $(BUILD_DIR)/main_test.o
	g++ $(FLAGS) $(BUILD_DIR)/test.o $(BUILD_DIR)/main_test.o -o $(BIN_DIR)/test

$(BUILD_DIR)/test.o: $(TEST)/test.cpp
	g++ $(FLAGS) $(TESTFL) -c $(TEST)/test.cpp -o $(BUILD_DIR)/test.o

$(BUILD_DIR)/main_test.o: $(TEST)/main.cpp
	g++ $(FLAGS) $(TESTFL) -c $(TEST)/main.cpp -o $(BUILD_DIR)/main_test.o

$(BIN_DIR)/main: $(BUILD_DIR)/main.o
	g++ $(FLAGS) $(BUILD_DIR)/main.o -o $(BIN_DIR)/main

$(BUILD_DIR)/main.o:
	g++ $(FLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

run: 
	./$(BIN_DIR)/main

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BIN_DIR)/main $(BIN_DIR)/test