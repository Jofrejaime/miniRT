/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:20:10 by lvitorin          #+#    #+#             */
/*   Updated: 2026/08/20 09:20:12 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

int	is_in_shadow(t_scene *scene, t_vec3 point, t_vec3 light_dir,
		double light_dist)
{
	t_ray	shadow_ray;
	t_hit	blocker;

	shadow_ray.origin = point;
	shadow_ray.dir = light_dir;
	if (hit_scene(scene, shadow_ray, &blocker) && blocker.t < light_dist)
		return (1);
	return (0);
}

static t_shade_factors	get_shade_factors(t_scene *scene, t_hit *hit)
{
	t_shade_factors	f;
	t_vec3			light_dir;
	double			light_dist;
	t_vec3			biased_point;
	double			diffuse;

	f.ambient = compute_ambient(scene);
	light_dir = light_direction(hit, scene->light);
	light_dist = light_distance(hit, scene->light);
	diffuse = compute_diffuse(hit, scene->light);
	f.diffuse = 0.0;
	if (diffuse > 0.01)
	{
		biased_point = point_with_bias(hit->point, hit->normal);
		if (!is_in_shadow(scene, biased_point, light_dir, light_dist - EPSILON))
			f.diffuse = diffuse;
	}
	return (f);
}

static int	shade_channel(int obj_channel, int light_channel,
		int ambient_channel, t_shade_factors f)
{
	double	value;
	double	ambient_contrib;
	double	diffuse_contrib;

	ambient_contrib = f.ambient * (ambient_channel / 255.0);
	diffuse_contrib = f.diffuse * (light_channel / 255.0);
	value = obj_channel * (ambient_contrib + diffuse_contrib);
	return (clamp_channel(value));
}

t_color	shade_point(t_scene *scene, t_hit *hit)
{
	t_shade_factors	f;
	t_color			obj_color;
	t_color			result;

	obj_color = hit->object->color;
	f = get_shade_factors(scene, hit);
	result.r = shade_channel(obj_color.r, scene->light->color.r,
			scene->ambient->color.r, f);
	result.g = shade_channel(obj_color.g, scene->light->color.g,
			scene->ambient->color.g, f);
	result.b = shade_channel(obj_color.b, scene->light->color.b,
			scene->ambient->color.b, f);
	return (result);
}
