#include "parser.h"

static t_error validate_token(t_token *token)
{
    if (!token)
        return (ERR_INVALID_TOKEN);
    if (!token->values)
        return (ERR_INVALID_TOKEN);
    if (!token->values[0])
        return (ERR_INVALID_TOKEN);
    return (ERR_NONE);
}
t_error expect_token_count(t_token *token, int expected)
{
    if (token->count != expected)
        return (ERR_INVALID_TOKEN_COUNT);
    return (ERR_NONE);
}

t_error parse_element(t_rt *rt, t_token *token)
{
    t_error err;

    err = validate_token(token);
    if (err != ERR_NONE)
        return (err);
    if (!ft_strcmp(token->values[0], "A") )
        return (parse_ambient(rt, token));
    else if (!ft_strcmp(token->values[0], "C"))
        return (parse_camera(rt, token));
    else if (!ft_strcmp(token->values[0], "L"))
        return (parse_light(rt, token));
    else if (!ft_strcmp(token->values[0], "sp"))
        return (parse_sphere(rt, token));
    else if (!ft_strcmp(token->values[0], "pl"))
        return (parse_plane(rt, token));
    else if (!ft_strcmp(token->values[0], "cy"))
        return (parse_cylinder(rt, token));
    else
        return (ERR_UNKNOWN_IDENTIFIER);
}

