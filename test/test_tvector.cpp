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
	TVector<int> v(10);
	TVector<int> vect(v);

	EXPECT_EQ(1, vect == v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(3);
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;
  TVector<int> vect = v;
  v[0] = 2;
  EXPECT_NE(v, vect);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(2);

	ASSERT_ANY_THROW(v[-1] = 4);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(10);

	ASSERT_ANY_THROW(v[11] = 4);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(2);
	v[0] = 1; v[1] = 2;
	TVector<int> v1(v);
	v = v;
	EXPECT_EQ(v, v1);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(2), v2(2);
	v1[0] = 1; v1[1] = 2; v2[0] = 2; v2[1] = 3;
	v1 = v2;
	EXPECT_EQ(2, v1[0]);
	EXPECT_EQ(3, v1[1]);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(2), v2(3);
	v1 = v2;
	EXPECT_NE(2, v1.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(2), v2(3);
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector <int> v1(3);
	TVector <int> v2(3);

	for (int i = v1.GetStartIndex(); i < v1.GetSize(); i++) {
		v1[i] = i;
		v2[i] = i;
	}

	EXPECT_EQ(1, v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector <int> v1(2);

	EXPECT_EQ(1, v1 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(4);
	TVector<int> v2(2);

	EXPECT_EQ(0, v1 == v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(2);
	v1[0] = 0; v1[1] = 0;
	TVector<int> v2(2);
	v2 = v1 + 5;
	
	EXPECT_EQ(5, v2[1]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(2);
	v1[0] = 0; v1[1] = 0;
	TVector<int> v2(2);
	v2 = v1 - 5;

	EXPECT_EQ(-5, v2[1]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++) {
		v1[i] = 2;
	}
	TVector<int> v2 = v1 * 4;

	EXPECT_EQ(8, v2[1]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5), v3(5);
	
	for (int i = 0; i < 5; i++) {
		v1[i] = i;
	}
	
	for (int i = 0; i < 5; i++) {
		v2[i] = i * 2;
	}
	
	for (int i = 0; i < 5; i++) {
		v3[i] = i * 3;
	}
	EXPECT_EQ(v3, v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(4), v2(5), v3(5);

	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5), v3(5);
	// 0 1 2 3 4
	for (int i = 0; i < 5; i++) {
		v1[i] = i;
	}
	// 0 2 4 6 8
	for (int i = 0; i < 5; i++) {
		v2[i] = i * 2;
	}
	// 0 -1 -2 -3 -4
	for (int i = 0; i < 5; i++) {
		v3[i] = i * (-1);
	}
	EXPECT_EQ(v3, v1 - v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(4), v2(5), v3(5);

	ASSERT_ANY_THROW(v1 - v2);;
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(3), v2(3);
	// 0 1 2
	for (int i = 0; i < 3; i++) {
		v1[i] = i;
	}
	// 0 2 4
	for (int i = 0; i < 3; i++) {
		v2[i] = i * 2;
	}

	EXPECT_EQ(10, v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(4), v2(5), v3(5);

	ASSERT_ANY_THROW(v1 * v2);
}

