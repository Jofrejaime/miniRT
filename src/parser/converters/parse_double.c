#include "parser.h"

t_error parse_double(double *value, char *str)
{
    char *endptr;

    if (!value || !str)
        return (ERR_INVALID_NUMBER);
    *value = strtod(str, &endptr);
    if (*endptr != '\0')
        return (ERR_INVALID_NUMBER);
    return (ERR_NONE);
}
