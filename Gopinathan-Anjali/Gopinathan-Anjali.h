/** OperateMatrix class storing a matrix to operate on (transpose a 
 *  matrix or multiply two matrices) 
 * 
 */


class OperateMatrix {
    public:
        struct Matrix {
            int** matrix_;   //2d array representing matrix
            int m_;  //rows
            int n_;  //columns
            Matrix(int** mtrx, int rows, int cols);
            ~Matrix();
        }
        // OperateMatrix();
        // ~OperateMatrix();

        Matrix multiply(Matrix m1, Matrix m2);

        Matrix transpose(Matrix m);


    //private:












}