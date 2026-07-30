#include "minirt.h"

int	main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc == 2 && !argv)
		return (0);
	windows_ini(&mlx, 400, 400);
	while(1)
		mlx_loop(mlx.win);
	return(0);
}
