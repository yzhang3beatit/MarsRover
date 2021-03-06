#include "coord.h"


typedef int (*maping)(void *map, coord_t *loc);
typedef bool (*obstacle)(void *map, coord_t *loc);

typedef struct _Smap{
	int h_axis;
	int v_axis;
	int south_edge;
	int north_edge;
	int east_edge;
	int west_edge;
	coord_t obst[10];
	int obst_num;

	maping map_fun;
	obstacle obst_fun;
}map_t;



extern void init_map(map_t *map);
extern int get_free_size(map_t *map);
extern void set_map_size(map_t *map, int h_limit, int v_limit);
extern int find_location_in_map(map_t *map, coord_t *loc);
extern bool examine_obst(map_t *map, coord_t *loc);
extern void add_obst(map_t *map, coord_t *loc);
extern const char* get_all_obst(map_t *map, char* loc);
