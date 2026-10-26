/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 14:42:51 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/09/14 14:42:52 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raios.h"
#include "render.h"

static int	color_to_int(t_color c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}

static int	ray_color(t_rt *rt, t_ray ray)
{
	t_hit	hit;
	t_color	color;

	if (hit_scene(&rt->scene, ray, &hit))
	{
		color = shade_point(&rt->scene, &hit);
		return (color_to_int(color));
	}
	return (0x000000);
}

void	render(t_rt *rt, int width, int height)
{
	int		x;
	int		y;
	t_ray	ray;
	int		color;

	camera_build_basis(rt->scene.camera, (double)width / height);
	y = 0;
	rt->scene.camera->width = width;
	rt->scene.camera->height = height;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ray = camera_get_ray(rt->scene.camera, x, y);
			color = ray_color(rt, ray);
			img_put_pixel(&rt->mlx.image, x, y, color);
			x++;
		}
		y++;
	}
}
