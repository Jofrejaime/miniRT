/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 09:35:45 by lvitorin          #+#    #+#             */
/*   Updated: 2026/08/06 09:35:48 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "raios.h"
#include "parser.h"
#include "token.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_rt		rt;
	int			fd;
	t_token		*tokens;

	if (argc != 2)
		return (1);
	if (!argv[1] || argv[1][0] == '\0')
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	tokens = tokenize(fd);
	close(fd);
	if (!tokens)
	{
		fprintf(stderr, "Error: Failed to tokenize file\n");
		return (1);
	}
	ft_bzero(&rt, sizeof(t_rt));
	if (parse_scene(&rt, tokens) != ERR_NONE)
	{
		fprintf(stderr, "Error parsing scene: %d\n", rt.error.code);
		if (rt.error.message)
			fprintf(stderr, "Message: %s\n", rt.error.message);
		return (1);
	}
	if (!rt.scene.camera)
	{
		fprintf(stderr, "Error: No camera defined in scene\n");
		return (1);
	}
	if (window_init(&rt.mlx, 800, 600) == -1)
		return (1);
	render_test_gradient(rt.scene.camera, &rt.mlx.image, 800, 600);
	mlx_put_image_to_window(rt.mlx.mlx, rt.mlx.win, rt.mlx.image.mlx_img, 0, 0);
	mlx_loop(rt.mlx.mlx);
	return (0);
}
