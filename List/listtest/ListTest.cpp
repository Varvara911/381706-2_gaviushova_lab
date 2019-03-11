#include "List.h"
#include <gtest.h>


TEST(List, can_create_list)
{
  ASSERT_NO_THROW(List<int> list);
}

TEST(List, can_add_item)
{
  List<int> list;
  ASSERT_NO_THROW(list.Add(2));
}

//TEST(List, can_get_item)
//{
//  List<int> a;
//  List<int> list;
//  list.Add(2);
//
//  a = list[0];
//  EXPECT_EQ(a, 2);
//}

TEST(List, can_insert_item)
{
  List<int> list;
  list.Add(3);
  list.Add(1);
  ASSERT_NO_THROW(list.Insert(1, 2));
}
//TEST(List, can_get_inserted_item)
//{
//  List<int> a;
//  List<int> list;
//  list.Add(3);
//  list.Add(1);
//  list.Insert(0, 2);
//
//  a = list[1];
//  EXPECT_EQ(a, 2);
//}


TEST(List, throws_when_get_elemnt_with_negative_index)
{
  List<int> list;
  list.Add(3);
  list.Add(1);

  ASSERT_ANY_THROW(list[-1]);
}

TEST(List, throws_when_get_elemnt_with_too_large_index)
{
  List<int> list;
  list.Add(3);
  list.Add(1);

  ASSERT_ANY_THROW(list[5]);
}

