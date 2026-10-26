/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:19:31 by lvitorin          #+#    #+#             */
/*   Updated: 2026/08/20 09:19:34 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

int	clamp_channel(double value)
{
	if (value < 0.0)
		return (0);
	if (value > 255.0)
		return (255);
	return ((int)value);
}

t_vec3	point_with_bias(t_vec3 point, t_vec3 normal)
{
	return (vec3_add(point, vec3_scale(normal, SHADOW_BIAS)));
}

t_vec3	light_direction(t_hit *hit, t_light *light)
{
	return (vec3_normalize(vec3_sub(light->pos, hit->point)));
}

double	light_distance(t_hit *hit, t_light *light)
{
	return (vec3_length(vec3_sub(light->pos, hit->point)));
}
