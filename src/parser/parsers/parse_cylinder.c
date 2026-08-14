#include "parser.h"

t_error parse_cylinder(
    t_rt *rt,
    t_token *token)
{
    t_cylinder *cylinder;
    t_object   *object;
    t_color     color;
    t_error     err;

    if (expect_token_count(token, 6))
        return (ERR_INVALID_ARGUMENT_COUNT);

    cylinder = malloc(sizeof(t_cylinder));
    if (!cylinder)
        return (ERR_MALLOC);

    err = parse_vec3(
            &cylinder->center,
            token->values[1]);
    if (err)
        return (free(cylinder), err);

    err = parse_vec3(
            &cylinder->axis,
            token->values[2]);
    if (err)
        return (free(cylinder), err);

    if (!valid_orientation(cylinder->axis))
        return (free(cylinder), ERR_INVALID_ORIENTATION);

    if (is_zero_vector(cylinder->axis))
        return (free(cylinder), ERR_INVALID_ORIENTATION);

    cylinder->axis = vec3_normalize(cylinder->axis);

    err = parse_double(
            &cylinder->diameter,
            token->values[3]);
    if (err)
        return (free(cylinder), err);

    if (cylinder->diameter <= 0.0)
        return (free(cylinder), ERR_INVALID_DIAMETER);

    err = parse_double(
            &cylinder->height,
            token->values[4]);
    if (err)
        return (free(cylinder), err);

    if (cylinder->height <= 0.0)
        return (free(cylinder), ERR_INVALID_HEIGHT);

    err = parse_color(
            &color,
            token->values[5]);
    if (err)
        return (free(cylinder), err);

    object = object_new(
                OBJ_CYLINDER,
                cylinder,
                color);

    if (!object)
        return (free(cylinder), ERR_MALLOC);

    object_add(
        &rt->scene.objects,
        object);

    return (ERR_NONE);
}