#include "direction.h"

typedef struct _Scoord{
	int horizon;
	int vertical;
	DIRECTION orie; //orientation
	struct _Scoord *next;
}coord_t;


extern void init_coord(coord_t *coord);
extern void set_coord(coord_t *coord, int x, int y);
extern void set_orient(coord_t *coord, char orie);
extern const char *get_coords(coord_t *coord, int size, char *output);
extern void insert_coord_list(coord_t *coord_list, coord_t *coord);
extern bool is_same_coord(coord_t *expect, coord_t *actual);
