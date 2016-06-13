enum DIRECTION{
	NORTH = 0,
	EAST,
	SOUTH,
	WEST
};

extern void init_default_dir(DIRECTION *direction);
extern void get_direction_delta(DIRECTION direction, int *delta_x, int *delta_y);
extern void direction_turn_right(int *direction);
extern void direction_turn_left(int *direction);
