
#include "obstacle.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;


class obstacle_test : public testing::Test
{
public:
	obst_t empty_obst;
	char output_[10];

	virtual void SetUp() {
		init_obst(&empty_obst);
	}
	virtual void TearDown() {/*DGTMock::destroyInstance();*/}
};


TEST_F(obstacle_test, emptyObstacleSizeIsZero)
{
	EXPECT_EQ(0, get_obst_size(&empty_obst));
}

TEST_F(obstacle_test, addOneInEmptyObstacleSizeIsOne)
{
	coord_t new_obst = {0, 1, NORTH, NULL};
	add_obst(&empty_obst, &new_obst);
	EXPECT_EQ(1, get_obst_size(&empty_obst));
}

TEST_F(obstacle_test, addOneObstacleCouldBePrintOut)
{
	coord_t new_obst = {0, 1, NORTH, NULL};
	add_obst(&empty_obst, &new_obst);
	EXPECT_STREQ("0,1", get_obst(&empty_obst, output_));
}


TEST_F(obstacle_test, addTwoObstaclesCouldBePrintOut)
{
	coord_t first_obst = {0, 1, NORTH, NULL};
	coord_t second_obst = {1, 1, NORTH, NULL};

	add_obst(&empty_obst, &first_obst);
	add_obst(&empty_obst, &second_obst);
	EXPECT_STREQ("0,1;1,1", get_obst(&empty_obst, output_));
}

TEST_F(obstacle_test, addSameObstaclesOnlyPrintOutOne)
{
	coord_t first_obst = {0, 1, NORTH, NULL};
	coord_t second_obst = {0, 1, NORTH, NULL};

	add_obst(&empty_obst, &first_obst);
	add_obst(&empty_obst, &second_obst);
	EXPECT_STREQ("0,1", get_obst(&empty_obst, output_));
}
