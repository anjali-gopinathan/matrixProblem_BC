CXXFLAGS = --std=c++11 -g -Wall

all: matrix-test

matrix-test: matrix-test.o Gopinathan-Anjali.h
	g++ $(CXXFLAGS) matrix-test.cpp -o matrix-test

matrix-test.o: matrix-test.cpp
	g++ $(CXXFLAGS) -c matrix-test.cpp -o matrix-test.o

clean:
	rm -f *.o matrix-test