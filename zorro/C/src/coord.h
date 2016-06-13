#include "direction.h"

typedef struct _Scoord{
	int horizon;
	int vertical;
	DIRECTION orie; //orientation
}coord_t;


extern void init_coord(coord_t *coord);
extern void set_coord(coord_t *coord, int x, int y);
extern void set_orient(coord_t *coord, char orie);
extern char *get_coord(coord_t *coord, char *loc);
extern bool match_coord(coord_t *expect, coord_t *actual);
