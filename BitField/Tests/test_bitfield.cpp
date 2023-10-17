#include "gtest.h"
#include <climits>
#include "bitfield.h"
TEST(TBitField, can_get_length) {
    TBitField bf(10);
    ASSERT_EQ(bf.size(), 10);
}

TEST(TBitField, can_create_bitfield_with_positive_length) {
    TBitField bf(100);
    ASSERT_EQ(bf.size(), 100);
}

TEST(TBitField, can_create_too_large_bitfield) {
    TBitField bf(1000000);
    ASSERT_EQ(bf.size(), 1000000);
}

TEST(TBitField, new_bitfield_is_set_to_zero) {
    TBitField bf(100);
    ASSERT_STREQ(bf.to_string().c_str(), "0000000000");
}

TEST(TBitField, throws_when_create_bitfield_with_negative_length) {
    ASSERT_THROW(TBitField bf(-1), std::logic_error);
}

TEST(TBitField, can_set_bit) {
    TBitField bf(10);
    bf.set(2);
    ASSERT_EQ(bf.test(2), true);
}

TEST(TBitField, throws_when_set_bit_with_negative_index) {
    TBitField bf(10);
    ASSERT_THROW(bf.set(-1), std::logic_error);
}

TEST(TBitField, throws_when_set_bit_with_too_large_index) {
    TBitField bf(10);
    ASSERT_THROW(bf.set(20), std::logic_error);
}

TEST(TBitField, throws_when_get_bit_with_negative_index) {
    TBitField bf(10);
    ASSERT_THROW(bf.test(-1), std::logic_error);
}

TEST(TBitField, throws_when_get_bit_with_too_large_index) {
    TBitField bf(10);
    ASSERT_THROW(bf.test(20), std::logic_error);
}

TEST(TBitField, can_clear_bit) {
    TBitField bf(10);
    bf.set(2);
    bf.reset(2);
    ASSERT_EQ(bf.test(2), false);
}

TEST(TBitField, throws_when_clear_bit_with_negative_index) {
    TBitField bf(10);
    ASSERT_THROW(bf.reset(-1), std::logic_error);
}

TEST(TBitField, throws_when_clear_bit_with_too_large_index) {
    TBitField bf(10);
    ASSERT_THROW(bf.reset(20), std::logic_error);
}

TEST(TBitField, can_assign_bitfields_of_equal_size) {
    TBitField bf1(10);
    bf1.set(2);
    TBitField bf2(10);
    bf2 = bf1;
    ASSERT_EQ(bf2.test(2), true);
}

TEST(TBitField, can_assign_bitfields_of_non_equal_size) {
    TBitField bf1(10);
    bf1.set(2);
    TBitField bf2(5);
    bf2 = bf1;
    ASSERT_EQ(bf2.test(2), true);
}

TEST(TBitField, assign_operator_changes_bitfield_size) {
    TBitField bf1(10);
    TBitField bf2(5);
    bf2 = bf1;
    ASSERT_EQ(bf2.size(), 10);
}

TEST(TBitField, assign_operator_correctly_work) {
    TBitField bf1(10);
    bf1.set(2);
    TBitField bf2(10);
    bf2.set(4);
    bf2 = bf1;
    ASSERT_EQ(bf2.test(2), true);
    ASSERT_EQ(bf2.test(4), false);
}

TEST(TBitField, or_operator_applied_to_bitfields_of_equal_size) {
    TBitField bf1(10);
    bf1.set(2);
    TBitField bf2(10);
    bf2.set(4);
    TBitField result = bf1 | bf2;
    ASSERT_EQ(result.test(2), true);
    ASSERT_EQ(result.test(4), true);
}

TEST(TBitField, or_operator_applied_to_bitfields_of_non_equal_size) {
    TBitField bf1(10);
    bf1.set(2);
    TBitField bf2(5);
    bf2.set(3);
    TBitField result = bf1 | bf2;
    ASSERT_EQ(result.test(2), true);
    ASSERT_EQ(result.test(3), true);
}

TEST(TBitField, and_operator_applied_to_bitfields_of_equal_size) {
    TBitField bf1(10);
    bf1.set(2);
    bf1.set(4);
    TBitField bf2(10);
    bf2.set(4);
    TBitField result = bf1 & bf2;
    ASSERT_EQ(result.test(2), false);
    ASSERT_EQ(result.test(4), true);
}

TEST(TBitField, and_operator_applied_to_bitfields_of_non_equal_size) {
    TBitField bf1(10);
    bf1.set(2);
    bf1.set(4);
    TBitField bf2(5);
    bf2.set(3);
    TBitField result = bf1 & bf2;
    ASSERT_EQ(result.test(2), false);
    ASSERT_EQ(result.test(3), false);
}



TEST(TBitField, not_operator_applied_to_bitfield) {
    TBitField bf(10);
    bf.set(2);
    TBitField result = ~bf;
    ASSERT_EQ(result.test(2), false);
}



