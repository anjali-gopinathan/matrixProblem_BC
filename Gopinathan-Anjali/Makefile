CXXFLAGS = --std=c++11 -g -Wall

all: matrix

matrix: matrix.o Gopinathan-Anjali.h
	g++ $(CXXFLAGS) matrix.o Gopinathan-Anjali -o matrix

#Gopinathan-Anjali.o: Gopinathan-Anjali.h Gopinathan-Anjali.cpp
#	g++ $(CXXFLAGS) -c Gopinathan-Anjali.cpp -o Gopinathan-Anjali.o

#Gopinathan-Anjali: Gopinathan-Anjali.h 
#	g++ $(CXXFLAGS) -c -o Gopinathan-Anjali.o


matrix.o: matrix.cpp
	g++ $(CXXFLAGS) -c matrix.cpp -o matrix.o

clean:
	rm -f *.o matrix