#include "direction.h"

void init_default_dir(int *direction)
{
	*direction = NORTH;
}

void get_direction_delta(int direction, int *delta_x, int *delta_y)
{
	switch(direction)
	{
	case NORTH:
		*delta_x = 0;
		*delta_y = 1;
		break;

	case EAST:
		*delta_x = 1;
		*delta_y = 0;
		break;

	case SOUTH:
		*delta_x = 0;
		*delta_y = -1;
		break;

	case WEST:
		*delta_x = -1;
		*delta_y = 0;
		break;

	default:
		break;
	}
}

void direction_turn_right(int *direction)
{
	*direction = (*direction + 1) % 4;
}

void direction_turn_left(int *direction)
{
	*direction = ((*direction + 3) % 4);
}
