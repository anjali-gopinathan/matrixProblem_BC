/** Test file. Contains main
 * 
 * 
 */

#include "Gopinathan-Anjali.h"
#include <iostream>
#include <stdexcept>

Matrix getMatrixFromUser(){
    int m, n;
    vector<vector<double>> userInput;
    vector<double> row;
    std::cout << "Enter m (rows):\t";
    std::cin >> m;
    std::cout << "Enter n (cols):\t";
    std::cin >> n;

    double val;
    for(unsigned int r=1; r<=m; r++){
        std::cout << "Enter all " << n << " elements in row" << r << ":\t";        
        for(unsigned int c = 1; c <= n; c++){
            std::cin >> val;
            row.push_back(val);
        }
        userInput.push_back(row);
    }
    return userInput;

}

int main(){
    OperateMatrix oper;
    char t_m_response;
    std::cout << "This program will transpose and multiply matrices." << std::endl
        << "Do you want to transpose (t) one matrix or multiply (m) two matrices?" << std::endl;
    std::cin >> t_m_response;
    if(t_m_response == 't'){    //transpose
        std::cout << "You selected transpose." << std::endl;
        oper.transpose(getMatrixFromUser());
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