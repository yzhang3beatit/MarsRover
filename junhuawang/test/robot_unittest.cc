#include <limits.h>
#include "map.h"
#include "robot.h"
#include "gtest/gtest.h"

class RobotTest: public testing::Test{
    protected:
        virtual void SetUp() {
            map_initialize(5, 5);
        }

        virtual void TearDown() {
            map_destroy();
        }
};

TEST_F(RobotTest, Robot_initialize_failed_if_position_is_not_allowed) {
    robot_t robot;

    EXPECT_FALSE(robot_initialize(&robot, -1, 0, 'N'));
    EXPECT_TRUE(robot_initialize(&robot, 5, 0, 'N'));
    EXPECT_TRUE(robot_initialize(&robot, 5, 5, 'N'));
    EXPECT_FALSE(robot_initialize(&robot, 6, 6, 'N'));
}

TEST_F(RobotTest, Robot_initialize_failed_if_direction_is_not_allowed) {
    robot_t robot;

    EXPECT_FALSE(robot_initialize(&robot, 0, 0, 'X'));
}

TEST_F(RobotTest, Robot_init_success) {
    robot_t robot;

    EXPECT_TRUE(robot_initialize(&robot, 0, 0, 'E'));
    EXPECT_TRUE(robot_initialize(&robot, 0, 0, 'N'));
    EXPECT_TRUE(robot_initialize(&robot, 0, 0, 'S'));
    EXPECT_TRUE(robot_initialize(&robot, 0, 0, 'W'));
}

TEST_F(RobotTest, Robot_move_forward_north_one_step) {
    robot_t robot;

    robot_initialize(&robot, 0, 0, 'N');
    EXPECT_TRUE(robot_accept_one_instruction(&robot, 'M'));
    EXPECT_TRUE(robot.x== 0);
    EXPECT_TRUE(robot.y== 1);
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'N');
}

TEST_F(RobotTest, Robot_move_forward_east_one_step) {
    robot_t robot;
     robot_initialize(&robot, 0, 0, 'E');
     EXPECT_TRUE(robot_accept_one_instruction(&robot, 'M'));
     EXPECT_TRUE(robot.x== 1);
     EXPECT_TRUE(robot.y== 0);
     EXPECT_TRUE(get_robot_direction_name(&robot)== 'E');
}

TEST_F(RobotTest, Robot_move_forward_west_one_step) {
    robot_t robot;
     robot_initialize(&robot, 5, 0, 'W');
     EXPECT_TRUE(robot_accept_one_instruction(&robot, 'M'));
     EXPECT_TRUE(robot.x== 4);
     EXPECT_TRUE(robot.y== 0);
     EXPECT_TRUE(get_robot_direction_name(&robot)== 'W');
}

TEST_F(RobotTest, Robot_move_forward_south_one_step) {
    robot_t robot;
     robot_initialize(&robot, 5, 5, 'S');
     EXPECT_TRUE(robot_accept_one_instruction(&robot, 'M'));
     EXPECT_TRUE(robot.x== 5);
     EXPECT_TRUE(robot.y== 4);
     EXPECT_TRUE(get_robot_direction_name(&robot)== 'S');
}
// 
TEST_F(RobotTest, Robot_move_out_the_north_border_failed) {
    robot_t robot;

    robot_initialize(&robot, 5, 5, 'N');
    EXPECT_FALSE(robot_accept_one_instruction(&robot, 'M'));
    EXPECT_TRUE(robot.x== 5);
    EXPECT_TRUE(robot.y== 5);
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'N');
}
// 
TEST_F(RobotTest, Robot_move_out_the_south_boarder_failed) {
    robot_t robot;

    map_initialize(5, 5);
    robot_initialize(&robot, 4, 0, 'S');
    EXPECT_FALSE(robot_accept_one_instruction(&robot, 'M'));
    EXPECT_TRUE(robot.x== 4);
    EXPECT_TRUE(robot.y== 0);
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'S');
}
//
TEST_F(RobotTest, Robot_move_out_the_west_boarder_failed) {
    robot_t robot;

    robot_initialize(&robot, 0, 4, 'W');
    EXPECT_FALSE(robot_accept_one_instruction(&robot, 'M'));
    EXPECT_TRUE(robot.x== 0);
    EXPECT_TRUE(robot.y== 4);
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'W');
}
//
TEST_F(RobotTest, Robot_move_out_the_east_boarder_failed) {
    robot_t robot;

    robot_initialize(&robot, 5, 0, 'E');
    EXPECT_FALSE(robot_accept_one_instruction(&robot, 'M'));
    EXPECT_TRUE(robot.x== 5);
    EXPECT_TRUE(robot.y== 0);
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'E');
}
// 
TEST_F(RobotTest, Robot_accept_turn_left_instruction_from_4_different_directions) {
    robot_t robot;

    robot_initialize(&robot, 0, 0, 'N');
    EXPECT_TRUE(robot_accept_one_instruction(&robot, 'L'));
    EXPECT_TRUE(robot.x== 0);
    EXPECT_TRUE(robot.y== 0);
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'W');
    EXPECT_TRUE(robot_accept_one_instruction(&robot, 'L'));
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'S');
    EXPECT_TRUE(robot_accept_one_instruction(&robot, 'L'));
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'E');
    EXPECT_TRUE(robot_accept_one_instruction(&robot, 'L'));
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'N');
}
//
TEST_F(RobotTest, Robot_accept_turn_right_instruction_from_4_different_directions) {
    robot_t robot;

    robot_initialize(&robot, 0, 0, 'N');
    EXPECT_TRUE(robot_accept_one_instruction(&robot, 'R'));
    EXPECT_TRUE(robot.x== 0);
    EXPECT_TRUE(robot.y== 0);
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'E');
    EXPECT_TRUE(robot_accept_one_instruction(&robot, 'R'));
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'S');
    EXPECT_TRUE(robot_accept_one_instruction(&robot, 'R'));
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'W');
    EXPECT_TRUE(robot_accept_one_instruction(&robot, 'R'));
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'N');
}

TEST_F(RobotTest, Robot_accept_long_instructions) {
    robot_t robot;
    char move[] = "LMLMLMLMM";

    robot_initialize(&robot, 1, 2, 'N');
    for(size_t i=0; i<strlen(move); i++) {
        robot_accept_one_instruction(&robot, move[i]);
    }
    EXPECT_TRUE(robot.x== 1);
    EXPECT_TRUE(robot.y== 3);
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'N');
}
//
TEST_F(RobotTest, Robot_accept_4_instructions_to_turn_around) {
    robot_t robot;
    char move[] = "RRRR";

    robot_initialize(&robot, 3, 3, 'E');
    for(size_t i=0; i<strlen(move); i++) {
        robot_accept_one_instruction(&robot, move[i]);
    }
    EXPECT_TRUE(robot.x== 3);
    EXPECT_TRUE(robot.y== 3);
    EXPECT_TRUE(get_robot_direction_name(&robot)== 'E');
}
