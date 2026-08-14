/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:28:30 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/27 14:29:36 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vec3.h"

t_vec3  vec3_normalize(t_vec3 v)
{
    double size;
    t_vec3 result;

    size = vec3_length(v);
    result.x = v.x / size;
    result.y = v.y / size;
    result.z = v.z / size;

    return (result);
}