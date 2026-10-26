/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 13:50:00 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/09/14 13:50:00 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

t_quadratic	cylinder_equation(t_ray ray, t_cylinder *cy)
{
	t_quadratic	eq;
	t_vec3		oc;
	t_vec3		oc_perp;
	t_vec3		dir_perp;

	oc = vec3_sub(ray.origin, cy->center);
	oc_perp = vec3_sub(oc, vec3_scale(cy->axis, vec3_dot(oc, cy->axis)));
	dir_perp = vec3_sub(ray.dir, vec3_scale(cy->axis, vec3_dot(ray.dir,
					cy->axis)));
	eq.a = vec3_dot(dir_perp, dir_perp);
	eq.b = 2.0 * vec3_dot(oc_perp, dir_perp);
	eq.c = vec3_dot(oc_perp, oc_perp) - ((cy->diameter * cy->diameter) / 4);
	eq.delta = (eq.b * eq.b) - (4.0 * eq.a * eq.c);
	return (eq);
}

static int	point_in_height(t_cylinder *cy, t_ray ray, double t)
{
	t_vec3	point;
	double	proj;

	point = ray_at(ray, t);
	proj = vec3_dot(vec3_sub(point, cy->center), cy->axis);
	return (proj >= -(cy->height / 2.0) && proj <= (cy->height / 2.0));
}

double	cylinder_side_distance(t_ray ray, t_cylinder *cy)
{
	t_quadratic	eq;
	double		t1;
	double		t2;
	double		best;

	eq = cylinder_equation(ray, cy);
	if (eq.delta < 0 || fabs(eq.a) < PARALLEL_EPSILON)
		return (-1);
	t1 = (-eq.b - sqrt(eq.delta)) / (2.0 * eq.a);
	t2 = (-eq.b + sqrt(eq.delta)) / (2.0 * eq.a);
	best = -1;
	if (t1 >= EPSILON && point_in_height(cy, ray, t1))
		best = t1;
	if (t2 >= EPSILON && point_in_height(cy, ray, t2) && (best < EPSILON
			|| t2 < best))
		best = t2;
	return (best);
}

double	cylinder_cap_t(t_ray ray, t_cylinder *cy, t_vec3 cap_center)
{
	double	denom;
	double	t;
	double	radius;
	t_vec3	point;
	t_vec3	diff;

	denom = vec3_dot(ray.dir, cy->axis);
	if (fabs(denom) < PARALLEL_EPSILON)
		return (-1);
	t = vec3_dot(vec3_sub(cap_center, ray.origin), cy->axis) / denom;
	if (t < EPSILON)
		return (-1);
	radius = cy->diameter / 2.0;
	point = ray_at(ray, t);
	diff = vec3_sub(point, cap_center);
	if (vec3_dot(diff, diff) > (radius * radius))
		return (-1);
	return (t);
}

t_vec3	cylinder_side_normal(t_cylinder *cy, t_vec3 point)
{
	double	proj;
	t_vec3	axis_point;

	proj = vec3_dot(vec3_sub(point, cy->center), cy->axis);
	axis_point = vec3_add(cy->center, vec3_scale(cy->axis, proj));
	return (vec3_normalize(vec3_sub(point, axis_point)));
}
