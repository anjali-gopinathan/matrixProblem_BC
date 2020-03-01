CC = g++
CPPFLAGS = --std=c++11 -g -Wall
GTEST_LL = -I /googletest/googletest/include/gtest/ -l gtest -l gtest_main -pthread


all: matrixTest

matrixTest.o: Gopinathan-Anjali.h
	$(CC) $(CPPFLAGS) -c Gopinathan-Anjali.h 

matrixTest: tester.cpp 
	$(CC) $(CPPFLAGS) tester.cpp $(GTEST_LL) -o matrixTest

userTests: user-test.o Gopinathan-Anjali.h
	g++ $(CXXFLAGS) user-test.cpp -o userTests

tests: matrixTest
	-@./matrixTest
	-@echo "--- All Tested! ---"

clean:
	-@rm *.o *.h.gch matrixTest
	-@echo "--- All Clean! ---"