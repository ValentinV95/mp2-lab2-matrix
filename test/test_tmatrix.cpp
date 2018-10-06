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
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}

	TMatrix<int> m1(m);

	EXPECT_EQ(m1, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  	TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}

	TMatrix<int> m1(m);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m1[i][j] = (i + j)*2;
		}
	}

	EXPECT_NE(m1, m);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);

	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  	TMatrix<int> m(5);

	m[1][1] = 42;

	EXPECT_EQ(42, m[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(5);

	ASSERT_ANY_THROW(m[-1][1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(5);

	ASSERT_ANY_THROW(m[1][6]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TMatrix<int> m1(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m1[i][j] = i + j;
		}
	}
	m = m;

	EXPECT_EQ(m, m1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TMatrix<int> m1(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m1[i][j] = (i + j) * 2;
		}
	}
	m = m1;

	EXPECT_EQ(m, m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TMatrix<int> m1(7);
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7 - i; j++)
		{
			m1[i][j] = (i + j) * 2;
		}
	}
	m = m1;

	EXPECT_EQ(m.GetSize(), m1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TMatrix<int> m1(7);
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7 - i; j++)
		{
			m1[i][j] = (i + j) * 2;
		}
	}
	m = m1;

	EXPECT_EQ(m, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TMatrix<int> m1(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m1[i][j] = i + j;
		}
	}
	EXPECT_EQ(m == m1, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	EXPECT_EQ(m == m, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TMatrix<int> m1(7);
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7 - i; j++)
		{
			m1[i][j] = (i + j) * 2;
		}
	}

	EXPECT_EQ(m != m1, true);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TMatrix<int> m1(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m1[i][j] = 2*(i + j);
		}
	}
	TMatrix<int> m2(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m2[i][j] = 3*(i + j);
		}
	}
	EXPECT_EQ(m + m1, m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TMatrix<int> m1(9);
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9 - i; j++)
		{
			m1[i][j] = 2*(i + j);
		}
	}
	
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TMatrix<int> m1(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m1[i][j] = 4*(i + j);
		}
	}
	TMatrix<int> m2(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m2[i][j] = 3*(i + j);
		}
	}
	EXPECT_EQ(m1 - m, m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> m(5);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 - i; j++)
		{
			m[i][j] = i + j;
		}
	}
	TMatrix<int> m1(9);
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9 - i; j++)
		{
			m1[i][j] = 2*(i + j);
		}
	}
	
	ASSERT_ANY_THROW(m - m1);
}

