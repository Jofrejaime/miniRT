/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:39:26 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/27 14:39:28 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vec3.h"

t_vec3  vec3_rotate(t_vec3 v, t_vec3 axis, double angle)
{
    t_vec3  result;
    double  cos_angle = cos(angle);
    double  sin_angle = sin(angle);

    result.x = v.x * cos_angle + axis.x * (1 - cos_angle) * \
    (v.x * axis.x + v.y * axis.y + v.z * axis.z) + \
    axis.y * sin_angle * v.z - axis.z * sin_angle * v.y;

    result.y = v.y * cos_angle + axis.y * (1 - cos_angle) * \
    (v.x * axis.x + v.y * axis.y + v.z * axis.z) + \
    axis.z * sin_angle * v.x - axis.x * sin_angle * v.z;
    
    result.z = v.z * cos_angle + axis.z * (1 - cos_angle) * \
    (v.x * axis.x + v.y * axis.y + v.z * axis.z) + \
    axis.x * sin_angle * v.y - axis.y * sin_angle * v.x;

    return (result);
}
