#include "parser.h"

t_error parse_sphere(
    t_rt *rt,
    t_token *token)
{
    t_vec3      center;
    t_color     color;
    double      diameter;
    t_object    *object;
    t_error     err;

    if (expect_token_count(token, 4))
        return (ERR_INVALID_ARGUMENT_COUNT);
    err = parse_vec3(&center, token->values[1]);
    if (err)
        return (err);
    err = parse_double(&diameter, token->values[2]);
    if (err)
        return (err);
    if (diameter <= 0.0)
        return (ERR_INVALID_DIAMETER);
    err = parse_color(&color, token->values[3]);
    if (err)
        return (err);
    object = create_sphere_object(
            center,
            diameter,
            color);
    if (!object)
        return (ERR_MALLOC);
    object_add(&rt->scene.objects, object);
    return (ERR_NONE);
}
