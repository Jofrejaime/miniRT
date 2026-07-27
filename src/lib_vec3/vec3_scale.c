/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:43:28 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/27 13:43:34 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vec3.h"


t_vec3  vec3_scale(t_vec3 v, double s)
{
        t_vec3 result;

        result.x = v.x * s;
        result.y = v.y * s;
        result.z = v.z * s;

    return (result);
}
