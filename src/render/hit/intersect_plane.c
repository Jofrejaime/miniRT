/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interset_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:41:35 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/18 15:41:57 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

static double	plane_hit_distance(t_ray ray, t_plane *pl)
{
	double	denom;
	double	t;

	denom = vec3_dot(pl->normal, ray.dir);
	if (fabs(denom) < PARALLEL_EPSILON)
		return (-1.0);
	t = vec3_dot(vec3_sub(pl->point, ray.origin), pl->normal) / denom;
	if (t < EPSILON)
		return (-1.0);
	return (t);
}

int	intersect_plane(t_ray ray, t_object *obj, t_hit *hit)
{
	t_plane	*pl;
	double	t;

	pl = (t_plane *)obj->data;
	t = plane_hit_distance(ray, pl);
	if (t < EPSILON)
		return (0);
	hit_fill(hit, ray, t, pl->normal);
	hit->object = obj;
	return (1);
}
