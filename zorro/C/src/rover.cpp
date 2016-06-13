#include <stdio.h>
#include <string.h>

#include "rover.h"

static void move_forward(coord_t *rover);
static void turn_right(coord_t *rover);
static void turn_left(coord_t *rover);

void init_rover(rover_t *rover)
{
	init_coord(&rover->loc);
	rover->map = NULL;
}

bool set_location(rover_t *rover, const char *loc)
{
	int ret;
	int x, y;
	char d;

	ret = sscanf(loc, "%d,%d,%c", &x, &y, &d);
	if(ret != 3)
		return false;

	set_coord(&(rover->loc), x, y);
	set_orient(&(rover->loc), d);

	return true;
}

char *get_location(rover_t *rover, char *location)
{
	return get_coord(&(rover->loc), location);
}

void load_map(rover_t *rover, map_t *map)
{
	rover->map = map;
}

int rover_move(rover_t *rover, const char *directive)
{
	coord_t prev_loc;
	int ret = 0;

	for(const char *str = directive; *str != '\0'; str++){
		if(*str == 'M'){
			memcpy(&prev_loc, &(rover->loc), sizeof(rover->loc));
			move_forward(&(rover->loc));
			if(rover->map)
			{
			    rover->map->map_fun(rover->map, &(rover->loc));
			    if(rover->map->obst_fun(rover->map, &(rover->loc)))
			    {
			    	printf("rover->loc %d,%d", rover->loc.horizon, rover->loc.vertical);
			    	memcpy(&(rover->loc), &prev_loc, sizeof(rover->loc));
			    	ret = -1;
			    	break;
			    }
			}

		} else if(*str == 'R'){
			turn_right(&(rover->loc));
		} else if(*str == 'L'){
			turn_left(&(rover->loc));
		}
	}

	if(ret == -1)
		add_obst(rover->map, &(prev_loc));
	else
		add_obst(rover->map, &(rover->loc));

	return ret;
}

static void move_forward(coord_t *rover)
{
	int delta_x, delta_y;

	get_direction_delta(rover->orie, &delta_x, &delta_y);
	rover->horizon += delta_x;
	rover->vertical += delta_y;
}

static void turn_right(coord_t *rover)
{
	direction_turn_right((int*)&rover->orie);
}

static void turn_left(coord_t *rover)
{
	direction_turn_left((int*)&rover->orie);
}
