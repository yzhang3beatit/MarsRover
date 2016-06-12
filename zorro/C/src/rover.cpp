#include <stdio.h>

#include "direction.h"
#include "rover.h"

static void move_forward(rover_t *rover);
static void turn_right(rover_t *rover);
static void turn_left(rover_t *rover);

void init_rover(rover_t *rover)
{
	rover->x = 0;
	rover->y = 0;
	init_default_dir(&rover->direction);
}

bool set_location(rover_t *rover, const char *loc)
{
	int ret;
	ret = sscanf(loc, "%d,%d", &rover->x, &rover->y);
	if(ret != 2)
		return false;

	return true;
}

char *get_location(rover_t *rover, char *location)
{
	sprintf(location, "%d,%d", rover->x, rover->y);
	return location;
}

void rover_move(rover_t *rover, const char *directive)
{
	for(const char *str = directive; *str != '\0'; str++){
		if(*str == 'M'){
			move_forward(rover);
		} else if(*str == 'R'){
			turn_right(rover);
		} else if(*str == 'L'){
			turn_left(rover);
		}
	}
}

static void move_forward(rover_t *rover)
{
	int delta_x, delta_y;

	get_direction_delta(rover->direction, &delta_x, &delta_y);
	rover->x += delta_x;
	rover->y += delta_y;
}

static void turn_right(rover_t *rover)
{
	direction_turn_right(&rover->direction);
}

static void turn_left(rover_t *rover)
{
	direction_turn_left(&rover->direction);
}
