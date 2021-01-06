#include <utmatrix.h>
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

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> A(3);
    TMatrix<int> A1(A);
    A[0][0] = 5;
    A1[0][0] = 4;
    EXPECT_NE(A[0][0], A1[0][0]);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> A(13);
    EXPECT_EQ(13, A.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> A(3);
    A[1][1] = 1;
    EXPECT_EQ(A[1][1], 1);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> Matrix;
    ASSERT_ANY_THROW(Matrix[-2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> Matrix;
    ASSERT_ANY_THROW(Matrix[MAX_MATRIX_SIZE + 1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> Matrix(4);
    ASSERT_NO_THROW(Matrix = Matrix);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> m(5), m1(7);
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            m[i][j] = i + 2 * j;
    m1 = m;
    EXPECT_EQ(m.GetSize(), m1.GetSize());
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m(5), m1(7);
    EXPECT_EQ(false, m == m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m(5), m1(10);
    ASSERT_ANY_THROW(m + m1);
}


