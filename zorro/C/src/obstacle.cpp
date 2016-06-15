#include <string.h>
#include <stdio.h>

#include "obstacle.h"

static void do_add_obst(obst_t *obsts, coord_t *new_obst);

void init_obst(obst_t *obst)
{
	memset(obst, 0, sizeof(*obst));
}

int get_obst_size(obst_t *obst)
{
	return obst->size;
}

void add_obst(obst_t *obsts, coord_t *new_obst)
{
	if(found_obst_in_list(obsts, new_obst))
		return;

	do_add_obst(obsts, new_obst);
}

bool found_obst_in_list(obst_t *obsts, coord_t *new_obst)
{
	for(int i = 0; i < obsts->size; i++)
	{
		if(is_same_coord(new_obst, &(obsts->obst_list[i])))
			return true;
	}

	return false;
}

static void do_add_obst(obst_t *obsts, coord_t *new_obst)
{
	memcpy(&(obsts->obst_list[obsts->size]), new_obst, sizeof(*new_obst));
	insert_coord_list(obsts->obst_list, &(obsts->obst_list[obsts->size]));
	obsts->size++;
}


const char *get_obst(obst_t *obsts, char *output)
{
	return get_coords(obsts->obst_list, obsts->size, output);
}

void print_all_obst(obst_t *obsts)
{
	for(int i = 0; i < obsts->size; i++)
		printf("obsts: %d, %d, %d\n", i, obsts->obst_list[i].horizon, obsts->obst_list[i].vertical);
}
