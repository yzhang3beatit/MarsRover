#include "rover.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;

TEST(rover_failed_test, RoverSetLocationFailedLackOfOriend)
{
	rover_t apple;
	init_rover(&apple);
	EXPECT_FALSE(set_location(&apple, "0,0"));
}

class rover_test : public testing::Test
{
public:
	rover_t apple_;
	char location_[LOC_LEN];
	const char *NORTH;
	const char *WEST;
	const char *SOUTH;
	const char *EAST;


	virtual void SetUp() {
		char set_loc[] = "1,1,N";

		NORTH = "1,2";
		WEST = "0,1";
		SOUTH = "1,0";
		EAST = "2,1";

		init_rover(&apple_);
		EXPECT_TRUE(set_location(&apple_, set_loc));
	}
	virtual void TearDown() {/*DGTMock::destroyInstance();*/}
};


TEST_F(rover_test, RoverLandingAtZeroByDefault)
{
	init_rover(&apple_);
	EXPECT_STREQ("0,0", get_rover_loc(&apple_, 1, location_));
}

TEST_F(rover_test, RoverLandingBySetting)
{
	EXPECT_STREQ("1,1", get_rover_loc(&apple_, 1, location_));
}

TEST_F(rover_test, RoverMoveForwardNorthByDefault)
{
	rover_move(&apple_, "M");
	EXPECT_STREQ(NORTH, get_rover_loc(&apple_, 1, location_));
}

TEST_F(rover_test, RoverTurnRightMoveForwardEast)
{
	rover_move(&apple_, "RM");
	EXPECT_STREQ(EAST, get_rover_loc(&apple_, 1, location_));
}

TEST_F(rover_test, RoverTurnRightTwiceMoveForwardSouth)
{
	rover_move(&apple_, "RRM");
	EXPECT_STREQ(SOUTH, get_rover_loc(&apple_, 1, location_));

}

TEST_F(rover_test, RoverTurnRight3TimesMoveForwardWest)
{
	rover_move(&apple_, "RRRM");
	EXPECT_STREQ(WEST, get_rover_loc(&apple_, 1, location_));

}

TEST_F(rover_test, RoverTurnLeftMoveForwardWest)
{
	rover_move(&apple_, "LM");
	EXPECT_STREQ(WEST, get_rover_loc(&apple_, 1, location_));
}

TEST_F(rover_test, RoverTurnLeftTwiceMoveForwardSouth)
{
	rover_move(&apple_, "LLM");
	EXPECT_STREQ(SOUTH, get_rover_loc(&apple_, 1, location_));
}

TEST_F(rover_test, RoverTurnLeft3TimesMoveForwardEast)
{
	rover_move(&apple_, "LLLM");
	EXPECT_STREQ(EAST, get_rover_loc(&apple_, 1, location_));
}
