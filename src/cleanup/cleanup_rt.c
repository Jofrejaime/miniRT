#include "cleanup.h"
#include "mlx.h"

static void destroy_window(t_mlx *mlx)
{
    if (!mlx)
        return ;
    if (mlx->win)
    {
        mlx_destroy_window(
            mlx->mlx,
            mlx->win);
        mlx->win = NULL;
    }
}

static void destroy_image(t_mlx *mlx)
{
    if (!mlx)
        return ;
    if (mlx->image.mlx_img)
    {
        mlx_destroy_image(
            mlx->mlx,
            mlx->image.mlx_img);
        mlx->image.mlx_img = NULL;
    }
}

void rt_destroy(t_rt *rt)
{
    if (!rt)
        return ;
    scene_destroy(&rt->scene);
    destroy_image(&rt->mlx);
    destroy_window(&rt->mlx);
#ifdef __linux__
    if (rt->mlx.mlx)
        mlx_destroy_display(rt->mlx.mlx);
#endif
    rt->mlx.mlx = NULL;
} 