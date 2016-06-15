#include "map.h"

typedef struct _SRover
{
	coord_t loc;
	map_t *map;
}rover_t;

#define LOC_LEN 10

extern void init_rover(rover_t *rover);
extern bool set_location(rover_t *rover, const char *location);
extern bool rover_move(rover_t *rover, const char *directive);
extern void insert_rover_list(rover_t *rover_list, rover_t *rover);
extern const char *get_rover_loc(rover_t *rover, int num, char *location);
