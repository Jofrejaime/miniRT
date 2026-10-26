/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:08:03 by lvitorin          #+#    #+#             */
/*   Updated: 2026/09/04 16:08:06 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

t_vec3		vec3_add(t_vec3 a, t_vec3 b);
t_vec3		vec3_sub(t_vec3 a, t_vec3 b);
t_vec3		vec3_scale(t_vec3 v, double s);
double		vec3_dot(t_vec3 a, t_vec3 b);
t_vec3		vec3_cross(t_vec3 a, t_vec3 b);
double		vec3_length(t_vec3 v);
t_vec3		vec3_normalize(t_vec3 v);
t_vec3		vec3_rotate(t_vec3 v, t_vec3 axis, double angle_rad);

#endif
