#include "MStack.h"
#include <gtest.h>

TEST(MStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(MStack<int> A(43, 2));
}

TEST(MStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(MStack<int> A(-43, 3));
}

TEST(MStack, can_create_copied_stack)
{
	MStack<int> A(43, 3);
	ASSERT_NO_THROW(MStack<int> B(A));
}

TEST(MStack, check_full_stack)
{
	MStack<int> A(1, 1);
	A.Put(1, 1);
	EXPECT_EQ(1, A.IsFull());
}

TEST(MStack, check_empty_stack)
{
	MStack<int> A(43, 5);
	EXPECT_EQ(1, A.IsEmpty());
}

TEST(MStack, cant_put_element_in_full_stack)
{
	MStack<int> A(4, 2);
	A.Put(1, 1);
	A.Put(2, 1);
	A.Put(3, 2);
	A.Put(4, 2);
	ASSERT_ANY_THROW(A.Put(5, 1));
}

TEST(MStack, cant_get_element_in_empty_stack)
{
	MStack<int> A(4, 2);
	ASSERT_ANY_THROW(A.Get(1));
}

TEST(MStack, can_put_and_get_element)
{
	MStack<int> A(4, 2);
	A.Put(1, 1);
	A.Put(2, 1);
	A.Put(3, 1);
	EXPECT_EQ(3, A.Get(1));
}
