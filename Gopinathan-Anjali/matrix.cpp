/** Test file. Contains main
 * 
 */

#include "Gopinathan-Anjali.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

const std::string ERROR_STARTER = "Error - ";
const std::string BAD_DIMENSION = "Invalid entry. Enter a positive integer.";
const std::string BAD_MTRX_ELEMENT = "Invalid entry. Enter a properly formatted number.";
const std::string BAD_MULT_DIMS = "The number of columns in matrix 1 must match the number of rows in matrix 2.";
const std::string BAD_CHAR_SELECTION = "Please enter 't', 'm', or 'q'.";
unsigned int getRowsFromUser(){
    unsigned int m;
    std::cout << "Enter m (rows):\t";
    std::cin >> m;
    if(std::cin.fail() || m <= 0){ 
        throw (BAD_DIMENSION);
    }
    return m;
}
unsigned int getColsFromUser(){
    unsigned int n;
    std::cout << "Enter n (cols):\t";
    std::cin >> n;
    if(std::cin.fail() || n <= 0){ 
        throw (BAD_DIMENSION);
    }
    return n;
}

vect_2d getMatrixFromUser(unsigned int m, unsigned int n){
    vect_2d userInput;
    std::vector<double> row;

    double val;
    std::cout << "Enter all " << m << " rows, each containing " << n 
                << " elements, separated by a space.\n" << std::endl; 
    for(unsigned int r=0; r<m; r++){
        std::cout << "Enter all " << n << " elements in row " << (r+1) 
                << ", separated by a space:\t";        
        std::string blankLine;
        std::getline(std::cin, blankLine);
        for(unsigned int c = 0; c < n; c++){
            std::cin >> val;
            if(std::cin.fail()){
                throw (BAD_MTRX_ELEMENT);
            }
            row.push_back(val);
        }
        userInput.push_back(row);
        row.clear();
    }
    return userInput;

}
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
    bool quit = false, error = false;

    std::cout << "This program can transpose and multiply matrices." 
        << std::endl;
    do{
        try{
            OperateMatrix oper;
            char responseChar;

                std::cout << "Select to either: "
                << "transpose (t) a matrix, multiply (m) two matrices or quit (q)?" 
                << std::endl;
            std::cin >> responseChar;

            if(responseChar == 't'){    //transpose
                std::cout << "You selected transpose." << std::endl;
                unsigned int rows = getRowsFromUser();
                unsigned int cols = getColsFromUser();
                vect_2d mtrx = getMatrixFromUser(rows, cols);
                
                Matrix userMatrix(mtrx, rows, cols);
                
                // std::string userS = printMatrix(userMatrix);
                std::cout << "Your matrix:" << printMatrix(userMatrix);

                Matrix transposed = oper.transpose(userMatrix);

                std::cout << "Transposed matrix:" << printMatrix(transposed);
            }
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
                    throw (BAD_MULT_DIMS);
                }
                unsigned int m2_cols = getColsFromUser();
                vect_2d mtrx2 = getMatrixFromUser(m2_rows, m2_cols);
                Matrix m2 (mtrx2, m2_rows, m2_cols);
                Matrix prod = oper.multiply(m1, m2);

                std::string m1S = printMatrix(m1); std::string m2S = printMatrix(m2); std::string prodS = printMatrix(prod);
                std::cout << "The product of" << m1S << " and" << m2S << " is:" << prodS;
            }
            else if(responseChar == 'q'){
                quit = true;
            }
            else {
                throw (BAD_CHAR_SELECTION);
            }
        }
        catch(const std::string e){
            std::cout << ERROR_STARTER << e << std::endl;
            error = true;
        }
    }while(!quit && !error);
    return 0;
}