/** OperateMatrix class storing a matrix to operate on (transpose a 
 *  matrix or multiply two matrices) 
 */
#include <vector>


struct Matrix{
    public:
        Matrix();
        Matrix(unsigned int rows, unsigned int cols);
        Matrix(std::vector<std::vector<double>> matrix, unsigned int rows, unsigned int cols);

        //void setMatrixAtElement(unsigned int r, unsigned int c);
        void setMatrix(std::vector<std::vector<double>> matrix);
        void setRows(unsigned int rows);
        void setCols(unsigned int cols);

        std::vector<std::vector<double>> getMatrix();
        unsigned int getRows();
        unsigned int getCols();

    private:    
        
        std::vector<std::vector<double>> matrix_;
        unsigned int m_; //rows
        unsigned int n_; //cols
};

struct OperateMatrix {
    //OperateMatrix();
    Matrix multiply(Matrix m1, Matrix m2);
    Matrix transpose(Matrix m);
};