#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "robot.h"

enum direction
{
    north,
    west,
    south,
    east
};

char direction_names[4] = {'N', 'W', 'S', 'E'};

int move_steps[2][4] = 
{
    {0, -1, 0, +1},
    {1, 0, -1, 0}
};

bool is_direction_allowed(char direction)
{
    for(int i=0; i<4; i++) {
        if(direction == direction_names[i]) {
            return true;
        }
    }
    return false;
}

int get_direction(char direct)
{
    int i=0;
    for(i=0; i<4; i++) {
        if(direct == direction_names[i]) {
            return i;
        }
    }
    return i;
}

char get_robot_direction_name(robot_t *robot)
{
    return direction_names[robot->direction];
}

bool robot_initialize(robot_t *robot, int x, int y, char direction)
{
   if(!robot) return false;
   if(!is_position_allowed(x,y)) return false;
   if(!is_direction_allowed(direction)) return false;

   robot->x = x;
   robot->y = y;
   robot->direction = get_direction(direction);
    return true;
}

bool robot_move(robot_t *robot)
{
    int new_x, new_y;

    new_x = robot->x + move_steps[0][robot->direction];
    new_y = robot->y + move_steps[1][robot->direction];

    if(!is_position_allowed(new_x, new_y)) return false;

    robot->x = new_x;
    robot->y = new_y;
    return true;
}

bool robot_turn_left(robot_t *robot)
{
    robot->direction = (robot->direction + 1) % 4;
    return true;
}

bool robot_turn_right(robot_t *robot)
{
    robot->direction = (4+robot->direction - 1) % 4;
    return true;
}

bool robot_accept_one_instruction(robot_t *robot, char instruction)
{
    switch (instruction) {
        case 'M':
            return robot_move(robot);
            break;
        case 'L':
            return robot_turn_left(robot);
            break;
        case 'R':
            return robot_turn_right(robot);
            break;
        default:
            break;

    }
    return true;
}

