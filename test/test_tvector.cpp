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
	TVector <int> v(5), w(5);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		w[i] = v[i];
	}
	EXPECT_EQ(v, w);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector <int> v(5), w(5);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		w[i] = v[i];
	}
	EXPECT_NE(&v[0], &w[0]);
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
	TVector <int> b(5);
	ASSERT_ANY_THROW(b[-1] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector <int> v(5);
	ASSERT_ANY_THROW(v[7] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector <int> v(5);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
	}
	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector <int> v(5), w(5);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
	}
	v = w;
	EXPECT_EQ(v, w);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector <int> v(3), w(5);
	v = w;
	EXPECT_EQ(v.GetSize(), w.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(5), w(3);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = i + 1;

	ASSERT_NO_THROW(w = v);

}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector <int> v(5);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
	}
	TVector <int> w = v;
	EXPECT_EQ(1, v == w);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector <int> v(5);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
	}
	EXPECT_EQ(1, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector <int> v(3), w(5);
	EXPECT_EQ(0, v == w);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector <int> v(5), w(5);
	int x = 3;
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		w[i] = v[i] + 3;
	}
	EXPECT_EQ(w, v + 3);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector <int> v(5), w(5);
	int x = 3;
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		w[i] = v[i] - 3;
	}
	EXPECT_EQ(w, v - 3);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector <int> v(5), w(5);
	int x = 3;
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		w[i] = v[i] * 3;
	}
	EXPECT_EQ(w, v * 3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector <int> v(5), w(5), res(5);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		w[i] = i;
		res[i] = v[i] + w[i];
	}
	EXPECT_EQ(res, v + w);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector <int> v(3), w(5);
	ASSERT_ANY_THROW(v + w);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector <int> v(5), w(5), res(5);
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		w[i] = i;
		res[i] = v[i] - w[i];
	}
	EXPECT_EQ(res, v - w);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector <int> v(3), w(5);
	ASSERT_ANY_THROW(v - w);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector <int> v(5), w(5);
	int res = 0;
	for (int i = 0; i < v.GetSize(); i++)
	{
		v[i] = i;
		w[i] = i;
		res += v[i] * w[i];
	}
	EXPECT_EQ(res, v * w);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector <int> v(5), w(10);
	ASSERT_ANY_THROW(v * w);
}
