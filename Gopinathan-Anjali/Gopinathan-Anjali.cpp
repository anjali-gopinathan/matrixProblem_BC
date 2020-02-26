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

Matrix::Matrix(unsigned int rows, unsigned int cols)
    : m_(rows), n_(cols)
{ 
    matrix_.resize(m_);   //outer vector consists of each row, so it has size rows (m_)
    for(unsigned int i=0; i<m_; i++){
        matrix_[i].resize(n_);
        for(unsigned int j=0; j<n_; j++){
            matrix_[i][j] = 0;
        }
    }
}

Matrix::Matrix(std::vector<std::vector<double>> matrix, unsigned int rows, unsigned int cols)
    : matrix_(matrix), m_(rows), n_(cols) { }
//setters for private variables of Matrix
void Matrix::setMatrix(std::vector<std::vector<double>> matrix){
    matrix_ = matrix;
}

//getters for private variables of Matrix
std::vector<std::vector<double>> Matrix::getMatrix(){
    return matrix_;
}
unsigned int Matrix::getRows(){
    return m_;
}
unsigned int Matrix::getCols(){
    return n_;
}

Matrix OperateMatrix::multiply(Matrix m1, Matrix m2)
{
    if(m1.getCols() != m2.getRows()){
        throw MULTIPLY_BAD_DIMS;
    }
    Matrix product (m1.getRows(), m2.getCols());
    std::vector<std::vector<double>> multiplied = product.getMatrix();
    unsigned int dim = m1.getCols();
    for(unsigned int r=0; r<product.getRows(); r++){
        for(unsigned int c=0; c<product.getCols(); c++){
            double element = 0;
            for(unsigned int k=0; k<dim; k++){
                element += (m1.getMatrix()[r][k] * m2.getMatrix()[k][c]);
            }
            multiplied[r][c] = element;
        }
    }
    product.setMatrix(multiplied);
    
    return product;
}

Matrix OperateMatrix::transpose(Matrix m)
{
    Matrix result(m.getCols(), m.getRows());
    std::vector<std::vector<double>> transposed = result.getMatrix();

    for(unsigned int r = 0; r < m.getRows(); r++){
        for(unsigned int c = 0; c < m.getCols(); c++){
            transposed[c][r] = m.getMatrix()[r][c];
        }
    }
    result.setMatrix(transposed);
    return result;

}