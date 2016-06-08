#include <limits.h>
#include "map.h"
#include "gtest/gtest.h"

TEST(MapTest, map_init_fail_if_size_is_not_positive_integer) {
    EXPECT_FALSE(map_initialize(0, 0));
    EXPECT_FALSE(map_initialize(-1, 0));
    EXPECT_FALSE(map_initialize(-1, -1));
}

//
TEST(MapTest, map_init_success_if_size_is_positive_integer) {
    EXPECT_TRUE(map_initialize(5, 5));
    EXPECT_TRUE(map_destroy());

}

TEST(MapTest, map_check_position_not_allowed) {
    EXPECT_TRUE(map_initialize(5, 5));
    EXPECT_FALSE(is_position_allowed(-1, 0));
    EXPECT_FALSE(is_position_allowed(0, -1));
    EXPECT_FALSE(is_position_allowed(6, 5));
    EXPECT_FALSE(is_position_allowed(6, 6));
    EXPECT_FALSE(is_position_allowed(0, 6));
    EXPECT_TRUE(map_destroy());

}

TEST(MapTest, map_check_if_position_allowed) {
    EXPECT_TRUE(map_initialize(5, 5));
    EXPECT_TRUE(is_position_allowed(0, 0));
    EXPECT_TRUE(is_position_allowed(5, 5));
    EXPECT_TRUE(is_position_allowed(4, 3));
    EXPECT_TRUE(map_destroy());

}
