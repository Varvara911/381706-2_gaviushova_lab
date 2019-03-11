#include <gtest.h>
#include "arrlist.h"

TEST(ArrList, can_create_list_with_size)
{
  ASSERT_NO_THROW(TArrList <int> list(7));
}

TEST(ArrList, can_create_list_without_size)
{
  ASSERT_NO_THROW(TArrList <int> list());
}

TEST(ArrList, can_create_copy_of_list)
{
  TArrList <int> list(7);

  ASSERT_NO_THROW(TArrList <int> copyList(list));
}

TEST(ArrList, can_create_copy_of_empty_list)
{
  TArrList <int> list(1);
  list.PushStart(1);
  TArrList <int> copyList(list);
  ASSERT_EQ(list.PopStart(), copyList.PopStart());
}

TEST(ArrList, can_get_in_start)
{
  TArrList <int> list(2);
  list.PushStart(5);
  list.PushStart(7);
  ASSERT_EQ(7, list.PopStart());
}

TEST(ArrList, can_put_in_start)
{
  TArrList <int> L(2);
  L.PushStart(5);
  L.PushStart(7);
  ASSERT_EQ(7, L.PopStart());
}

TEST(ArrList, throws_when_create_list_with_negative_size)
{
  ASSERT_ANY_THROW(TArrList <int> list(-1));
}

TEST(ArrList, can_put_and_get_end)
{
  TArrList <int> list(2);
  list.PushEnd(5);
  list.PushEnd(7);
  ASSERT_EQ(7, list.PopEnd());
  ASSERT_EQ(5, list.PopEnd());
}

TEST(ArrList, function_isfull_works)
{
  TArrList <int> list(1);
  list.PushStart(5);
  ASSERT_TRUE(list.IsFull());
}

TEST(ArrList, can_use_empty_check_false)
{
  TArrList <int> list(1);
  list.PushStart(5);
  ASSERT_FALSE(list.IsEmpty());
}

TEST(ArrList, can_use_empty_check_true)
{
  TArrList <int> list(1);
  ASSERT_TRUE(list.IsEmpty());
}

TEST(ArrList, throws_when_put_in_full_list_in_start)
{
  TArrList <int> list(1);
  list.PushStart(1);
  ASSERT_ANY_THROW(list.PushStart(2));
}

TEST(ArrList, throws_when_put_in_full_list_in_finish)
{
  TArrList <int> list(1);
  list.PushStart(1);
  ASSERT_ANY_THROW(list.PushEnd(2));
}

TEST(ArrList, throws_when_get_in_empty_list_in_start)
{
  TArrList <int> list(1);
  ASSERT_ANY_THROW(list.PopStart());
}

TEST(ArrList, throws_when_in_empty_list_get__in_end)
{
  TArrList <int> list(1);
  ASSERT_ANY_THROW(list.PopEnd());
}

TEST(ArrList, throws_when_get_in_empty_list)
{
  TArrList <int> list(9);
  ASSERT_ANY_THROW(list.Pop(3));
}

TEST(ArrList, throws_when_put_in_full_list)
{
  TArrList <int> list(3);  	
  list.PushEnd(1);  
  list.PushEnd(1);
  list.PushEnd(1);
  ASSERT_ANY_THROW(list.Push(1, 6));
}

TEST(ArrList, throws_when_incurrent_index_when_put)
{
  TArrList <int> list(4);
  list.PushEnd(1);
  list.PushEnd(1);
  list.PushEnd(1);
  ASSERT_ANY_THROW(list.Push(10, 6));
}

TEST(ArrList, can_get_elem)
{
	TArrList <int> list(3);
	list.PushEnd(1);
	list.PushEnd(2);
	list.PushEnd(3);

	ASSERT_EQ(list.Pop(1), 2);
}

TEST(ArrList, can_put_elem)
{
  TArrList <int> list(4);
  list.PushEnd(1);
  list.PushEnd(2);
  list.PushEnd(3);
  list.Push(2, 10);

  ASSERT_EQ(list.Pop(1), 2);
  ASSERT_EQ(list.Pop(1), 10);
}
