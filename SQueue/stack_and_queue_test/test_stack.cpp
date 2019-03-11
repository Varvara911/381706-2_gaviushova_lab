#include "gtest.h"
#include "Stack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> A(43));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> A(-43));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> A(43);
  ASSERT_NO_THROW(TStack<int> B(A));
}

TEST(TStack, check_full_stack)
{
  TStack<int> A(1);
  A.Put(1);
  EXPECT_EQ(1, A.IsFull());
}

TEST(TStack, check_empty_stack)
{
  TStack<int> A(43);
  EXPECT_EQ(1, A.IsEmpty());
}

TEST(TStack, cant_put_element_in_full_stack)
{
  TStack<int> A(4);
  A.Put(1);
  A.Put(2);
  A.Put(3);
  A.Put(4);
  ASSERT_ANY_THROW(A.Put(5));
}

TEST(TStack, cant_get_element_in_empty_stack)
{
  TStack<int> A(4);
  ASSERT_ANY_THROW(A.Get());
}

TEST(TStack, can_put_and_get_element)
{
  TStack<int> A(4);
  A.Put(1);
  A.Put(2);
  A.Put(3);
  EXPECT_EQ(3, A.Get());
}
