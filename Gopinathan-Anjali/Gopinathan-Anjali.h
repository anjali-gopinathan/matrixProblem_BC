/** Anjali Gopinathan - Matrix Multiplication and Transposition  
 * 
 *  OperateMatrix class storing a matrix to operate on (transpose a 
 *  matrix or multiply two matrices) 
 */
#include <vector>

typedef std::vector<std::vector<double>> vect_2d;

struct Matrix{
    public:
        //default constructor
        Matrix()
            : m_(0), n_(0) { }
        //constructor. sets matrix elements to 0.
        Matrix(unsigned int rows, unsigned int cols)
            : m_(rows), n_(cols)
            { 
                //initialize matrix with zeros
                matrix_.resize(m_);
                for(unsigned int i=0; i<m_; i++){
                    matrix_[i].resize(n_);
                    for(unsigned int j=0; j<n_; j++){
                        matrix_[i][j] = 0;
                    }
                }
            }
        //constructor. assigns private variables
        Matrix(vect_2d matrix, unsigned int rows, unsigned int cols)
            : matrix_(matrix), m_(rows), n_(cols) { }
        //setter functions
        void setMatrix(vect_2d matrix) 
            { matrix_ = matrix; }
        void setMatrixElement(unsigned int row, unsigned int col, double val)
            {
                matrix_[row][col] = val;
            }

        //getter functions, accessors for private data members
        vect_2d getMatrix() 
            { return matrix_; }
        unsigned int getRows()
            { return m_; }
        unsigned int getCols()
            { return n_; }

    private:            
        vect_2d matrix_; //matrix
        unsigned int m_; //rows
        unsigned int n_; //cols
};

struct OperateMatrix {
    /*  multiply() contains the algorithm for multiplying matrices.
     */
    Matrix multiply(Matrix m1, Matrix m2)
    {
        Matrix product (m1.getRows(), m2.getCols());
        unsigned int dim = m1.getCols();
        for(unsigned int r=0; r<product.getRows(); r++){
            for(unsigned int c=0; c<product.getCols(); c++){
                double val = 0;
                for(unsigned int k=0; k<dim; k++){
                    val += (m1.getMatrix()[r][k] * m2.getMatrix()[k][c]);
                }
                product.setMatrixElement(r, c, val);
            }
        }
        return product;
    }
    /*  transpose() contains the algorithm for transposing a matrix.
     */
    Matrix transpose(Matrix m)
    {
        Matrix result(m.getCols(), m.getRows());
        for(unsigned int r = 0; r < m.getRows(); r++){
            for(unsigned int c = 0; c < m.getCols(); c++){
                result.setMatrixElement(c, r, m.getMatrix()[r][c]);
            }
        }
        return result;
    }
};