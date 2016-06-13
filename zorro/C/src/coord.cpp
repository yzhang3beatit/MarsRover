#include <stdio.h>
#include "coord.h"

void init_coord(coord_t *coord)
{
	coord->horizon = 0;
	coord->vertical = 0;
	init_default_dir(&(coord->orie));
}

void set_coord(coord_t *coord, int x, int y)
{
	coord->horizon = x;
	coord->vertical = y;
}

void set_orient(coord_t *coord, char orie)
{
	DIRECTION ori;

	switch(orie)
	{
	case 'N':
		ori = NORTH;
		break;
	case 'S':
		ori = SOUTH;
		break;
	case 'E':
		ori = EAST;
		break;
	case 'W':
		ori = WEST;
		break;
	default:
		ori = NORTH;
		break;
	}
	coord->orie = ori;
}

char *get_coord(coord_t *coord, char *loc)
{
	sprintf(loc, "%d,%d", coord->horizon, coord->vertical);

	return loc;
}

bool match_coord(coord_t *expect, coord_t *actual)
{
	return expect->horizon == actual->horizon &&
			expect->vertical == actual->vertical;
}
