/** Source code file. contains source code for the functions listed 
 *  in Gopinathan-Anjali.h
 * 
 */

#include <stdexcept>
#include "Gopinathan-Anjali.h"

const std::string MULTIPLY_BAD_DIMS = "The n value of matrix 1 does not match the m value of matrix 2. Cannot multiply these matrices.";

OperateMatrix::Matrix::Matrix(int** mtrx, int rows, int cols) 
    : m_(rows), n_(cols) 
{   
    //dynamically allocate memory for matrix_
    matrix_ = new int*[m_];
    for(int i = 0; i < m_; i++){
        matrix_[i] = new int[n_];
    }
}

//default constructor
OperateMatrix::OperateMatrix() {


}

//destructor
OperateMatrix::~OperateMatrix(){


}

Matrix OperateMatrix::multiply(Matrix m1, Matrix m2){
    if(m1.n_ != m2.m_){
        throw std::invalid_argument(MULTIPLY_BAD_DIMS);
    }
}

Matrix OperateMatrix::transpose(Matrix m){

}