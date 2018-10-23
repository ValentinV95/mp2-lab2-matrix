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
	TVector<int> v1(5);
	TVector<int> v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<double> v1(3);
	TVector<double> v2 = v1;
	EXPECT_NE(&v1[0], &v2[0]);
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
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-1]);
}
TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[4]);
}
TEST(TVector, can_assign_vector_to_itself)
{
	TVector<char> v(2);
	v[0] = 'a'; v[1] = 'b';
	v = v;
	EXPECT_EQ('a', v[0]);
	EXPECT_EQ('b', v[1]);
}
TEST(TVector, can_assign_vectors_of_equal_size)
{
	const int s = 2;
	TVector<float> v1(s), v2(s);
	v1[0] = 123; v1[1] = 456;
	v2 = v1;
	EXPECT_EQ(123, v2[0]);
	EXPECT_EQ(456, v2[1]);
}
TEST(TVector, assign_operator_change_vector_size)
{
	const int s1 = 3, s2 = 14;
	TVector<double> v1(s1), v2(s2);
	v1 = v2;
	EXPECT_NE(s1, v1.GetSize());
}
TEST(TVector, can_assign_vectors_of_different_size)
{
	const int s1 = 2, s2 = 11;
	TVector<double> v1(s1), v2(s2);
	v1 = v2;
	EXPECT_EQ(v1, v2);
}
TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(9);
	TVector<int> v2(9);
	for (int i = 0; i < v2.GetSize(); i++) {
		v1[i] = v2[i] = i;
	}
	EXPECT_EQ(v1, v2);
}
TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<float> v(10);
	EXPECT_EQ(v, v);
}
TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<long int> v1(11);
	TVector<long int> v2(12);
	EXPECT_NE(v1, v2);
}
TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i * 2;
	}
	TVector<int> v1(4);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i * 2 + 10;
	}
	v = v + 10;
	EXPECT_EQ(v, v1);
}
TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(7), expVec(7);
	//v1 = (0 10 11 12 13 14 15)
	for (int i = 0; i < 7; i++) {
		v1[i] = i * 10;
	}
	//expVec = (-8 2 3 4 5 6 7)
	for (int i = 0; i < 7; i++) {
		expVec[i] = i * 10 - 8;
	}
	EXPECT_EQ(expVec, (v1 - 8));
}
TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(5), expVec(5);
	//v1 = (0 1 2 3 4)
	for (int i = 0; i < 5; i++) {
		v1[i] = i;
	}
	//expVec = (0 2 4 6 8)
	for (int i = 0; i < 5; i++) {
		expVec[i] = i * 2;
	}
	EXPECT_EQ(expVec, v1 * 2);
}
TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(3), v2(3), expVec(3);
	//v1 = (0 2 4)
	for (int i = 0; i < 3; i++) {
		v1[i] = i * 2;
	}
	//v2 = (0 8 16)
	for (int i = 0; i < 3; i++) {
		v2[i] = i * 8;
	}
	//expVec = (0 10 20)
	for (int i = 0; i < 3; i++) {
		expVec[i] = i * 10;
	}
	EXPECT_EQ(expVec, v1 + v2);
}
TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(9), v2(1);
	ASSERT_ANY_THROW(v1 + v2);
}
TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5), expVec(5);
	//v1 = (1 6 11 16 21)
	for (int i = 0; i < 5; i++) {
		v1[i] = i * 5 + 1;
	}
	//v2 = (10 10 10 10 10)
	for (int i = 0; i < 5; i++) {
		v2[i] = 10;
	}
	//expVec = (-9 -4 1 5 11)
	for (int i = 0; i < 5; i++) {
		expVec[i] = i * 5 - 9;
	}
	EXPECT_EQ(expVec, v1 - v2);
}
TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(4), v2(10);
	ASSERT_ANY_THROW(v1 - v2);
}
TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(3), v2(3);
	const int expRes = 64;
	//v1 = (0 2 4)
	for (int i = 0; i < 3; i++) {
		v1[i] = i * 2;
	}
	//v2 = (9 10 11)
	for (int i = 0; i < 3; i++) {
		v2[i] = i + 9;
	}
	EXPECT_EQ(expRes, v1 * v2);
}
TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(1), v2(7);
	ASSERT_ANY_THROW(v1 * v2);
}

