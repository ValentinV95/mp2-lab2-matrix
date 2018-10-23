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
	TVector<int> a(2);
	a[0] = 1;
	a[1] = 2;
	TVector<int> b = a;
	EXPECT_EQ(a,b);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> a(2);
	a[0] = 1;
	a[1] = 2;

	TVector<int> b(4);
	b[0] = 2;
	b[1] = 2;
	b[2] = 2;
	b[3] = 2;
	a = b;
	b[0] = 6;
	EXPECT_NE(a, b);
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
	ASSERT_ANY_THROW(v[-3]);

}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[109999999]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	TVector<int> v1(v);
	v = v;
	EXPECT_EQ(v, v1);

}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(4);
	TVector<int> v1(4);
	v = v1;
	EXPECT_EQ(v, v1);

}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(4);
 
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;
	TVector<int> v1(4);

	EXPECT_EQ(v.GetSize(), v1.GetSize());

}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;

	TVector<int> v1(7);
	for (int i = 0; i < v1.GetSize(); i++)
		v1[i] = 1;
	v = v1;
	EXPECT_EQ(v, v1);

}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;
	TVector<int> v1(v);

	EXPECT_EQ(v==v1, true);

}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;

	EXPECT_EQ(v == v, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;
	TVector<int> v1(8);

	EXPECT_EQ(v != v1, true);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;
	TVector<int> rez(4);
	for (int i = 0; i < rez.GetSize(); i++)
		rez[i] = 2;
	v = v + 1;
	EXPECT_EQ(v, rez);

}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 2;
	TVector<int> rez(4);
	for (int i = 0; i < rez.GetSize(); i++)
		rez[i] = 1;
	v = v - 1;
	EXPECT_EQ(v, rez);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;
	TVector<int> rez(4);
	for (int i = 0; i < rez.GetSize(); i++)
		rez[i] = 2;
	v = v*2;
	EXPECT_EQ(v, rez);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;
	TVector<int> v1(4);
	for (int i = 0; i < v1.GetSize(); i++)
		v1[i] = 1;
	TVector<int> r(4);
	for (int i = 0; i < r.GetSize(); i++)
		r[i] = 2;
	EXPECT_EQ(v+v1, r);

}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;
	TVector<int> v1(6);
	for (int i = 0; i < v1.GetSize(); i++)
		v1[i] = 1;
	ASSERT_ANY_THROW(v+v1);

	
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(3);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 3;
	TVector<int> v1(3);
	for (int i = 0; i < v1.GetSize(); i++)
		v1[i] = 1;
	TVector<int> r(3);
	r[0] = 2;
	r[1] = 2;
	r[2] = 2;
	EXPECT_EQ(v - v1, r);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;
	TVector<int> v1(6);
	for (int i = 0; i < v1.GetSize(); i++)
		v1[i] = 1;
	ASSERT_ANY_THROW(v - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 3;
	TVector<int> v1(4);
	for (int i = 0; i < v1.GetSize(); i++)
		v1[i] = 2;
	int S = 24;
	EXPECT_EQ(v * v1, S);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = 1;
	TVector<int> v1(6);
	for (int i = 0; i < v1.GetSize(); i++)
		v1[i] = 1;
	ASSERT_ANY_THROW(v * v1);
}

