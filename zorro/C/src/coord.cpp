#include <stdio.h>
#include <string.h>
#include "coord.h"

static char *get_coord(coord_t *coord, char *loc);

void init_coord(coord_t *coord)
{
	coord->horizon = 0;
	coord->vertical = 0;
	init_default_dir(&(coord->orie));
	coord->next = NULL;
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



const char *get_coords(coord_t *coord, int num, char *output)
{
	char *ptr = output;
	coord_t *coord_ptr = coord;

	for(int i = 0; i < num; i++)
	{
		if(i > 0)
		{
			*ptr = ';';
			ptr++;
		}
		get_coord(coord_ptr, ptr);
		coord_ptr = coord_ptr->next;
		ptr += strlen(ptr);
	}

	return output;
}

static char *get_coord(coord_t *coord, char *loc)
{
	sprintf(loc, "%d,%d", coord->horizon, coord->vertical);

	return loc;
}


void insert_coord_list(coord_t *coord_list, coord_t *coord)
{
	coord_t *coord_ptr = coord_list;

    if(coord_list == coord)
        return;
	while(coord_ptr->next)
    {
		coord_ptr = coord_ptr->next;
    }

	coord_ptr->next = coord;
}

bool is_same_coord(coord_t *expect, coord_t *actual)
{
	bool ret = (expect->horizon == actual->horizon &&
			expect->vertical == actual->vertical);
	return ret;
}
