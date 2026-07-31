#include "minirt.h"
#include "parse.h"

int	main(int argc, char **argv)
{
	t_mlx mlx;

	if (!verify_args(argc, argv))
		return (1);
//	if (initialize_miniRT())
//		return (1);
	if (windows_ini(&mlx, 400, 400) != 0)
		return (1);
	mlx_loop(mlx.mlx);
	return(0);
}
