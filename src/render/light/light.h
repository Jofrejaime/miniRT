/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:19:50 by lvitorin          #+#    #+#             */
/*   Updated: 2026/08/20 09:19:52 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "hit.h"
# include "minirt.h"

# define SHADOW_BIAS 1e-3

typedef struct s_shade_factors
{
	double	ambient;
	double	diffuse;
}			t_shade_factors;

/* light_utils.c — partilhado */
int			clamp_channel(double value);
t_vec3		point_with_bias(t_vec3 point, t_vec3 normal);
t_vec3		light_direction(t_hit *hit, t_light *light);
double		light_distance(t_hit *hit, t_light *light);

/* ambient.c / diffuse.c — Dev A */
double		compute_ambient(t_scene *scene);
double		compute_diffuse(t_hit *hit, t_light *light);

/* shadow.c — Dev B */
int			is_in_shadow(t_scene *scene, t_vec3 point, t_vec3 light_dir,
				double light_dist);

/* shade.c — integração */
t_color		shade_point(t_scene *scene, t_hit *hit);

#endif
