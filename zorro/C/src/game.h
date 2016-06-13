#include "rover.h"

#define MAX_ROVER 10
typedef struct _Sgame{
	map_t   map;
	int     rover_num;
	rover_t rovers[MAX_ROVER];
}game_t;

extern void init_game(game_t *def);
extern const char *get_rovers_in_game(game_t *game, char *loc);
extern void set_map_in_game(game_t *game, int h_axis, int v_axis);
extern void game_set_locations(game_t *game, const char *locs);
extern bool rover_move_in_game(game_t *game, int index, const char* directive);
