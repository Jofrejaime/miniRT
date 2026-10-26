/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:36:56 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/18 15:36:57 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

int	hit_scene(t_scene *scene, t_ray ray, t_hit *hit)
{
	t_object	*obj;
	t_hit		temp;
	double		closest;
	int			found;

	found = 0;
	closest = INFINITY;
	obj = scene->objects;
	while (obj)
	{
		if (intersect_object(ray, obj, &temp))
		{
			if (temp.t > EPSILON && temp.t < closest)
			{
				closest = temp.t;
				*hit = temp;
				found = 1;
			}
		}
		obj = obj->next;
	}
	return (found);
}
