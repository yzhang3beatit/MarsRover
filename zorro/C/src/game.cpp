#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "game.h"

static const char* get_location_from(const char* locs, char *loc, int max);

void init_game(game_t *def_game)
{
	for(int i = 0; i < MAX_ROVER; i++)
	{
		init_rover(&(def_game->rovers[i]));
		def_game->rovers[i].map = &(def_game->map);
	}
	def_game->rover_num = 0;
	set_map_in_game(def_game, 5, 5);
	def_game->flag = 0;
}

void set_map_in_game(game_t *game, int h_axis, int v_axis)
{
	init_map(&(game->map));
	set_map_size(&(game->map), h_axis, v_axis);
}

const char *get_rovers_in_game(game_t *game, char *loc)
{
	return get_rover_loc(game->rovers, game->rover_num, loc);
}

void game_set_locations(game_t *game, const char *locs)
{
	char loc[LOC_LEN];
	const char *ptr = locs;
	int i;

	rover_t *rover = game->rovers;

	for(i = game->rover_num;
		i < MAX_ROVER;
		rover = &(game->rovers[i]))
	{
		ptr = get_location_from(ptr, loc, sizeof(loc));
    	game->rover_num++;

		set_location(rover, loc);
		insert_rover_list(game->rovers, rover);
		if(*ptr == '\0')
			break;
		i++;
	}
}

int rover_move_in_game(game_t *game, int index, const char* directive)
{
	if(index >= game->rover_num)
		return INVALID_INDEX_ERR;

	if(!rover_move(&(game->rovers[index]), directive))
		if(game->flag != NO_OBSTACLE)
			return ENCOUNTER_OBSTACLE_ERR;

	return SUCCESSFUL;
}

static const char* get_location_from(const char* locs, char *loc, int max)
{
	const char* ptr = locs;
	int comma = 0;

	for(;*ptr != '\0' && (ptr-locs) < max; ptr++, loc++)
	{
		*loc = *ptr;
		if(comma == 2)
		{
			ptr++;
			loc++;
			*loc = '\0';
			break;
		}
		if(*ptr == ',')
			comma++;
	}

	if(*ptr != '\0')
		ptr++;

	return ptr;

}

void cancel_obstacle(game_t *game)
{
	game->flag = NO_OBSTACLE;
}

const char *get_game_obstacle(game_t *game, char *output)
{
	return get_obstacle_in_map(&(game->map), output);
}
