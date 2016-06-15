#include "coord.h"

#define MAX_OBST 10

typedef struct _Sobstacle{
	coord_t obst_list[MAX_OBST];
	int size;
}obst_t;

extern int get_obst_size(obst_t *obst);
extern void init_obst(obst_t *obst);
extern void add_obst(obst_t *obst, coord_t *new_obst);
extern const char *get_obst(obst_t *obst, char *output);
extern bool found_obst_in_list(obst_t *obsts, coord_t *new_obst);
extern void print_all_obst(obst_t *obsts);
