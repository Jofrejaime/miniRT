#include "parser.h"

static int valid_diameter(double diameter)
{
    return (diameter > 0.0);
}

t_error parse_sphere(
    t_rt *rt,
    t_token *token)
{
    t_sphere    *sphere;
    t_object    *object;
    t_error     err;

    if (expect_token_count(token, 4))
        return (ERR_INVALID_ARGUMENT_COUNT);

    sphere = malloc(sizeof(t_sphere));
    if (!sphere)
        return (ERR_MALLOC);

    err = parse_vec3(
            &sphere->center,
            token->values[1]);
    if (err)
        return (free(sphere), err);

    err = parse_double(
            &sphere->diameter,
            token->values[2]);
    if (err)
        return (free(sphere), err);

    if (!valid_diameter(sphere->diameter))
        return (free(sphere), ERR_INVALID_DIAMETER);

    object = malloc(sizeof(t_object));
    if (!object)
        return (free(sphere), ERR_MALLOC);

    err = parse_color(
            &object->color,
            token->values[3]);
    if (err)
        return (free(sphere), free(object), err);

    object->type = OBJ_SPHERE;
    object->data = sphere;
    object->next = NULL;

    object_add(
        &rt->scene.objects,
        object);

    return (ERR_NONE);
}