/** OperateMatrix class storing a matrix to operate on (transpose a 
 *  matrix or multiply two matrices) 
 */
#include <vector>

class Matrix{
    public:
        Matrix();
        Matrix(int rows, int cols);
        vector<vector<double>> matrix_;
    private:
        int m_; //rows
        int n_; //cols
}

struct OperateMatrix {
    //OperateMatrix();
    Matrix multiply(Matrix m1, Matrix m2);
    Matrix transpose(Matrix m);
}