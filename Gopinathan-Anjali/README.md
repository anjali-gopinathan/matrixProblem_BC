# Anjali Gopinathan - Matrix Multiplication and Transposition
This program multiplies and transposes matrices.

## Compilation
To compile, type ```make```.

## Execution
To run with my tests, as defined in tester.cpp, execute: ```make tests```

To run with the user's input with an interactive command line UI, execute ``` make userTests``` followed by ```./userTests```.

### Test cases
To run test cases, I used google tests. In order for the ```make tests``` command to execute properly, the gtest libary must be installed. It doesn't matter where the gtest libray is installed on the computer, it just needs to be consistent with the path described in the Makefile. I installed the gtest library from [Google's googletest Github repository](https://github.com/google/googletest), and I detailed its path in the Makefile.