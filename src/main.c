#include "minirt.h"
#include "parser.h"

int	main(int argc, char **argv)
{
	t_mlx mlx;

	if (verify_args(argc, argv))
		return (1);
	if (argc == 2 && !argv)
		return (0);
	windows_ini(&mlx, 400, 400);
	while(1)
		mlx_loop(mlx.win);
	return(0);
}
