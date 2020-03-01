#include "Gopinathan-Anjali.h"
#include "gtest/gtest.h"

TEST(MatrixTest, Nominal_Transpose){
	OperateMatrix operate;

	//transposing a 2x2 square matrix:
	Matrix a ({ {1, 2},
				{3, 4} }, 2, 2);	
	vect_2d a_result = {{1, 3},{2, 4}};

	//transposing a 3x3 square matrix:
	Matrix b ({ {-2.2, 0.04, 3.9},		
				{ 4.6,  -10,-5.0},
				{ 7.1,  9.2, -11}}, 3, 3);
	vect_2d b_result = {{-2.2, 4.6, 7.1},
						{0.04, -10, 9.2},
						{ 3.9,-5.0, -11}};

	//transposing a 2x3 rectangular matrix"
	Matrix c ({ {1,3,5},
				{2,4,6}}, 2, 3);
	vect_2d c_result = {{1,2},{3,4},{5,6}};

	EXPECT_EQ(a_result, operate.transpose(a).getMatrix());
	EXPECT_EQ(b_result, operate.transpose(b).getMatrix());
	EXPECT_EQ(c_result, operate.transpose(c).getMatrix());
}

TEST(MatrixTest, Nominal_Multiply){
	OperateMatrix operate;
	//multiplying matrices
	Matrix d ({{1,2},{3,-2},{-4,0}}, 3, 2);
	Matrix e ({ {5,10,-4},
				{-6,3,0}}, 2, 3);
	vect_2d d_times_e = { {-7,16, -4},
						{27,24,-12},
						{-20,-40,16}};
	vect_2d e_times_d = {{51,-10},{3,-18}};

	EXPECT_EQ(d_times_e, operate.multiply(d, e).getMatrix());
	EXPECT_EQ(e_times_d, operate.multiply(e, d).getMatrix());
}
TEST(MatrixTest, OffNominal_Multiply){
	OperateMatrix operate;
	//multiplying a 3x2 matrix by a 1x3 matrix should not work
	Matrix d ({{1,2},{3,-2},{-4,0}}, 3, 2);
	Matrix f (1,3);
	EXPECT_THROW(operate.multiply(d,f).getMatrix(), std::invalid_argument);
}

