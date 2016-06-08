#ifndef __ROBOT_H__
#define __ROBOT_H__

typedef struct robot
{
    int x;
    int y;
    int direction;
} robot_t;


bool set_map_size(int height, int width);
bool robot_initialize(robot_t *robot, int x, int y, char direction);
bool robot_accept_one_instruction(robot_t *robot, char instruction);
char get_robot_direction_name(robot_t *robot);

#endif
