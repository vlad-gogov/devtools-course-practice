// Copyright 2021 Gogov Vladislav

#include <gtest/gtest.h>

#include "include/dheap.h"

TEST(DheapTest, can_create_default) {
    ASSERT_NO_THROW(Dheap a);
}

TEST(DheapTest, cannot_create_with_base_1) {
    ASSERT_ANY_THROW(Dheap a(1));
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

TEST(DheapTest, can_create_with_weights) {
    int base = 3;
    std::vector<int> weight = {1, 2, 3, 4};
    Dheap a(base, weight);
    ASSERT_EQ(a.getWeight(), weight);
}
