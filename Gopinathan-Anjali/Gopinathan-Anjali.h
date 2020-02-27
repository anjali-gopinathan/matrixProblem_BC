/** OperateMatrix class storing a matrix to operate on (transpose a 
 *  matrix or multiply two matrices) 
 */
#include <vector>

typedef std::vector<std::vector<double>> vect_2d;

struct Matrix{
    public:
        Matrix()
            : m_(0), n_(0) { }
        Matrix(unsigned int rows, unsigned int cols)
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
        Matrix(vect_2d matrix, unsigned int rows, unsigned int cols)
            : matrix_(matrix), m_(rows), n_(cols) { }
        void setMatrix(vect_2d matrix) 
            { matrix_ = matrix; }
        void setMatrixElement(unsigned int row, unsigned int col, double val)
            {
                matrix_[row][col] = val;
            }
        vect_2d getMatrix() 
            { return matrix_; }
        
        unsigned int getRows()
            { return m_; }
        unsigned int getCols()
            { return n_; }

    private:            
        vect_2d matrix_;
        unsigned int m_; //rows
        unsigned int n_; //cols
};

struct OperateMatrix {
    Matrix multiply(Matrix m1, Matrix m2)
    {
        Matrix product (m1.getRows(), m2.getCols());
        unsigned int dim = m1.getCols();
        for(unsigned int r=0; r<product.getRows(); r++){
            for(unsigned int c=0; c<product.getCols(); c++){
                double element = 0;
                for(unsigned int k=0; k<dim; k++){
                    element += (m1.getMatrix()[r][k] * m2.getMatrix()[k][c]);
                }
                product.setMatrixElement(r, c, element);
            }
        }
        return product;
    }

    Matrix transpose(Matrix m)
    {
        Matrix result(m.getCols(), m.getRows());

        for(unsigned int r = 0; r < m.getRows(); r++){
            for(unsigned int c = 0; c < m.getCols(); c++){
                // transposed[c][r] = m.getMatrix()[r][c];
                result.setMatrixElement(c, r, m.getMatrix()[r][c]);
            }
        }
        // result.setMatrix(transposed);    
        return result;
    }
};