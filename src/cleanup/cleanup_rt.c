#include "cleanup.h"
#include "mlx.h"

void rt_destroy(t_rt *rt)
{
	if (!rt)
		return ;
	scene_destroy(&rt->scene);
	if (rt->image.img)
	{
		mlx_destroy_image(rt->mlx, rt->image.img);
		rt->image.img = NULL;
	}
	if (rt->win)
	{
		mlx_destroy_window(rt->mlx, rt->win);
		rt->win = NULL;
	}
#ifdef __linux__
	if (rt->mlx)
		mlx_destroy_display(rt->mlx);
#endif
	if (rt->mlx)
	{
		free(rt->mlx);
		rt->mlx = NULL;
	}
}
