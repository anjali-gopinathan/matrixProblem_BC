/** Test file. Contains main
 * 
 * 
 */

#include "Gopinathan-Anjali.h"
#include <iostream>
#include <stdexcept>


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
                << " elements, separated by a space." << std::endl; 
    for(unsigned int r=0; r<m; r++){
        std::cout << "Enter all " << n << " elements in row " << (r+1) << ", separated by a space:\t";        
        for(unsigned int c = 0; c < n; c++){
            std::cin >> val;
            row.push_back(val);
        }
        userInput.push_back(row);
    }
    Matrix input(userInput, m, n);
    return input;

}
void printMatrix(Matrix m){
    for(unsigned int i=0; i<m.getRows(); i++){
        for(unsigned int j=0; j<m.getCols(); j++){
            std::cout << m.getMatrix()[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    OperateMatrix oper;
    char t_m_response;
    std::cout << "This program will transpose and multiply matrices." << std::endl
        << "Do you want to transpose (t) one matrix or multiply (m) two matrices?" << std::endl;
    std::cin >> t_m_response;
    if(t_m_response == 't'){    //transpose
        std::cout << "You selected transpose." << std::endl;
        Matrix userMatrix = getMatrixFromUser();

        std::cout << "Your matrix:\n";
        printMatrix(userMatrix);


        Matrix transposeThis = oper.transpose(userMatrix);

        std::cout << "Transposed matrix:" << std::endl;
        printMatrix(transposeThis);
    }
    else if(t_m_response == 'm'){   //multiply
        std::cout << "You selected multiply." << std::endl;
        Matrix m1 = getMatrixFromUser();
        Matrix m2 = getMatrixFromUser();
        oper.multiply(m1, m2);
    }
    else if(t_m_response == 'q'){
        return 0;
    }
    else {
        throw std::invalid_argument("Please enter 't', 'm', or 'q'.");
    }
    return 0;
}