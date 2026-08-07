#include  "parser.h"

static int in_range(int value)
{
    return (value >= 0 && value <= 255);
}

static t_error add_color(t_color *color, char *r,
    char *g,
    char *b)
{
    t_error err;

    err = parse_int(&color->r, r);
    if (err)
        return (err);
    err = parse_int(&color->g, g);
    if (err)
        return (err);
    err = parse_int(&color->b, b);
    if (err)
        return (err);
    if (!in_range(color->r)
        || !in_range(color->g)
        || !in_range(color->b))
        return (ERR_INVALID_COLOR);
    return (ERR_NONE);
}

t_error parse_color(t_color *color, char *str)
{
    char    **parts;
    t_error err;

    if (!color || !str)
        return (ERR_INVALID_COLOR);
    parts = ft_split(str, ',');
    if (!parts)
        return (ERR_MALLOC);
    if (ft_arrlen(parts) != 3)
        return (ft_free_arr(parts), ERR_INVALID_COLOR);
    err = add_color(color, parts[0], parts[1], parts[2]);
    ft_free_arr(parts);
    return (err);
}