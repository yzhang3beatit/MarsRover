#include "game.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;

TEST(game_test, gameInitRoversbyLocation)
{
	game_t def_game;
	char location_[LOC_LEN];

	init_game(&def_game);

	game_set_locations(&def_game, "1,1,N,2,2,S");
	EXPECT_STREQ("1,1;2,2", get_rovers_in_game(&def_game, location_));
}

TEST(game_test, gameExamples)
{
	game_t game;
	char location_[LOC_LEN];

	init_game(&game);
	set_map_in_game(&game, 10, 10);
	cancel_obstacle(&game);

	game_set_locations(&game, "1,2,N,3,3,E");
	EXPECT_STREQ("1,2;3,3", get_rovers_in_game(&game, location_));
	EXPECT_EQ(SUCCESSFUL, rover_move_in_game(&game, 0, "LMLMLMLMM"));
	EXPECT_EQ(SUCCESSFUL, rover_move_in_game(&game, 1, "MMRMMRMRRM"));
	EXPECT_STREQ("1,3;5,1", get_rovers_in_game(&game, location_));
}

class game_wrap_test : public testing::Test
{
public:
	game_t game;
	char location_[LOC_LEN];
	virtual void SetUp() {
		init_game(&game);
		set_map_in_game(&game, 5, 10);

	}
	virtual void TearDown() {/*DGTMock::destroyInstance();*/}
};



TEST_F(game_wrap_test, RoverMoveFromNorthEdgeToSouthEdge)
{
	game_set_locations(&game, "2,10,N");
	EXPECT_EQ(SUCCESSFUL, rover_move_in_game(&game, 0, "M"));
	EXPECT_STREQ("2,0", get_rovers_in_game(&game, location_));
}

TEST_F(game_wrap_test, RoverMoveFromEastEdgeToWestEdge)
{
	game_set_locations(&game, "5,4,E");
	EXPECT_EQ(SUCCESSFUL, rover_move_in_game(&game, 0, "M"));
	EXPECT_STREQ("0,4", get_rovers_in_game(&game, location_));
}

TEST_F(game_wrap_test, RoverMoveFromSouthEdgeToNorthEdge)
{
	game_set_locations(&game, "2,0,S");
	EXPECT_EQ(SUCCESSFUL, rover_move_in_game(&game, 0, "M"));
	EXPECT_STREQ("2,10", get_rovers_in_game(&game, location_));
}

TEST_F(game_wrap_test, RoverMoveFromWestEdgeToEastEdge)
{
	game_set_locations(&game, "0,4,W");
	EXPECT_EQ(SUCCESSFUL, rover_move_in_game(&game, 0, "M"));
	EXPECT_STREQ("5,4", get_rovers_in_game(&game, location_));
}

TEST_F(game_wrap_test, RoverMoveFailedForWrongIndex)
{
	game_set_locations(&game, "2,9,N");
	EXPECT_EQ(INVALID_INDEX_ERR, rover_move_in_game(&game, 1, "M"));
	EXPECT_STREQ("2,9", get_rovers_in_game(&game, location_));
}




class game_obstacle_test : public testing::Test
{
public:
	game_t game;
	char location_[LOC_LEN];
	virtual void SetUp() {
		init_game(&game);
		set_map_in_game(&game, 10, 10);

	}
	virtual void TearDown() {/*DGTMock::destroyInstance();*/}
};

TEST_F(game_obstacle_test, FirstRoverEncouterObstacle)
{
	coord_t obst = {0, 1, NORTH, NULL};
	game_set_locations(&game, "0,0,N");
	add_obst(&(game.map.obst), &obst);
	EXPECT_EQ(ENCOUNTER_OBSTACLE_ERR, rover_move_in_game(&game, 0, "M"));
	EXPECT_STREQ("0,1", get_game_obstacle(&game, location_));
}

TEST_F(game_obstacle_test, SecondRoverBlockedByFirstRover)
{
	game_set_locations(&game, "0,0,N,0,0,N");
	EXPECT_EQ(SUCCESSFUL, rover_move_in_game(&game, 0, "RLMMRL"));
	EXPECT_STREQ("0,2", get_game_obstacle(&game, location_));
	EXPECT_EQ(ENCOUNTER_OBSTACLE_ERR, rover_move_in_game(&game, 1, "MM"));
	EXPECT_STREQ("0,2;0,1", get_game_obstacle(&game, location_));
}

TEST_F(game_obstacle_test, SecondRoverNotBlockedByFirstRover)
{
	game_set_locations(&game, "0,0,N,0,0,N");
	EXPECT_EQ(SUCCESSFUL, rover_move_in_game(&game, 0, "RM"));
	EXPECT_EQ(SUCCESSFUL, rover_move_in_game(&game, 1, "M"));
	EXPECT_STREQ("1,0;0,1", get_game_obstacle(&game, location_));
}
