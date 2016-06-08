#include <stdlib.h>
#include <string.h>
#include "map.h"

typedef struct map
{
    int height;
    int width;
} map_t;

map_t map;
bool map_initialize(int height, int width)
{
    if((height <= 0) or(width <= 0)) return false;
    map.height = height;
    map.width = width;
    return true;
}

bool is_position_allowed(int x, int y)
{
    if((x < 0) or(x > map.height)) return false;
    if((y < 0) or(y > map.width)) return false;

    return true;
}

bool map_destroy(void)
{
    map.height = map.width = 0;
    return true;
}
