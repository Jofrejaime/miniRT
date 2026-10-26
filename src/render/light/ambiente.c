/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiente.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:18:22 by lvitorin          #+#    #+#             */
/*   Updated: 2026/08/20 09:18:47 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

double	compute_ambient(t_scene *scene)
{
	return (scene->ambient->ratio);
}

double	compute_diffuse(t_hit *hit, t_light *light)
{
	t_vec3	dir;
	double	cos_theta;

	dir = light_direction(hit, light);
	cos_theta = vec3_dot(hit->normal, dir);
	if (cos_theta < 0.0)
		cos_theta = 0.0;
	return (cos_theta * light->ratio);
}
