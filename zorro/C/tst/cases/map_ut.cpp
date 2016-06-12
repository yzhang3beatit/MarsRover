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
		rover_t banana;
	}
	virtual void TearDown() {/*DGTMock::destroyInstance();*/}
};


TEST_F(map_test, EmptyMapSizeIsZero)
{
	map_t default_;

	init_map_(&default_);
	EXPECT_STREQ(0, get_free_size(&default_));
}

