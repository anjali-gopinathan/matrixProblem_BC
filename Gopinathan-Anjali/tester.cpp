#include "Gopinathan-Anjali.h"
#include "gtest/gtest.h"

TEST(MatrixTest, Nominal_TransposeSquare){
	OperateMatrix operate;

	Matrix a ({ {1, 2},
				{3, 4} }, 2, 2);	//2x2 matrix
	vect_2d result_a = {{1, 3},{2, 4}};

	Matrix b ({ {-2.2, 0.04, 3.9},
				{ 4.6,  -10,-5.0},
				{ 7.1,  9.2, -11}}, 3, 3);
	vect_2d result_b = {{-2.2, 4.6, 7.1},
						{0.04, -10, 9.2},
						{ 3.9,-5.0, -11}};

	EXPECT_EQ(result_a, operate.transpose(a).getMatrix());
	EXPECT_EQ(result_b, operate.transpose(b).getMatrix());
}

TEST(MatrixTest, Nominal_TransposeRect){

}