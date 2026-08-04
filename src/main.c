#include "minirt.h"
#include "parser.h"

int	main(int argc, char **argv)
{
	t_mlx mlx;
	int fd;

	if (verify_args(argc, argv) != ERR_NONE)
		return (1);
	fd = open(argv[1], O_RDONLY);
//	if (initialize_miniRT())
//		return (1);
	if (windows_ini(&mlx, 400, 400) != 0)
		return (1);
	mlx_loop(mlx.mlx);
	close(fd);
	return(0);
}
