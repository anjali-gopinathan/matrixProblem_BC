/** Test file. Contains main
 * 
 * 
 */

#include "Gopinathan-Anjali.h"
#include <iostream>
#include <stdexcept>

Matrix getMatrixFromUser(){
    int m, n;


    std::cout << "Enter m (rows):\t";
    std::cin >> m;
    std::cout << "Enter n (cols):\t";
    std::cin >> n;

    //dynamically allocate new matrix from user
    int** mtrx = new int*[m];
    for(int i = 0; i < m; i++){
        mtrx[i] = new int[n];
    }

    for(unsigned int r=1; r<=m; r++){
        std::cout << "Enter all " << n << " elements in row" << r << ":\t";
        for(int c = 1; c <= n; c++){
            std::cin >> mtrx[r-1][c-1];
        }
    }
//    OperateMatrix::Matrix m = new OperateMatrix::Matrix();
}

int main(){
    
    char t_m_response;
    std::cout << "This program will transpose and multiply matrices." << std::endl
        << "Do you want to transpose (t) one matrix or multiply (m) two matrices?" << std::endl;
    std::cin >> t_m_response;
    if(t_m_response == 't'){    //transpose
        std::cout << "You selected transpose." << std::endl;

        
    }
    else if(t_m_response == 'm'){   //multiply

    }
    else if(t_m_response == 'q'){
        break;
    }
    else {
        throw std::invalid_argument("Please enter 't', 'm', or 'q'.");
    }



    return 0;
}