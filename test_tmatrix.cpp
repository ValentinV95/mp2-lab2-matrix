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
	TMatrix<int> m(5);
	TMatrix<int>  a = m;
	EXPECT_EQ(a, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	TMatrix<int>  a = m;
	a[0][0] = 0;
	EXPECT_NE(a, m);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ( m.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[0][0] = 1;
	EXPECT_EQ(m[0][0], 1);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	EXPECT_ANY_THROW(m[-1][-1]= 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	EXPECT_ANY_THROW(m[10][10] = 1);

}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	EXPECT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5);
	TMatrix<int> a(5);
	EXPECT_NO_THROW(m = a);

}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5);
	TMatrix<int> a(7);
	m = a;
	EXPECT_EQ(m.GetSize(), a.GetSize());

}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5);
	TMatrix<int> a(7);
	EXPECT_NO_THROW (m = a);

}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5);
	TMatrix<int> a(5);
	m = a;
	EXPECT_EQ(m==a, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	TMatrix<int> a(5);
	EXPECT_EQ(m == m, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(5);
	TMatrix<int> a(7);
	EXPECT_EQ(m != a, true);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(5);
	TMatrix<int> a(5);
	EXPECT_NO_THROW(m+a);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(5);
	TMatrix<int> a(7);
	EXPECT_ANY_THROW(m + a);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(5);
	TMatrix<int> a(5);
	EXPECT_NO_THROW(m - a);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(5);
	TMatrix<int> a(7);
	EXPECT_ANY_THROW(m - a);
}

