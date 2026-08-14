#include "parser.h"

static int valid_ratio(double ratio)
{
    return (ratio >= 0.0 && ratio <= 1.0);
}

t_error parse_light(
    t_rt *rt,
    t_token *token)
{
    t_light *light;
    t_error err;

    if (expect_token_count(token, 4))
        return (ERR_INVALID_ARGUMENT_COUNT);

    if (rt->scene.light)
        return (ERR_DUPLICATE_LIGHT);
    light = malloc(sizeof(t_light));
    if (!light)
        return (ERR_MALLOC);
    err = parse_vec3(
            &light->pos,
            token->values[1]);
    if (err)
        return (free(light), err);
    err = parse_double(
            &light->ratio,
            token->values[2]);
    if (err)
        return (free(light), err);
    if (!valid_ratio(light->ratio))
        return (free(light), ERR_INVALID_RATIO);
    err = parse_color(
            &light->color,
            token->values[3]);
    if (err)
        return (free(light), err);
    rt->scene.light = light;
    return (ERR_NONE);
}