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
	TVector <int> v1(4);
	v1[1] = 7;
	TVector<int> v2(v1);
	EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(7);
	TVector<int> v2(v1);
	v1[5] = 10;
	EXPECT_NE(v1[5], v2[5]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(7);
  EXPECT_EQ(7, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v1(7, 3);
  EXPECT_EQ(3, v1.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v1(4);
  v1[0] = 4;
  EXPECT_EQ(4, v1[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(1);
	ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v1(1);
	ASSERT_ANY_THROW(v1[2]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v1(1);
	v1[0] = 10;
	TVector<int> v2(v1);
	EXPECT_EQ(v1, v2);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(1);
	v1[0] = 10;
	TVector<int> v2(1);
	v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(1), v2(5);
	v = v2;
	EXPECT_EQ(5, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(5), v2(7);
	v1[1] = 9;
	v2[3] = 10;
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(5), v2(5);
	EXPECT_EQ(true, v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v1(5);
	EXPECT_EQ(true, v1 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(1), v2(3);
	EXPECT_EQ(true, v1 != v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(1), v2(1);
	v1 = v1 + 1;
	v2[0] = 1;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(1), v2(1);
	v1 = v1 - 1;
	v2[0] = -1;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(1), v2(1);
	v1 = v1 + 1;
	v1 = v1 * 7;
	v2[0] = 7;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(3), v2(3), v3(3);
	v3[1] = 7;
	v1[1] = 3;
	v2[1] = 4;
	v2 = v2 + v1;
	EXPECT_EQ(v3, v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(7), v2(17);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(3), v2(3), v3(3);
	v3[1] = 7;
	v1[1] = 3;
	v2[1] = 10;
	v2 = v2 - v1;
	EXPECT_EQ(v3, v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(7), v2(17);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(3), v2(3), v3(3);
    v3[1] = 6;
	v1[1] = 2;
	v2[1] = 3;
	v2 = v2 * v1;
	EXPECT_EQ(v3, v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(5), v2(7);
	ASSERT_ANY_THROW(v1 * v2);
}

