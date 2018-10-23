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
	TMatrix<int> a(3);
	
	TMatrix<int> b=a;
	EXPECT_EQ(a, b);


}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int>a(3);
	TMatrix<int>b(a);
	
	b[1][2] = 1;
	
	EXPECT_NE(a, b);

}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);

	EXPECT_EQ(4, v.GetSize());
  
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(4);
	v[1][2] = 8;
	EXPECT_EQ(8, v[1][2]);

}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[-3][2]);

}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[10000000000000][2]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(v);
	v = v;
	EXPECT_EQ(v,v1);


}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(v);
	v = v1;
	EXPECT_EQ(v,v1);

}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> v(4),v1(8);
	v = v1;

	EXPECT_EQ(8, v1.GetSize());

}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> v(4), v1(8);
	v = v1;

	EXPECT_EQ(v,v1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> v(4), v1(v);
	EXPECT_EQ(v==v1, true);

}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> v(4);
	EXPECT_EQ(v == v, true);

}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> v(4), v1(5);
	EXPECT_EQ(v != v1, true);

}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> v(2), v1(2),rez(2);

	v[0][0] = 1;
	v[0][1] = 1;
	v[1][1] = 1;
	v1[0][0] = 2;
	v1[0][1] = 1;
	v1[1][1] = 1;
	rez[0][0] = 3;
	rez[0][1] = 2;
	rez[1][1] = 2;
	EXPECT_EQ((v+v1), rez);
	

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> v(2), v1(7);
	ASSERT_ANY_THROW(v+v1);

	
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> v(2), v1(2), rez(2);

	v[0][0] = 3;
	v[0][1] = 3;
	v[1][1] = 3;
	v1[0][0] = 2;
	v1[0][1] = 1;
	v1[1][1] = 1;
	rez[0][0] = 1;
	rez[0][1] = 2;
	rez[1][1] = 2;
	EXPECT_EQ((v - v1), rez);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> v(2), v1(7);
	ASSERT_ANY_THROW(v - v1);
}

