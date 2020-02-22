/** Source code file. contains source code for the functions listed 
 *  in Gopinathan-Anjali.h
 * 
 */

#include <stdexcept>
#include "Gopinathan-Anjali.h"

const std::string MULTIPLY_BAD_DIMS = "The n value of matrix 1 does not match the m value of matrix 2. Cannot multiply these matrices.";

//matrix constructor
Matrix::Matrix(int** mtrx, std::size_t rows, std::size_t cols) 
    : m_(rows), n_(cols) 
{   
    //dynamically allocate memory for matrix_
    matrix_ = new int*[m_];
    for(unsigned int i = 0; i < m_; i++){
        matrix_[i] = new int[n_];
    }
}
//matrix copy constructor
Matrix::Matrix(const Matrix& myMatrix)
    : m_(myMatrix.m_), n_(myMatrix.n_)
{
    //dynamically allocate new memory to create 2d array    
    matrix_ = new int*[m_];
    for(unsigned int i = 0; i< m_; i++){
        matrix_[i] = new int[n_];
        
    }

    //assign matrix elements in matrix_ to elements in myMatrix
    for(unsigned int i = 0; i < m_; i++){
        for(unsigned int j = 0; j < n_; j++){
            matrix_[i][j] = myMatrix.matrix_[i][j];
        }
    }
}
//copy assignment operator
Matrix& operator=(const Matrix& myMatrix){
    //check if self assigning
    if(this == &myMatrix){
        return *this;   //return immediately if self assignment
    }

    //delete memory of current board
    for(unsigned int i=0; i < m_; i++){
        delete [] matrix_[i];
    }
}


//matrix assignment operator
Matrix::~Matrix(){

}
//matrix destructor


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
    //Matrix result (m);
}