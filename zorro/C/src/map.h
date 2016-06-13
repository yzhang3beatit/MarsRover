#include "coord.h"

typedef struct _Smap{
	int h_axis;
	int v_axis;
	int south_edge;
	int north_edge;
	int east_edge;
	int west_edge;
}map_t;

typedef int (*maping)(map_t *map, coord_t *loc);

extern void init_map(map_t *map);
extern int get_free_size(map_t *map);
extern void set_map_size(map_t *map, int h_limit, int v_limit);
extern int find_location_in_map(map_t *map, coord_t *loc);
