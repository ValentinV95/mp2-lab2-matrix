#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(5,1);
	v[1] = 1;
	v[4] = 4;

	TVector<int> v1(v);

	EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(5,1);
	TVector<int> v1(v);

	EXPECT_NE( &v[v.GetStartIndex()], &v1[v1.GetStartIndex()]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4,1);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4,1);

  EXPECT_EQ(1, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4,1);
  v[1] = 4;

  EXPECT_EQ(4, v[1]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v;

	ASSERT_ANY_THROW(v[-9] = 6);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v;

	ASSERT_ANY_THROW(v[10] = 6);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4,1);
	v[1] = 1;
	v[2] = 2;
	v[3] = 3;
	v[4] = 4;

	TVector<int> expV(v);

	v = v;

	EXPECT_EQ(expV , v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(4,1);
	v[1] = 1;
	v[2] = 2;
	v[3] = 3;
	v[4] = 4;

	TVector<int> v1(4,1);
	v1[1] = 4;
	v1[2] = 3;
	v1[3] = 2;
	v1[4] = 1;

	v1 = v;
	
	EXPECT_EQ(v, v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(2,1);
	TVector<int> v1(5,1);

	v1 = v;

	EXPECT_EQ(v.GetSize(), v1.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(5,1);
	v[1] = 1;
	v[5] = 5;

	TVector<int> v1(4,1);
	v1[2] = 2;
	v1[3] = 3;
	v1[4] = 4;

	v1 = v;

	EXPECT_EQ(v, v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(3,1);
	v[2] = 2;

	TVector<int> v1(v);

	EXPECT_EQ(true, v==v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(3,1);
	v[2] = 2;

	EXPECT_EQ(true, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(3,1);
	v[2] = 2;

	TVector<int> v1(5,1);
	v1[2] = 2;

	EXPECT_EQ(true, v != v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(3,1);
	v[1] = 1;
	v[2] = 1;
	v[3] = 1;

	TVector<int> expV(4);
	expV[0] = 2;
	expV[1] = 3;
	expV[2] = 3;
	expV[3] = 3;
	
	EXPECT_EQ(expV, v+2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(3,1);
	v[1] = 1;
	v[2] = 1;
	v[3] = 1;

	TVector<int> expV(4);
	expV[0] = -2;
	expV[1] = -1;
	expV[2] = -1;
	expV[3] = -1;

	EXPECT_EQ(expV, v - 2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> expV(3,1);
	expV[1] = 3;
	expV[2] = 3;
	expV[3] = 3;

	TVector<int> v(3,1);
	v[1] = 1;
	v[2] = 1;
	v[3] = 1;

	EXPECT_EQ(expV, v*3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(4,1);
	v[1] = 1;
	v[2] = 2;
	v[3] = 3;
	v[4] = 4;

	TVector<int> v1(4,1);
	v1[1] = 4;
	v1[2] = 3;
	v1[3] = 2;
	v1[4] = 1;

	TVector<int> expV(4,1);
	expV[1] = 5;
	expV[2] = 5;
	expV[3] = 5;
	expV[4] = 5;

	EXPECT_EQ(expV, v+v1);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(4,1);
	TVector<int> v1(2,1); 

	ASSERT_ANY_THROW(v+v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(4,1);
	v[1] = 5;
	v[2] = 5;
	v[3] = 5;
	v[4] = 5;

	TVector<int> v1(4,1);
	v1[1] = 4;
	v1[2] = 3;
	v1[3] = 2;
	v1[4] = 1;

	TVector<int> expV(4,1);
	expV[1] = 1;
	expV[2] = 2;
	expV[3] = 3;
	expV[4] = 4;

	EXPECT_EQ(expV, v - v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(4,1);
	TVector<int> v1(2,1);

	ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(4,1);
	v[1] = 1;
	v[2] = 2;
	v[3] = 3;
	v[4] = 4;

	TVector<int> v1(4,1);
	v1[1] = 8;
	v1[2] = 1;
	v1[3] = 2;
	v1[4] = 1;

	int exp = 20;

	EXPECT_EQ(exp, v*v1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	TVector<int> v1(2);

	ASSERT_ANY_THROW(v * v1);
}

