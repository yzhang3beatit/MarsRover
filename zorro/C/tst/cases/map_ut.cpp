#include "map.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;


class map_test : public testing::Test
{
public:
	map_t map_;

	virtual void SetUp() {
		init_map(&map_);
		set_map_size(&map_, 5, 5);

	}
	virtual void TearDown() {/*DGTMock::destroyInstance();*/}
};


TEST_F(map_test, EmptyMapSizeIsZero)
{
	map_t default_;

	init_map(&default_);
	EXPECT_EQ(1, get_free_size(&default_));
}

TEST_F(map_test, SetMapSize)
{
	set_map_size(&map_, 5, 5);

	EXPECT_EQ(6*6, get_free_size(&map_));
}

TEST_F(map_test, WrapFromNorthEdgeToSouthEdge)
{
	coord_t north_edge = {2, 6, NORTH};

	find_location_in_map(&map_, &north_edge);
	EXPECT_EQ(2, north_edge.horizon);
	EXPECT_EQ(0, north_edge.vertical);
	EXPECT_EQ(NORTH, north_edge.orie);
}

TEST_F(map_test, WrapFromSouthEdgeToNorthEdge)
{
	coord_t south_edge = {2, -1, SOUTH};

	find_location_in_map(&map_, &south_edge);
	EXPECT_EQ(2, south_edge.horizon);
	EXPECT_EQ(5, south_edge.vertical);
	EXPECT_EQ(SOUTH, south_edge.orie);
}

TEST_F(map_test, WrapFromEastEdgeToWestEdge)
{
	coord_t east_edge = {6, 2, EAST};

	find_location_in_map(&map_, &east_edge);
	EXPECT_EQ(0, east_edge.horizon);
	EXPECT_EQ(2, east_edge.vertical);
	EXPECT_EQ(EAST, east_edge.orie);
}

TEST_F(map_test, WrapFromWestEdgeToEastEdge)
{
	coord_t west_edge = {-1, 2, WEST};

	find_location_in_map(&map_, &west_edge);
	EXPECT_EQ(5, west_edge.horizon);
	EXPECT_EQ(2, west_edge.vertical);
	EXPECT_EQ(WEST, west_edge.orie);
}
