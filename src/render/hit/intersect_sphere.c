/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:40:57 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/18 15:40:59 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

static t_quadratic	sphere_equation(t_ray ray, t_sphere *sp)
{
	t_quadratic	eq;
	t_vec3		oc;

	oc = vec3_sub(ray.origin, sp->center);
	eq.a = vec3_dot(ray.dir, ray.dir);
	eq.b = 2.0 * vec3_dot(oc, ray.dir);
	eq.c = vec3_dot(oc, oc) - sp->radius * sp->radius;
	eq.delta = (eq.b * eq.b) - (4.0 * eq.a * eq.c);
	return (eq);
}

static double	solve_sphere(t_quadratic eq)
{
	double	t1;
	double	t2;

	if (eq.delta < 0)
		return (-1);
	t1 = (-eq.b - sqrt(eq.delta)) / (2.0 * eq.a);
	t2 = (-eq.b + sqrt(eq.delta)) / (2.0 * eq.a);
	return (smallest_positive_root(t1, t2));
}

static double	sphere_hit_distance(t_ray ray, t_sphere *sp)
{
	t_quadratic	eq;

	eq = sphere_equation(ray, sp);
	return (solve_sphere(eq));
}

int	intersect_sphere(t_ray ray, t_object *obj, t_hit *hit)
{
	t_sphere	*sp;
	double		t;
	t_vec3		normal;

	sp = (t_sphere *)obj->data;
	t = sphere_hit_distance(ray, sp);
	if (t < EPSILON)
		return (0);
	normal = vec3_normalize(vec3_sub(ray_at(ray, t), sp->center));
	hit_fill(hit, ray, t, normal);
	hit->object = obj;
	return (1);
}
