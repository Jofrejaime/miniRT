 #include "parser.h"

static int valid_ratio(double ratio)
{
    return (ratio >= 0.0 && ratio <= 1.0);
}

t_error parse_ambient(
    t_rt *rt,
    t_token *token)
{
    t_ambient   *ambient;
    t_error     err;

    if (expect_token_count(token, 3))
        return (ERR_INVALID_ARGUMENT_COUNT);

    if (rt->scene.ambient)
        return (ERR_DUPLICATE_AMBIENT);

    ambient = malloc(sizeof(t_ambient));
    if (!ambient)
        return (ERR_MALLOC);

    err = parse_double(
            &ambient->ratio,
            token->values[1]);
    if (err)
        return (free(ambient), err);

    if (!valid_ratio(ambient->ratio))
        return (free(ambient), ERR_INVALID_RATIO);

    err = parse_color(
            &ambient->color,
            token->values[2]);
    if (err)
        return (free(ambient), err);

    rt->scene.ambient = ambient;

    return (ERR_NONE);
}