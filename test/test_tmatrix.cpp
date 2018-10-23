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
	TMatrix<int> mt(5);
	TMatrix<int> mt1;

	EXPECT_EQ(mt, mt1 = mt);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}

	TMatrix<int> mt1(mt);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt1[i][j] = 2;
	}

	EXPECT_NE(mt, mt1);
}

TEST(TMatrix, can_get_size)
{
	const int Size = 4;
	TMatrix<int> mt(4);

	EXPECT_EQ(Size, mt.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	const int temp = 17;
	TMatrix<int> mt(2);
	mt[1][1] = temp;

	EXPECT_EQ(temp, mt[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> mt(3);

	ASSERT_ANY_THROW(mt[-1][-2] = 0);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> mt(3);

	ASSERT_ANY_THROW(mt[10][5] = 0);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}

	TMatrix<int> mt1(mt);

	EXPECT_EQ(mt = mt, mt1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}
	TMatrix<int> mt1(5);

	EXPECT_EQ(mt, mt1 = mt);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}

	TMatrix<int> mt1(5);

	mt1 = mt;

	EXPECT_EQ(mt.GetSize(), mt1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}
	TMatrix<int> mt1(7);

	EXPECT_EQ(mt, mt1 = mt);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}
	TMatrix<int> mt1(mt);

	EXPECT_EQ(mt1 == mt, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}

	EXPECT_EQ(mt == mt, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}
	TMatrix<int> mt1(3);

	EXPECT_EQ(mt1 != mt, true);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}
	TMatrix<int> mt1(mt);

	TMatrix<int> mt2(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt2[i][j] = 2;
	}

	EXPECT_EQ(mt1 + mt, mt2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}
	TMatrix<int> mt1(3);

	ASSERT_ANY_THROW(mt1 + mt);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> mt(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
			mt[i][j] = 3;
	}
	TMatrix<int> mt1(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
			mt1[i][j] = 2;
	}

	TMatrix<int> mt2(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
			mt2[i][j] = 1;
	}

	EXPECT_EQ(mt - mt1, mt2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> mt(5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
			mt[i][j] = 1;
	}
	TMatrix<int> mt1(3);

	ASSERT_ANY_THROW(mt1 - mt);
}


