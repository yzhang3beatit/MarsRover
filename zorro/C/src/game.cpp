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
		load_map(&(def_game->rovers[i]), &(def_game->map));
	}
	def_game->rover_num = 0;
	set_map_in_game(def_game, 5, 5);
}

void set_map_in_game(game_t *game, int h_axis, int v_axis)
{
	init_map(&(game->map));
	set_map_size(&(game->map), h_axis, v_axis);
}

const char *get_rovers_in_game(game_t *game, char *loc)
{
	rover_t *rover = game->rovers;
	char *ptr = loc;

	for(int i = 0; i < game->rover_num; rover = &(game->rovers[++i]))
	{
		if(i > 0)
		{
			*ptr = ';';
			ptr++;
		}
		get_location(rover, ptr);
		ptr += strlen(ptr);
	}

	return loc;
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
		if(*ptr == '\0')
			break;
		i++;
	}
}

int rover_move_in_game(game_t *game, int index, const char* directive)
{
	if(index >= game->rover_num)
		return ROVER_INDEX_ERR;

	if(rover_move(&(game->rovers[index]), directive) == -1)
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

char *get_obstacle(game_t *game, int index, char *obst)
{
	return obst;
}
