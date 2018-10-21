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
	TVector <int> a(2);
	for (int i = 0; i < 2; i++)
	{
		a[i] = i;
	}
	TVector <int> a1 = a;
	EXPECT_EQ(a, a1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> a(2);
	for (int i = 0; i < 2; i++)
	{
		a[i] = i;
	}
	TVector<int> a1(a);
	for (int i = 0; i < 2; i++)
	{
		a1[i] -= i;
	}
	EXPECT_NE(a, a1);
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
	TVector <int> a(1);
	EXPECT_ANY_THROW(a[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector <int> a(1);
	EXPECT_ANY_THROW(a[2]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b = a;
	a = a;
	EXPECT_EQ(a, b);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(1);
	b[0] = 2;
	a = b;
	EXPECT_EQ(a, b);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector <int> a(2);
	a[0] = 1;
	TVector <int> b(1);
	b[0] = 2;
	a = b;
	EXPECT_EQ(a.GetSize(), b.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(1);
	b[0] = 2;
	a = b;
	EXPECT_EQ(a, b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(1);
	b[0] = 2;
	a = b;
	EXPECT_EQ((a == b), true);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector <int> a(1);
	a[0] = 1;
	EXPECT_EQ((a == a), true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(1);
	b[0] = 2;
	EXPECT_EQ((a == b), false);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(1);
	b[0] = 2;
	EXPECT_EQ(a + 1, b);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(1);
	b[0] = 2;
	EXPECT_EQ(a, b - 1);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(1);
	b[0] = 2;
	EXPECT_EQ(a * 2, b);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(1);
	b[0] = 2;
	TVector <int> c(1);
	c[0] = 3;
	EXPECT_EQ(a + b, c);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(2);
	b[0] = 2;
	EXPECT_ANY_THROW(a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(1);
	b[0] = 2;
	TVector <int> c(1);
	c[0] = 1;
	EXPECT_EQ(b - a, c);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector <int> a(1);
	a[0] = 1;
	TVector <int> b(2);
	b[0] = 2;
	EXPECT_ANY_THROW(a - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> a(1);
	a[0] = 1;
	TVector<int> b(1);
	b[0] = 3;
	EXPECT_EQ(a * b, 3);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> a(1);
	a[0] = 1;
	TVector<int> b(2);
	b[0] = 3;
	EXPECT_ANY_THROW(a*b);
}

