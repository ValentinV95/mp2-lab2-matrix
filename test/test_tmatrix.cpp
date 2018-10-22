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
	TMatrix<int> m1(2);
	m1[0][0] = 5;
	TMatrix<int> m2(m1);
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(2);
	m1[0][0] = 1;
	TMatrix<int> m2 = m1;
	m2[0][0] = 3;
	EXPECT_NE(m1, m2);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> mt(3);
	EXPECT_EQ(3, mt.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> mt(3);
	mt[0][0] = 5;
	EXPECT_EQ(5, mt[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> mt(3);
	ASSERT_ANY_THROW(mt[-1][-1] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> mt(3);
	ASSERT_ANY_THROW(mt[4][0] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(mt);
	mt = mt;
	EXPECT_EQ(mt1, mt);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> mt(3);
	TMatrix<int> mt1(3);
	mt[0][0] = 5;
	mt1[0][0] = 2;
	mt = mt1;
	EXPECT_EQ(mt, mt1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> mt(2);
	mt[0][0] = 1;
	mt[0][1] = 3;
	TMatrix<int> mt1(3);
	mt1[0][0] = 1;
	mt1[0][1] = 2;

	mt = mt1;
	EXPECT_EQ(mt.GetSize(), mt1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> mt(2);
	mt[0][0] = 1;
	mt[0][1] = 3;

	TMatrix<int> mt1(3);
	mt1[0][0] = 1;
	mt1[0][1] = 2;

	mt = mt1;
	EXPECT_EQ(mt, mt1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> mt(3);
	mt[0][0] = 1;
	mt[0][1] = 3;
	TMatrix<int>mt1(mt);
	EXPECT_EQ(1, mt == mt1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> mt(2);
	mt[0][0] = 1;
	mt[0][1] = 3;
	EXPECT_EQ(1, mt == mt);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> mt(2);
	mt[0][0] = 1;
	mt[0][1] = 3;
	TMatrix<int> mt1(3);
	mt1[0][0] = 1;
	mt1[0][1] = 2;

	EXPECT_NE(mt, mt1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> mt(2);
	mt[0][0] = 1;
	mt[0][1] = 3;
	mt[1][1] = 4;
	TMatrix<int> mt1(2);
	mt1[0][0] = 1;
	mt1[0][1] = 2;
	mt1[1][1] = 6;
	TMatrix<int> mt2(2);
	mt2[0][0] = 2;
	mt2[0][1] = 5;
	mt2[1][1] = 10;
	EXPECT_EQ(mt + mt1, mt2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> mt(1);
	mt[0][0] = 1;
	TMatrix<int> mt1(2);
	mt1[0][0] = 1;
	mt1[0][1] = 2;
	mt1[1][1] = 6;
	ASSERT_ANY_THROW(mt + mt1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> mt(2);
	mt[0][0] = 1;
	mt[0][1] = 3;
	mt[1][1] = 4;
	TMatrix<int> mt1(2);
	mt1[0][0] = 1;
	mt1[0][1] = 2;
	mt1[1][1] = 6;
	TMatrix<int> mt2(2);
	mt2[0][0] = 0;
	mt2[0][1] = 1;
	mt2[1][1] = -2;
	EXPECT_EQ(mt - mt1, mt2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> mt(1);
	mt[0][0] = 1;
	TMatrix<int> mt1(2);
	mt1[0][0] = 1;
	mt1[0][1] = 2;
	mt1[1][1] = 6;
	ASSERT_ANY_THROW(mt - mt1);
}

