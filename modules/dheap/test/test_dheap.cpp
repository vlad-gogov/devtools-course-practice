// Copyright 2021 Gogov Vladislav

#include <gtest/gtest.h>

#include <vector>

#include "include/dheap.h"

TEST(DheapTest, can_create_default) {
    ASSERT_NO_THROW(Dheap a);
}

TEST(DheapTest, cannot_create_with_base_1) {
    ASSERT_ANY_THROW(Dheap a(1));
}

TEST(DheapTest, can_get_base) {
    int base = 3;
    Dheap a(base);
    ASSERT_EQ(a.getBase(), base);
}

TEST(DheapTest, can_create_with_default_base) {
    Dheap a;
    ASSERT_EQ(a.getBase(), 2);
}

TEST(DheapTest, can_create_with_base_5) {
    int base = 5;
    Dheap a(base);
    ASSERT_EQ(a.getBase(), base);
}

TEST(DheapTest, can_get_weights) {
    int base = 2;
    std::vector<int> weight = {1, 2};
    Dheap a(base, weight);
    ASSERT_EQ(a.getWeight(), weight);
}

TEST(DheapTest, can_get_size_dheap) {
    int base = 2;
    std::vector<int> weight = {1, 2, 8, 9, 10, 5};
    Dheap a(base, weight);
    ASSERT_EQ(a.getSize(), weight.size());
}

TEST(DheapTest, can_create_with_hilling_weights) {
    int base = 3;
    std::vector<int> weight = {1, 2, 3, 4};
    Dheap a(base, weight);
    ASSERT_EQ(a.getWeight(), weight);
}

TEST(DheapTest, can_pop_min) {
    int base = 2;
    std::vector<int> weight = {5, 6, 7};
    Dheap a(base, weight);
    a.popMin();
    ASSERT_NE(a.getWeight()[0], weight[0]);
}

TEST(DheapTest, can_top_min) {
    int base = 2;
    std::vector<int> weight = {5, 6, 7};
    Dheap a(base, weight);
    ASSERT_EQ(a.topMin(), weight[0]);
}

TEST(DheapTest, can_hilling_dheap) {
    int base = 4;
    std::vector<int> weight = {11, 9, 9, 6, 8, 3, 4, 12, 7};
    Dheap a(base, weight);
    std::vector<int> hilling_weight = {3, 4, 9, 6, 8, 9, 11, 12, 7};
    ASSERT_EQ(a.getWeight(), hilling_weight);
}

TEST(DheapTest, can_insert_min_child_dheap) {
    int base = 4;
    int insert_child = 1;
    std::vector<int> weight = {11, 9, 9, 6, 8, 3, 4, 12, 7};
    Dheap a(base, weight);
    a.insert(insert_child);
    ASSERT_EQ(a.topMin(), insert_child);
}

TEST(DheapTest, can_insert_max_child_dheap) {
    int base = 4;
    int insert_child = 15;
    std::vector<int> weight = {3, 4, 12, 7, 11, 9, 6, 8, 14};
    Dheap a(base, weight);
    a.insert(insert_child);
    ASSERT_EQ(a.getWeight().back(), insert_child);
}