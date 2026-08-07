#include "windows.h"
#include "cleanup.h"

static int	handle_keypress(int keycode, void *param)
{
	if (keycode == 65307)
	{
		rt_destroy((t_rt *)param);
		exit(0);
	}
	return (0);
}

static int	handle_close(void *param)
{
	rt_destroy((t_rt *)param);
	exit(0);
}

static int	handle_expose(void *param)
{
	(void)param;
	return (0);
}

int	windows_ini(t_mlx *mlx, int width, int height, t_rt *rt)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (-1);
	mlx->win = mlx_new_window(mlx->mlx, width, height, "miniRT");
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->mlx);
		return (-1);
	}
	mlx->image.mlx_img = mlx_new_image(mlx->mlx, width, height);
	if (!mlx->image.mlx_img)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		return (-1);
	}
	mlx->image.addr = mlx_get_data_addr(mlx->image.mlx_img,
			&mlx->image.bpp, &mlx->image.line_len, &mlx->image.endian);
	mlx_hook(mlx->win, 2, 1L << 0, handle_keypress, rt);
	mlx_hook(mlx->win, 17, 0, handle_close, rt);
	mlx_hook(mlx->win, 12, 1L << 15, handle_expose, rt);
	mlx_loop(mlx->mlx);
	return (0);
}
