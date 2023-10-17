#include "gtest.h"
#include <climits>
#include "set.h"
TEST(TSet, can_get_max_power_set) {
    TSet set(10);
    ASSERT_EQ(set.GetMaxPower(), 10);
}

TEST(TSet, can_insert_non_existing_element) {
    TSet set(10);
    set.InsElem(3);
    ASSERT_TRUE(set.IsMember(3));
}

TEST(TSet, can_insert_existing_element) {
    TSet set(10);
    set.InsElem(3);
    set.InsElem(3);
    ASSERT_TRUE(set.IsMember(3));
}

TEST(TSet, can_delete_non_existing_element) {
    TSet set(10);
    set.DelElem(3);
    ASSERT_FALSE(set.IsMember(3));
}

TEST(TSet, can_delete_existing_element) {
    TSet set(10);
    set.InsElem(3);
    set.DelElem(3);
    ASSERT_FALSE(set.IsMember(3));
}

TEST(TSet, compare_two_sets_of_non_equal_sizes) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(5);
    set2.InsElem(3);
    ASSERT_FALSE(set1 == set2);
    ASSERT_TRUE(set1 != set2);
}

TEST(TSet, compare_two_equal_sets) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(10);
    set2.InsElem(3);
    ASSERT_TRUE(set1 == set2);
    ASSERT_FALSE(set1 != set2);
}

TEST(TSet, compare_two_non_equal_sets) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(10);
    set2.InsElem(5);
    ASSERT_FALSE(set1 == set2);
    ASSERT_TRUE(set1 != set2);
}

TEST(TSet, can_assign_set_of_equal_size) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(10);
    set2 = set1;
    ASSERT_TRUE(set2.IsMember(3));
}

TEST(TSet, can_assign_set_of_greater_size) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(5);
    set2 = set1;
    ASSERT_TRUE(set2.IsMember(3));
}

TEST(TSet, can_assign_set_of_less_size) {
    TSet set1(5);
    set1.InsElem(3);
    TSet set2(10);
    set2 = set1;
    ASSERT_TRUE(set2.IsMember(3));
}

TEST(TSet, can_insert_non_existing_element_using_plus_operator) {
    TSet set(10);
    TSet result = set + 3;
    ASSERT_TRUE(result.IsMember(3));
}

TEST(TSet, throws_when_insert_non_existing_element_out_of_range_using_plus_operator) {
    TSet set(10);
    ASSERT_THROW(set + 12, std::out_of_range);
}

TEST(TSet, can_insert_existing_element_using_plus_operator) {
    TSet set(10);
    set.InsElem(3);
    TSet result = set + 3;
    ASSERT_TRUE(result.IsMember(3));
}

TEST(TSet, check_size_of_the_combination_of_two_sets_of_equal_size) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(10);
    set2.InsElem(5);
    TSet result = set1 + set2;
    ASSERT_EQ(result.GetMaxPower(), 10);
}

TEST(TSet, can_combine_two_sets_of_equal_size) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(10);
    set2.InsElem(5);
    TSet result = set1 + set2;
    ASSERT_TRUE(result.IsMember(3));
    ASSERT_TRUE(result.IsMember(5));
}

TEST(TSet, check_size_changes_of_the_combination_of_two_sets_of_non_equal_size) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(5);
    set2.InsElem(5);
    TSet result = set1 + set2;
    ASSERT_EQ(result.GetMaxPower(), 10);
}

TEST(TSet, can_combine_two_sets_of_non_equal_size) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(5);
    set2.InsElem(5);
    TSet result = set1 + set2;
    ASSERT_TRUE(result.IsMember(3));
    ASSERT_TRUE(result.IsMember(5));
}

TEST(TSet, can_intersect_two_sets_of_equal_size) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(10);
    set2.InsElem(3);
    TSet result = set1 * set2;
    ASSERT_TRUE(result.IsMember(3));
}

TEST(TSet, can_intersect_two_sets_of_non_equal_size) {
    TSet set1(10);
    set1.InsElem(3);
    TSet set2(5);
    set2.InsElem(3);
    TSet result = set1 * set2;
    ASSERT_TRUE(result.IsMember(3));
}

TEST(TSet, check_negation_operator) {
    TSet set(10);
    set.InsElem(3);
    TSet result = ~set;
    ASSERT_FALSE(result.IsMember(3));
}

