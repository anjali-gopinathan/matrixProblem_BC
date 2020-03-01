CC = g++
CPPFLAGS = --std=c++11 -g -Wall
BIN_DIR = bin
GTEST_LL = -I /googletest/googletest/include/gtest/ -l gtest -l gtest_main -pthread


all: $(BIN_DIR)/matrixTest

# Rule to ensure that $(BIN_DIR) directory exists or it'll create it
$(BIN_DIR)/.dirstamp:
	-@mkdir -p $(BIN_DIR)
	-@touch $(BIN_DIR)/.dirstamp

$(BIN_DIR)/matrixTest.o: Gopinathan-Anjali.h $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c Gopinathan-Anjali.h 

$(BIN_DIR)/matrixTest: tester.cpp 
	$(CC) $(CPPFLAGS) tester.cpp $(GTEST_LL) -o $(BIN_DIR)/matrixTest



.PHONY: clean tests

tests: $(BIN_DIR)/matrixTest
	-@$(BIN_DIR)/matrixTest
	-@echo "--- All Tested! ---"

clean:
	-@rm -rf $(BIN_DIR)
	-@echo "--- All Clean! ---"