/** OperateMatrix class storing a matrix to operate on (transpose a 
 *  matrix or multiply two matrices) 
 * 
 */


class Matrix {
    public:
        Matrix(int** mtrx, int rows, int cols);     //constructor

        Matrix (const Matrix& myMatrix);    //copy constructor
        Matrix& operator=(const Matrix& myMatrix);  //copy assignment operator
        ~Matrix();  //destructor
    private:
        int** matrix_;   //2d array representing matrix
        std::size_t m_;  //rows
        std::size_t n_;  //columns

}
struct OperateMatrix {
    public:
        // OperateMatrix();
        // ~OperateMatrix();

        Matrix multiply(Matrix m1, Matrix m2);

        Matrix transpose(Matrix m);

}