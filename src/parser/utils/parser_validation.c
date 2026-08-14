#include "parser.h"

t_error validate_scene(t_rt *rt)
{
    if (!rt)
        return (ERR_INVALID_SCENE);
    if (!rt->scene.objects)
        return (ERR_MISSING_OBJECTS);
    if (!rt->scene.ambient)
        return (ERR_MISSING_AMBIENT);
    if (!rt->scene.camera)
        return (ERR_MISSING_CAMERA);
    if (!rt->scene.light)
        return (ERR_MISSING_LIGHT);
    return (ERR_NONE);
}

t_error validate_token(t_token *token)
{
    if (!token)
        return (ERR_INVALID_TOKEN);
    if (!token->values || !token->values[0])
        return (ERR_INVALID_TOKEN);
    if (token->count <= 0)
        return (ERR_INVALID_TOKEN_COUNT);
    return (ERR_NONE);
}
