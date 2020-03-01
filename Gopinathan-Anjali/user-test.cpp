/** Anjali Gopinathan - Matrix Multiplication and Transposition 
 * 
 * user-test.cpp: tester file. Contains main.
 */

#include "Gopinathan-Anjali.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

const std::string BAD_DIMENSION = "Invalid entry. Dimension must be a positive integer.";
const std::string BAD_MTRX_ELEMENT = "Invalid entry. Element must be a properly formatted number.";
const std::string BAD_CHAR_SELECTION = "Response must be 't' or 'm'.";
const std::string ERROR_STARTER = "Error - ";
const std::string BAD_MULT_DIMS = "The number of columns in matrix 1 must match the number of rows in matrix 2.";

/* The following two functions, getRowsFromUser and getColsFromUser, take 
 * input from the user and error check to make sure the input is valid .
 */
unsigned int getRowsFromUser(){
    unsigned int m;
    std::cout << "Enter m (rows):\t";
    std::cin >> m;
    //Throw an error if input is not an unsigned int
    if(std::cin.fail() || m == 0){    
        throw std::invalid_argument(BAD_DIMENSION); 
    }
    return m;
}

unsigned int getColsFromUser(){
    unsigned int n;
    std::cout << "Enter n (cols):\t";
    std::cin >> n;
    //Throw an error if input is not an unsigned int
    if(std::cin.fail() || n == 0){ 
        throw std::invalid_argument(BAD_DIMENSION);
    }
    return n;
}
/* Reads in user input into a vector of vectors of doubles. This data type, 
 * abstracted to be called a "vect_2d", represents the matrix. 
 * getMatrixFromUser() also does error checks to make sure that the element 
 * type is valid.
 */
vect_2d getMatrixFromUser(unsigned int m, unsigned int n){
    vect_2d userInput;
    std::vector<double> row;
    double val;
    std::cout << "\nEnter all " << m << " rows, each containing " << n 
                << " elements, separated by whitespace." << std::endl; 
    for(unsigned int r=0; r<m; r++){
        std::cout << "Enter all " << n << " elements in row " << (r+1) 
                << ", separated by a space:\t";        
        std::string blankLine;
        std::getline(std::cin, blankLine);
        for(unsigned int c = 0; c < n; c++){
            std::cin >> val;
            if(std::cin.fail()){
                throw std::invalid_argument(BAD_MTRX_ELEMENT);
            }
            row.push_back(val);
        }
        userInput.push_back(row);
        row.clear();
    }
    std::cout << std::endl;
    return userInput;
}
/*Prints out a given matrix.
 */
std::string printMatrix(Matrix m){
    std::stringstream result;
    result << "\n";
    for(unsigned int i=0; i<m.getRows(); i++){
        for(unsigned int j=0; j<m.getCols(); j++){
            result << m.getMatrix()[i][j] << "\t";
        }
        result << "\n";
    }
    return result.str();
}

int main(){
    std::cout << "This program can transpose and multiply matrices." 
        << std::endl;
    try{
        OperateMatrix oper;
        char responseChar;

            std::cout << "Select to either: "
            << "transpose (t) a matrix or multiply (m) two matrices?" 
            << std::endl;
        std::cin >> responseChar;
        /* Calls appropriate functions if user chooses transpose
         */
        if(responseChar == 't'){    //transpose
            std::cout << "You selected transpose." << std::endl;
            unsigned int rows = getRowsFromUser();
            unsigned int cols = getColsFromUser();
            vect_2d mtrx = getMatrixFromUser(rows, cols);
            
            Matrix userMatrix(mtrx, rows, cols);
            
            std::cout << "Your matrix:" << printMatrix(userMatrix);

            Matrix transposed = oper.transpose(userMatrix);

            std::cout << "\nTransposed matrix:" << printMatrix(transposed);
        }
        /* Calls appropriate functions if user chooses multiply
         */
        else if(responseChar == 'm'){   //multiply
            std::cout << "You selected multiply." << std::endl;
            std::cout << "Enter the following for matrix 1:" << std::endl;
            unsigned int m1_rows = getRowsFromUser();
            unsigned int m1_cols = getColsFromUser();
            vect_2d mtrx1 = getMatrixFromUser(m1_rows, m1_cols); 
            Matrix m1 (mtrx1, m1_rows, m1_cols);
            
            std::cout << "Enter the following for matrix 2:" << std::endl;
            unsigned int m2_rows = getRowsFromUser();
            if(m2_rows != m1_cols){
                throw std::invalid_argument(BAD_MULT_DIMS);
            }
            unsigned int m2_cols = getColsFromUser();
            vect_2d mtrx2 = getMatrixFromUser(m2_rows, m2_cols);
            Matrix m2 (mtrx2, m2_rows, m2_cols);
            Matrix prod = oper.multiply(m1, m2);

            std::cout << "The product of" << printMatrix(m1) << "\nand\n" 
            << printMatrix(m2) << "\nis:\n" << printMatrix(prod);
        }
        else {
            /*  Throw an error if result is neither 't' nor 'm'
             */
            throw std::invalid_argument(BAD_CHAR_SELECTION);
        }
    }
    catch(const std::exception& e){
        std::cout << ERROR_STARTER << e.what() << std::endl;
    }
    return 0;
}