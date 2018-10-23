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

	TMatrix<int> mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;//operator[]
	TMatrix<int> mt2(mt1);
	EXPECT_EQ(mt1, mt2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{

	TMatrix<int> mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;//operator[]
	TVector<TVector<int>> mt2(mt1);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt2[i][j] = i + j + 1;//operator[]
	EXPECT_NE(mt1, mt2);
}

TEST(TMatrix, can_get_size)
{

	TMatrix<int>mt(4);

	EXPECT_EQ(4, mt.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> mt(4);
	mt[0][1] = 4;

	EXPECT_EQ(4, mt[0][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> mt(4);
	ASSERT_ANY_THROW(mt[-2][-1] = 2);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> mt(4);
	ASSERT_ANY_THROW(mt[5][6] = 2);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;
	TMatrix<int> mt2(mt1);
	EXPECT_EQ(mt2, mt1 = mt1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int>mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;
	TMatrix<int> mt2(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt2[i][j] = i + j + 1;
	mt2 = mt1;
	EXPECT_EQ(mt2, mt1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;
	TMatrix<int> mt2(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt2[i][j] = i + j + 1;
	mt2 = mt1;
	EXPECT_EQ(mt2.GetSize(), mt1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int>mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;
	TMatrix<int> mt2(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j<5 - i; j++)
			mt2[i][j] = i + j + 1;
	mt2 = mt1;
	EXPECT_EQ(mt2, mt1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{

	TMatrix<int> mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;
	TMatrix<int>  mt2(mt1);
	EXPECT_EQ(mt2 == mt1, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;
	EXPECT_EQ(mt1 == mt1, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;
	TMatrix<int> mt2(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j<5 - i; j++)
			mt2[i][j] = i + j;

	EXPECT_NE(mt2, mt1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;
	TMatrix<int> mt2(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt2[i][j] = i + j + 1;
	TMatrix<int> mt3(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt3[i][j] = 2 * i + 2 * j + 1;
	EXPECT_EQ(mt3, mt1 + mt2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;
	TMatrix<int> mt2(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j<5 - i; j++)
			mt2[i][j] = i + j;
	ASSERT_ANY_THROW(mt1 + mt2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{


	TMatrix<int> mt1(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt1[i][j] = i + j;
	TMatrix<int> mt2(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt2[i][j] = i + j + 1;
	TMatrix<int> mt3(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt3[i][j] = 1;
	EXPECT_EQ(mt3, mt2 - mt1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> mt1(5);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j<5 - i; j++)
			mt1[i][j] = i + j;
	TMatrix<int> mt2(10);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j<10 - i; j++)
			mt2[i][j] = i + j + 1;
	ASSERT_ANY_THROW(mt2 - mt1);
}

