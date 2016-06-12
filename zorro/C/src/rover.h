typedef struct _SRover
{
	int x;
	int y;
	int direction;
}rover_t;


extern void init_rover(rover_t *rover);
extern bool set_location(rover_t *rover, const char *location);
extern char *get_location(rover_t *rover, char *location);
extern void rover_move(rover_t *rover, const char *directive);
