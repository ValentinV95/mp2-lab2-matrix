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
	TMatrix<int> m1(m);
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(m);
	EXPECT_NE(&m[0][0], &m1[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m1(10);
	EXPECT_EQ(10, m1.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix <int> a(5);
	EXPECT_EQ(1, (a[1][1] = 1));
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix <int> a(5);
	ASSERT_ANY_THROW(a[-1][-1] = 5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix <int> a(MAX_MATRIX_SIZE);
	ASSERT_ANY_THROW(a[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = 5);

}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(5);
	m1[0][0] = 1;
	ASSERT_NO_THROW(m = m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> a(5), b(3);
	b = a;
	EXPECT_EQ(5, b.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(6);
	m1[0][0] = 1;
	ASSERT_NO_THROW(m = m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(5);
	m = m1;
	EXPECT_TRUE(m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	EXPECT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> a(5), b(4);
	EXPECT_NE(a, b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> a(5), b(5), c(5);
	a[0][0] = 5;
	b[0][0] = 10;
	c[0][0] = 15;
	EXPECT_EQ(c, a + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> a(5), b(6);
	EXPECT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> a(5), b(5), c(5);
	a[0][0] = 5;
	b[0][0] = 10;
	c[0][0] = -5;
	EXPECT_EQ(c, a - b);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> a(5), b(6);
	EXPECT_ANY_THROW(a - b);
}
