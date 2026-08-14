#include "parser.h"

t_error expect_token_count(
    t_token *token,
    int expected)
{
    if (!token)
        return (ERR_INVALID_TOKEN);

    if (token->count != expected)
        return (ERR_INVALID_TOKEN_COUNT);

    return (ERR_NONE);
}
t_error parse_element(t_rt *rt, t_token *token)
{
    t_error err;
    char *id;

    id = token->values[0];
    err = validate_token(token);
    if (err != ERR_NONE)
        return (err);
    if (!ft_strncmp(id, "A", 2))
        return (parse_ambient(rt, token));
    else if (!ft_strncmp(id, "C", 2))
        return (parse_camera(rt, token));
    else if (!ft_strncmp(id, "L", 2))
        return (parse_light(rt, token));
    else if (!ft_strncmp(id, "sp", 3))
        return (parse_sphere(rt, token));
    else if (!ft_strncmp(id, "pl", 3))
        return (parse_plane(rt, token));
    else if (!ft_strncmp(id, "cy", 3))
        return (parse_cylinder(rt, token));
    else
        return (ERR_UNKNOWN_IDENTIFIER);
}
