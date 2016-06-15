#include "rover.h"

#define MAX_ROVER 10



#define SUCCESSFUL 0
#define INVALID_INDEX_ERR -1
#define ENCOUNTER_OBSTACLE_ERR -2


#define NO_OBSTACLE 1

typedef struct _Sgame{
	map_t   map;
	int     rover_num;
	rover_t rovers[MAX_ROVER];
	int     flag;
}game_t;

extern void init_game(game_t *def);
extern const char *get_rovers_in_game(game_t *game, char *loc);
extern void set_map_in_game(game_t *game, int h_axis, int v_axis);
extern void game_set_locations(game_t *game, const char *locs);
extern int rover_move_in_game(game_t *game, int index, const char* directive);
extern const char *get_game_obstacle(game_t *game, char *output);
