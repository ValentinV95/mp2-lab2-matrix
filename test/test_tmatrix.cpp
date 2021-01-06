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
    TMatrix <int> a(5);
    a[0][0] = 6;
    TMatrix <int> b(a);
    ASSERT_EQ(a, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> a(5), b(a);
    b[0][0] = 1;
    EXPECT_EQ(true, a != b);
}

TEST(TMatrix, can_get_size)
{
    TMatrix <int> a(5);
    EXPECT_EQ(5, a.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix <int> a(5);
    a[0][0] = 5;
    int b = a[0][0];
    EXPECT_EQ(10, b);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix <int> a(5);
    ASSERT_ANY_THROW(a[-1][1] = 0);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix <int> a(5);
    ASSERT_ANY_THROW(a[5][1] = 0);

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix <int> a(5);
    a[0][0] = 5;
    TMatrix <int > b(a);
    a = a;
    EXPECT_EQ(a, b);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix <int> a(5);
    TMatrix <int> b(5);
    a[0][0] = 5;
    b = a;
    EXPECT_EQ(b, a);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix <int> a(5);
    TMatrix <int> b(4);
    a = b;
    EXPECT_EQ(4, a.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  ADD_FAILURE();
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix <int> a(5), b(5);
    EXPECT_EQ(true, a == b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix <int> a(5);
    EXPECT_EQ(true, a == a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix <int> a(5), b(4);
    EXPECT_EQ(false, a == b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix <int> a(5), b(5), c(5);
    c[0][0] = 10;
    b[0][0] = 5;
    a[0][0] = 5;
    EXPECT_EQ(c, a + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix <int> a(5), b(4);
    ASSERT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix <int> a(5), b(5), c(5);
    b[0][0] = 5;
    a[0][0] = 5;
    EXPECT_EQ(c, a - b);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix <int> a(5), b(4);
    ASSERT_ANY_THROW(a - b);
}

