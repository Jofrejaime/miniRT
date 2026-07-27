/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:59:46 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/27 13:59:49 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vec3.h"

t_vec3  vec3_cross(t_vec3 a, t_vec3 b)
{
    t_vec3 result;

    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;

    return (result);
}