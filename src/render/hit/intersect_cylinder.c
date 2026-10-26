/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:40:39 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/18 15:40:40 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

static int	try_side_hit(t_ray ray, t_cylinder *cy, double *t_out,
		t_vec3 *normal_out)
{
	double	t;

	t = cylinder_side_distance(ray, cy);
	if (t < EPSILON)
		return (0);
	*t_out = t;
	*normal_out = cylinder_side_normal(cy, ray_at(ray, t));
	return (1);
}

static int	try_top_cap_hit(t_ray ray, t_cylinder *cy, double *t_out,
		t_vec3 *normal_out)
{
	t_vec3	cap_center;
	double	t;

	cap_center = vec3_add(cy->center, vec3_scale(cy->axis, cy->height / 2.0));
	t = cylinder_cap_t(ray, cy, cap_center);
	if (t < EPSILON)
		return (0);
	*t_out = t;
	*normal_out = cy->axis;
	return (1);
}

static int	try_bottom_cap_hit(t_ray ray, t_cylinder *cy, double *t_out,
		t_vec3 *normal_out)
{
	t_vec3	cap_center;
	double	t;

	cap_center = vec3_sub(cy->center, vec3_scale(cy->axis, cy->height / 2.0));
	t = cylinder_cap_t(ray, cy, cap_center);
	if (t < EPSILON)
		return (0);
	*t_out = t;
	*normal_out = vec3_scale(cy->axis, -1);
	return (1);
}

static void	update_best(double candidate, double *best,
				t_vec3 *normal, t_vec3 cand_norm)
{
	if (candidate < EPSILON)
		return ;
	if (*best < EPSILON || candidate < *best)
	{
		*best = candidate;
		*normal = cand_norm;
	}
}

int	intersect_cylinder(t_ray ray, t_object *obj, t_hit *hit)
{
	t_cylinder	*cy;
	double		t;
	double		best;
	t_vec3		normal;
	t_vec3		tmp;

	cy = (t_cylinder *)obj->data;
	best = -1;
	normal = (t_vec3){0, 0, 0};
	if (try_side_hit(ray, cy, &t, &tmp))
		update_best(t, &best, &normal, tmp);
	if (try_top_cap_hit(ray, cy, &t, &tmp))
		update_best(t, &best, &normal, tmp);
	if (try_bottom_cap_hit(ray, cy, &t, &tmp))
		update_best(t, &best, &normal, tmp);
	if (best < EPSILON)
		return (0);
	hit_fill(hit, ray, best, normal);
	hit->object = obj;
	return (1);
}
