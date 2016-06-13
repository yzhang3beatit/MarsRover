#include <stdio.h>
#include <string.h>

#include "map.h"

static void wrapping_map_edge(map_t *map, coord_t *loc);
static void wrapping_north_south(map_t *map, coord_t *loc);
static void wrapping_east_west(map_t *map, coord_t *loc);


void init_map(map_t *map)
{
	map->h_axis = 0;
	map->v_axis = 0;
	map->south_edge = 0;
	map->north_edge = 0;
	map->east_edge = 0;
	map->west_edge = 0;
	memset(map->obst, 0, sizeof(map->obst));
	map->obst_num = 0;

	map->map_fun = (maping)find_location_in_map;
	map->obst_fun = (obstacle)examine_obst;
}

int get_free_size(map_t *map)
{
	return (map->h_axis + 1) * (map->v_axis + 1);
}

void set_map_size(map_t *map, int h_limit, int v_limit)
{
	map->h_axis = h_limit;
	map->v_axis = v_limit;
	map->north_edge = v_limit;
	map->east_edge = h_limit;
}

int find_location_in_map(map_t *map, coord_t *loc)
{
	wrapping_map_edge(map, loc);

	return 0;
}

static void wrapping_map_edge(map_t *map, coord_t *loc)
{
	wrapping_north_south(map, loc);
	wrapping_east_west(map, loc);
}

static void wrapping_north_south(map_t *map, coord_t *loc)
{
	if (loc->vertical > map->north_edge)
		loc->vertical = map->south_edge;

	if (loc->vertical < map->south_edge)
		loc->vertical = map->north_edge;
}

static void wrapping_east_west(map_t *map, coord_t *loc)
{
	if (loc->horizon > map->east_edge)
		loc->horizon = map->west_edge;

	if (loc->horizon < map->west_edge)
		loc->horizon = map->east_edge;
}

bool examine_obst(map_t *map, coord_t *loc)
{
	for(int i = 0; i < map->obst_num; i++)
	{
		if(match_coord(loc, &(map->obst[i])))
			return true;
	}
	return false;
}

void add_obst(map_t *map, coord_t *loc)
{
	if(!map)
		return;
	if(!examine_obst(map, loc))
        memcpy(&(map->obst[map->obst_num++]), loc, sizeof(*loc));
}

const char* get_all_obst(map_t *map, char* loc)
{
	coord_t *obst = map->obst;
	char *ptr = loc;

	for(int i = 0; i < map->obst_num; obst = &(map->obst[++i]))
	{
		if(i > 0)
		{
			*ptr = ';';
			ptr++;
		}
		get_coord(obst, ptr);
		ptr += strlen(ptr);
	}

	return loc;

}
