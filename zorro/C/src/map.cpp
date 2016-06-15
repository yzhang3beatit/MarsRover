#include <stdio.h>

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
	init_obst(&(map->obst));
	init_coord(&(map->start_point));
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

bool encounter_obst(map_t *map, coord_t *coord)
{
	return found_obst_in_list(&(map->obst), coord);
}

void add_obst_in_map(map_t *map, coord_t *new_obst)
{
	if(is_same_coord(&(map->start_point), new_obst))
		return;
	add_obst(&(map->obst), new_obst);
}

const char* get_obstacle_in_map(map_t *map, char *output)
{
	return get_obst(&(map->obst), output);
}
