/** Test file. Contains main
 * 
 */

#include "Gopinathan-Anjali.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>


Matrix getMatrixFromUser(){
    unsigned int m, n;
    std::vector<std::vector<double>> userInput;
    std::vector<double> row;
    std::cout << "Enter m (rows):\t";
    std::cin >> m;
    std::cout << "Enter n (cols):\t";
    std::cin >> n;

    double val;
    std::cout << "Enter all " << m << " rows, each containing " << n 
                << " elements, separated by a space.\n" << std::endl; 
    for(unsigned int r=0; r<m; r++){
        std::cout << "Enter all " << n << " elements in row " << (r+1) << ", separated by a space:\t";        
        std::string blankLine;
        std::getline(std::cin, blankLine);
        for(unsigned int c = 0; c < n; c++){
            std::cin >> val;
            row.push_back(val);
        }
        userInput.push_back(row);
        row.clear();
    }
    Matrix input(userInput, m, n);
    return input;

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

void print_exception_message(const std::string& what_msg){
    std::cout << "Error - " << what_msg << std::endl;
}
int main(){
    bool quit = false;
    do{
        try{
            OperateMatrix oper;
            char t_m_response;
            std::cout << "This program will transpose and multiply matrices." << std::endl
                << "Do you want to transpose (t) one matrix or multiply (m) two matrices or quit(q)?" << std::endl;
            std::cin >> t_m_response;
            if(t_m_response == 't'){    //transpose
                std::cout << "You selected transpose." << std::endl;
                Matrix userMatrix = getMatrixFromUser();
                std::string userS = printMatrix(userMatrix);
                std::cout << "Your matrix:" << userS;

                Matrix transposed = oper.transpose(userMatrix);

                std::cout << "Transposed matrix:" << printMatrix(transposed);
            }
            else if(t_m_response == 'm'){   //multiply
                std::cout << "You selected multiply." << std::endl;
                Matrix m1 = getMatrixFromUser();
                Matrix m2 = getMatrixFromUser();
                Matrix prod = oper.multiply(m1, m2);
                std::string m1S = printMatrix(m1); std::string m2S = printMatrix(m2); std::string prodS = printMatrix(prod);
                std::cout << "The product of" << m1S << " and" << m2S << " is:" << prodS;
            }
            else if(t_m_response == 'q'){
                quit = true;
            }
            else {
                throw ("Please enter 't', 'm', or 'q'.");
            }
        }
        catch(const std::string e){
            std::cout << "Error - " << e << std::endl;
        }
    }while(!quit);
    return 0;
}