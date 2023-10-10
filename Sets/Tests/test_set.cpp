#include <gtest.h>
#include <climits>
#include "set.h"

TEST(TSet, can_combine_two_sets_of_equal_size)
{
  const int size = 5;
  TSet set1(size), set2(size), set3(size), expSet(size);
  // set1 = {1, 2, 4}
  set1.insert(1);
  set1.insert(2);
  set1.insert(4);
  // set2 = {0, 1, 2}
  set2.insert(0);
  set2.insert(1);
  set2.insert(2);
  set3 = set1 + set2;
  // expSet = {0, 1, 2, 4}
  expSet.insert(0);
  expSet.insert(1);
  expSet.insert(2);
  expSet.insert(4);

  EXPECT_EQ(expSet, set3);
}

TEST(TSet, check_negation_operator)
{
  const int size = 4;
  TSet set(size), set1(size), expSet(size);
  // set1 = {1, 3}
  set.insert(1);
  set.insert(3);
  set1 = ~set;
  // expSet = {0, 2}
  expSet.insert(0);
  expSet.insert(2);

  EXPECT_EQ(expSet, set1);
}
