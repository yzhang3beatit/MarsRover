#include <stdio.h>
#include <string.h>
#include "rover.h"

static void do_move_forward(coord_t *rover);
static bool move_forward(rover_t* rover);
static void turn_right(coord_t *rover);
static void turn_left(coord_t *rover);
static bool move_forward_with_policy(rover_t* rover);

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

void insert_rover_list(rover_t *rover_list, rover_t *rover)
{
	insert_coord_list(&(rover_list->loc), &(rover->loc));
}

const char *get_rover_loc(rover_t *rover, int num, char *location)
{
	return get_coords(&(rover->loc), num, location);
}

bool rover_move(rover_t *rover, const char *directive)
{
	bool ret = true;

	for(const char *str = directive; *str != '\0'; str++){
		if(*str == 'M'){
			if(!move_forward_with_policy(rover))
				ret = false;
		} else if(*str == 'R'){
			turn_right(&(rover->loc));
		} else if(*str == 'L'){
			turn_left(&(rover->loc));
		}
	}
	if(rover->map)
	{
		add_obst_in_map(rover->map, &(rover->loc));
	}
end:
	return ret;
}

static bool move_forward_with_policy(rover_t* rover)
{
	coord_t last;
	bool ret;

	memcpy(&last, &(rover->loc), sizeof(last));
	ret = move_forward(rover);

	if(!ret)
		memcpy(&(rover->loc), &last, sizeof(last));

	return ret;
}

static bool move_forward(rover_t* rover)
{
	do_move_forward(&(rover->loc));
	if(!rover->map)
		return true;

	find_location_in_map(rover->map, &(rover->loc));

	if(encounter_obst(rover->map, &(rover->loc)))
		return false;

    return true;
}

static void do_move_forward(coord_t *rover)
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
