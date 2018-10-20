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
	TMatrix<int> m(4);
	m[0][1]=1;
	m[0][2]=1;
	

	TMatrix<int> d(m);
	EXPECT_EQ(m, d);

}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
TMatrix<int> m(4);
	m[0][1]=1;
	m[0][2]=1;
	

	TMatrix<int> d(m);
	
	d[1][2]=13;

	EXPECT_NE(m, d);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(4);
 	EXPECT_EQ(4, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
   TMatrix<int> m(4);
	m[0][1]=1;

	EXPECT_EQ(1, m[0][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[-1][3]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[2][5]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	TMatrix<int> d(m);
	m = m;
	EXPECT_EQ(m,d);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> m(4);
	m[0][1]=1;
	m[0][2]=1;
	
	TMatrix<int> d(m);
	d[1][2]=13;

	m=d;
	EXPECT_EQ(m,d);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(4);
	TMatrix<int> d(3);
	m=d;
	EXPECT_EQ(m.GetSize(), d.GetSize());

}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(4);
	m[0][1]=1;
	m[0][2]=1;
	

	TMatrix<int> d(3);
	d[1][1]=13;

	m=d;

	EXPECT_EQ(m,d);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> m(4);
	m[0][1]=1;
	m[0][2]=1;
	

	TMatrix<int> d(m);
	EXPECT_EQ(m == d, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> m(4);
	m[0][1]=1;
    m[0][2]=1;
	m[0][3]=1;
	EXPECT_EQ(m == m, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> m(4);
	m[0][1]=1;
	m[0][2]=1;
	

	TMatrix<int> d(3);
	d[1][1]=13;

	EXPECT_NE(m,d);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(2);
	m[0][0] = 3;
	m[0][1] = 1;
	m[1][1] = 19;

 	TMatrix<int> d(2);
	d[0][0] = 11;
	d[0][1] = -2;
	d[1][1] = 2;

 	TMatrix<int> res(2);
	res[0][0] = 14;
	res[0][1] = -1;
	res[1][1] = 21;
 	EXPECT_EQ(m + d, res);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(3);
	
	TMatrix<int> d(2);
	
	ASSERT_ANY_THROW(m+d);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix<int> m(2);
	m[0][0] = 3;
	m[0][1] = 1;
	m[1][1] = 19;

 	TMatrix<int> d(2);
	d[0][0] = 11;
	d[0][1] = -2;
	d[1][1] = 2;

 	TMatrix<int> res(2);
	res[0][0] = 14;
	res[0][1] = -1;
	res[1][1] = 21;
 	EXPECT_EQ(res - d, m);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(3);	

	TMatrix<int> d(2);
	

	ASSERT_ANY_THROW(m-d);
}

