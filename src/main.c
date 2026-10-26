/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 13:11:54 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/09/14 13:11:57 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "errors.h"
#include "minirt.h"
#include "parser.h"
#include "raios.h"
#include "render.h"

#define WIDTH 800
#define HEIGHT 600

static int	check_args(t_rt *rt, int argc, char **argv)
{
	t_error	err;

	err = verify_args(argc, argv);
	if (err)
	{
		set_error(&rt->error, err, NULL, NULL);
		print_error(&rt->error);
		return (1);
	}
	return (0);
}

static int	open_scene_file(t_rt *rt, char **argv, int *fd)
{
	*fd = open(argv[1], O_RDONLY);
	if (*fd >= 0)
		return (0);
	set_error(&rt->error, ERR_FILE_OPEN, NULL, argv[1]);
	print_error(&rt->error);
	return (1);
}

static int	process_scene(t_rt *rt, t_token *tokens)
{
	t_error	err;

	err = parse_scene(rt, tokens);
	if (err)
	{
		print_error(&rt->error);
		destroy_tokens(tokens);
		scene_destroy(&rt->scene);
		return (1);
	}
	destroy_tokens(tokens);
	return (0);
}

static int	init_and_render(t_rt *rt)
{
	if (windows_ini(&rt->mlx, WIDTH, HEIGHT, rt) != 0)
	{
		scene_destroy(&rt->scene);
		return (1);
	}
	render(rt, WIDTH, HEIGHT);
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win, rt->mlx.image.mlx_img, 0,
		0);
	mlx_loop(rt->mlx.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rt	rt;
	t_token	*tokens;
	int		fd;
	int		err;

	ft_bzero(&rt, sizeof(t_rt));
	err = check_args(&rt, argc, argv);
	if (err)
		return (1);
	err = open_scene_file(&rt, argv, &fd);
	if (err)
		return (1);
	tokens = tokenize(fd);
	close(fd);
	if (process_scene(&rt, tokens))
		return (1);
	return (init_and_render(&rt));
}
