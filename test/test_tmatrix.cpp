#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<double> mt1(3);
	TMatrix<double> mt2 = mt1;
	EXPECT_EQ(mt1, mt2);
}
TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<double> mt1(4);
	TMatrix<double> mt2 = mt1;
	EXPECT_NE(&mt1[0], &mt2[0]);
}
TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}
TEST(TMatrix, can_set_and_get_element)
{
	const int exp = 11;
	TMatrix<int> mt(6);

	mt[1][4] = exp;
	EXPECT_EQ(exp, mt[1][4]);
}
TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> mt(4);
	ASSERT_ANY_THROW(mt[1][-2]);
}
TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> mt(5);
	ASSERT_ANY_THROW(mt[5]);
}
TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> mt(3);
	mt[0][0] = 3; mt[0][1] = 1; mt[1][1] = 2;
	mt = mt;
	EXPECT_EQ(3, mt[0][0]);
	EXPECT_EQ(1, mt[0][1]);
	EXPECT_EQ(2, mt[1][1]);
}
TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(2);
	m[0][0] = 1; m[0][1] = 2; m[1][1] = 3;
	TMatrix<int> m1(2);
	m = m1;
	EXPECT_EQ(m, m1);
}
TEST(TMatrix, assign_operator_change_matrix_size)
{
	const int size1 = 3, size2 = 5;
	TMatrix<double> mt1(size1), mt2(size2);
	mt1 = mt2;
	EXPECT_NE(size1, mt1.GetSize());
}
TEST(TMatrix, can_assign_matrices_of_different_size)
{
	const int size1 = 3, size2 = 5;
	TMatrix<double> mt1(size1), mt2(size2);
	mt1 = mt2;
	EXPECT_EQ(mt1, mt2);
}
TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> mt1(3), mt2(3);
	for (int i = 0; i < 3; i++) {
		mt1[i] = mt2[i];
	}
	EXPECT_EQ(mt1, mt2);
}
TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<float> mt(7);
	EXPECT_EQ(mt, mt);
}
TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	const int size1 = 3, size2 = 5;
	TMatrix<double> mt1(size1), mt2(size2);

	EXPECT_NE(mt1, mt2);
}
TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(3);
	m[0][0] = 1; m[1][1] = 2; m[2][2] = 3;
	m[0][1] = 2; m[0][2] = 3; m[1][2] = 3;
	TMatrix<int> m1(3);
	m1[0][0] = 3; m1[1][1] = 2; m1[2][2] = 1;
	m1[0][1] = 2; m1[0][2] = 1; m1[1][2] = 1;
	TMatrix<int> m2(3);
	m2[0][0] = 4; m2[1][1] = 4; m2[2][2] = 4;
	m2[0][1] = 4; m2[0][2] = 4; m2[1][2] = 4;
	EXPECT_EQ(m + m1, m2);
}
TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> mt1(6), mt2(11);
	ASSERT_ANY_THROW(mt1 + mt2);
}
TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	const int size = 2;
	TMatrix<int> mt1(size), mt2(size), expMt(size);
	mt1[0][0] = 3; mt1[0][1] = 5;
	mt1[1][1] = 1;
	mt2[0][0] = 7; mt2[0][1] = 5;
	mt2[1][1] = 9;
	expMt[0][0] = -4; expMt[0][1] = 0;
	expMt[1][1] = -8;
	EXPECT_EQ(expMt, mt1 - mt2);
}
TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> mt1(3), mt2(4);
	ASSERT_ANY_THROW(mt1 - mt2);
}