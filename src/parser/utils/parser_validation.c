#inlcude "parser.h"

t_error validate_scene (t_rt *rt)
{
    if (!rt->scene.ambient)
        return (ERR_MISSING_AMBIENT);
    if (!rt->scene.camera)
        return (ERR_MISSING_CAMERA);
    if (!rt->scene.light)
        return (ERR_MISSING_LIGHT);
    return (ERR_NONE);
}