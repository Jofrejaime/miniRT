/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:40:47 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/18 15:40:49 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

int	intersect_object(t_ray ray, t_object *obj, t_hit *hit)
{
	if (!obj)
		return (0);
	if (obj->type == OBJ_SPHERE)
		return (intersect_sphere(ray, obj, hit));
	if (obj->type == OBJ_PLANE)
		return (intersect_plane(ray, obj, hit));
	if (obj->type == OBJ_CYLINDER)
		return (intersect_cylinder(ray, obj, hit));
	return (0);
}
