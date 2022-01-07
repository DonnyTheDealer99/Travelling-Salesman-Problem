#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define MAX_CITIES 10
#define MAX_RANGE 10
#define STARTING_CITY 0 // Sets starting point to '0'

struct City{
    int id;
    int x_coord;
    int y_coord;
};