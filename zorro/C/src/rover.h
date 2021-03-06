#include "map.h"

typedef struct _SRover
{
	coord_t loc;
	map_t *map;
}rover_t;

#define LOC_LEN 10

extern void init_rover(rover_t *rover);
extern bool set_location(rover_t *rover, const char *location);
extern char *get_location(rover_t *rover, char *location);
extern int rover_move(rover_t *rover, const char *directive);
extern void load_map(rover_t *rover, map_t *map);
