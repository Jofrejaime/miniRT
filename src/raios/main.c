#include "minirt.h"
#include "raios.h"
#include "../lexer/token.h"

static int	handle_error(t_rt *rt, t_error err, char *arg, char *msg)
{
	set_error(&rt->error, err, 0, NULL, arg, msg);
	print_error(&rt->error);
	return (1);
}

static int	load_scene(t_rt *rt, int fd, char *path)
{
	t_token	*tokens;
	t_error	err;

	tokens = tokenize(fd);
	err = parse_scene(rt, tokens);
	free_tokens(tokens);
	if (err)
		return (handle_error(rt, err, path, NULL));
	return (0);
}

int	main(int argc, char **argv)
{
	t_rt	rt;
	int		fd;
	t_error	err;

	ft_bzero(&rt, sizeof(t_rt));
	err = verify_args(argc, argv);
	if (err)
		return (handle_error(&rt, err, NULL, NULL));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (handle_error(&rt, ERR_FILE_OPEN, argv[1], "Cannot open file"));
	if (load_scene(&rt, fd, argv[1]))
	{
		close(fd);
		return (1);
	}
	close(fd);
	if (windows_ini(&rt.mlx, 400, 400) != 0)
	{
		rt_destroy(&rt);
		return (1);
	}
	camera_build_basis(&rt.scene.camera, 400.0 / 400.0);
	render_scene(&rt.scene, &rt.mlx);
	mlx_put_image_to_window(rt.mlx.mlx, rt.mlx.win, rt.mlx.image.mlx_img, 0, 0);
	/*mlx_hook(rt.mlx.win, 2, 1L << 0, key_hook, &rt);
	mlx_hook(rt.mlx.win, 17, 1L << 17, close_hook, &rt);*/
	mlx_loop(rt.mlx.mlx);
	return (0);
}