CXXFLAGS = --std=c++11 -g -Wall -lthread

all: matrix

matrix: main.o Gopinathan-Anjali.o
	g++ $(CXXFLAGS) main.o Gopinathan-Anjali.o -o matrix

Gopinathan-Anjali.o: Gopinathan-Anjali.h Gopinathan-Anjali.cpp
	g++ $(CXXFLAGS) -c Gopinathan-Anjali.cpp -o Gopinathan-Anjali.o

main.o: matrix.cpp
	g++ $(CXXFLAGS) -c matrix.cpp -o main.o

clean:
	rm -f *.o matrix