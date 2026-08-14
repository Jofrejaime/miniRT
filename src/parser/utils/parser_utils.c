#include "parser.h"


int valid_orientation(t_vec3 v)
{
    return (
        v.x >= -1.0 && v.x <= 1.0 &&
        v.y >= -1.0 && v.y <= 1.0 &&
        v.z >= -1.0 && v.z <= 1.0
    );
}

int is_zero_vector(t_vec3 v)
{
    return (
        v.x == 0.0 &&
        v.y == 0.0 &&
        v.z == 0.0
    );
}
