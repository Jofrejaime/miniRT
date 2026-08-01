#include "parser.h"

t_error parse_vec3(t_vec3 *vec, char *str)
{
    char    **parts;
    t_error err;

    if (!vec || !str)
        return (ERR_INVALID_VECTOR);
    parts = ft_split(str, ',');
    if (!parts)
        return (ERR_MALLOC);
    if (ft_arrlen(parts) != 3)
        return (ft_free_arr(parts), ERR_INVALID_VECTOR);
    err = parse_double(&vec->x, parts[0]);
    if (err)
        return (ft_free_arr(parts), ERR_INVALID_VECTOR);
    err = parse_double(&vec->y, parts[1]);
    if (err)
        return (ft_free_arr(parts), ERR_INVALID_VECTOR);
    err = parse_double(&vec->z, parts[2]);
    if (err)
        return (ft_free_arr(parts), ERR_INVALID_VECTOR);
    ft_free_arr(parts);
    return (ERR_NONE);
}