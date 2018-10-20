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
  TVector <int> v(10);
  for(int i=0; i<10;i+=2)
	  v[i]=3;
  
  TVector<int> k(v);

 

  EXPECT_EQ(k, v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(10);
  for(int i=0; i<10;i+=2)
	  v[i]=3;
  TVector<int> k(v);
  v[1]=21;

  EXPECT_NE(k, v);
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
  ASSERT_ANY_THROW(v[-4]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> v(4);
  ASSERT_ANY_THROW( v [5]);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> v(10);
  for(int i=0; i<10;i+=2)
	  v[i]=3;
  TVector<int> k(10);
   for(int i=0; i<10;i+=2)
	  k[i]=3;
  v=v;
  EXPECT_EQ(v, k);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> v(10);
  for(int i=0; i<10;i+=2)
	  v[i]=3;

  TVector<int> k(10);
  for(int i=1; i<10;i+=2)
	  k[i]=3;

  v=k;
  EXPECT_EQ(v, k);


}

TEST(TVector, assign_operator_change_vector_size)
{
  TVector<int> v(10);
 
  TVector<int> k(5);

  v=k;

  EXPECT_EQ(5, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> v(10);
  for(int i=0; i<10;i+=2)
	  v[i]=3;

  TVector<int> k(20);
  for(int i=1; i<20;i+=2)
	  k[i]=3;

  v=k;
  EXPECT_EQ(v, k);
}

TEST(TVector, compare_equal_vectors_return_true)
{
   TVector<int> v(10);
  for(int i=0; i<10;i+=2)
	  v[i]=3;

  TVector<int> k(10);
  for(int i=0; i<10;i+=2)
	  k[i]=3;

  EXPECT_EQ(v == k, true);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
   TVector<int> v(10);
  for(int i=0; i<10;i+=2)
	  v[i]=3;
   EXPECT_EQ(v == v, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{

	TVector<int> v(10);
	TVector<int> k(5);

	EXPECT_NE(k, v);
}

TEST(TVector, can_add_scalar_to_vector)
{
   TVector<int> v(10);
    for(int i=0; i<10;i++)
	  v[i]=2;

   TVector<int> k(10);
   for(int i=0; i<10;i++)
	  k[i]=1;

    k=k+1;

    EXPECT_EQ(v, k);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> v(10);
   for(int i=0; i<10;i++)
	  v[i]=2;

   TVector<int> k(10);
   for(int i=0; i<10;i++)
	  k[i]=1;

    v=v-1;

    EXPECT_EQ(v, k);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
   TVector<int> k(10);
   for(int i=0; i<10;i++)
	  k[i]=1;

   TVector<int> v(k);

   v = v+1;
   k = k*2;

   EXPECT_EQ(v, k);
}

TEST(TVector, can_add_vectors_with_equal_size)
{

	TVector<int> k(10);
	for(int i=0; i<10;i++)
		k[i]=1;
	TVector<int> v(10);
	for(int i=0; i<10;i++)
		v[i]=2;


	EXPECT_EQ(v, k + k);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> k(10);
	TVector<int> v(5);
	
	
	ASSERT_ANY_THROW( v+k);

}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> k(10);
	for(int i=0; i<10;i++)
		k[i]=1;
	TVector<int> v(10);
	for(int i=0; i<10;i++)
		v[i]=2;


	EXPECT_EQ(v - k, k);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> k(10);
	TVector<int> v(5);


	ASSERT_ANY_THROW( v-k);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> k(10);
	for(int i=0; i<10;i++)
		k[i]=1;
	TVector<int> v(k); 

	EXPECT_EQ(10, v*k);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> k(10);
	TVector<int> v(5);


	ASSERT_ANY_THROW( v*k);
}

