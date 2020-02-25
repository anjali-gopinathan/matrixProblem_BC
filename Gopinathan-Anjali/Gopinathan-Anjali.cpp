/** Source code file. contains source code for the functions listed 
 *  in Gopinathan-Anjali.h
 * 
 */

#include <stdexcept>
#include "Gopinathan-Anjali.h"

const std::string MULTIPLY_BAD_DIMS = "The n value of matrix 1 does not match the m value of matrix 2. Cannot multiply these matrices.";

Matrix::Matrix()
    : m_(0), n_(0)    
{ }

Matrix(int rows, int cols)
    : m_(rows), n_(cols)
{ }

Matrix OperateMatrix::multiply(Matrix m1, Matrix m2){
    if(m1.n_ != m2.m_){
        throw std::invalid_argument(MULTIPLY_BAD_DIMS);
    }

}

Matrix OperateMatrix::transpose(Matrix m){
    Matrix transposed;

    for(int r = 0; r < m.m_; r++){
        for(int c = 0; c < m.n_; c++){
            
        }
    }

}