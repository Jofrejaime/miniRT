/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:11:32 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/19 15:11:39 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_error	parse_plane_point_and_normal(t_plane *plane, t_token *token)
{
	t_error	err;

	err = parse_vec3(&plane->point, token->values[1]);
	if (err)
		return (err);
	err = parse_vec3(&plane->normal, token->values[2]);
	if (err)
		return (err);
	if (!valid_orientation(plane->normal) || is_zero_vector(plane->normal))
		return (ERR_INVALID_ORIENTATION);
	plane->normal = vec3_normalize(plane->normal);
	return (ERR_NONE);
}

t_error	parse_plane(t_rt *rt, t_token *token)
{
	t_plane		*plane;
	t_object	*object;
	t_color		color;
	t_error		err;

	if (expect_token_count(token, 4))
		return (ERR_INVALID_ARGUMENT_COUNT);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (ERR_MALLOC);
	err = parse_plane_point_and_normal(plane, token);
	if (err)
		return (free(plane), err);
	err = parse_color(&color, token->values[3]);
	if (err)
		return (free(plane), err);
	object = object_new(OBJ_PLANE, plane, color);
	if (!object)
		return (free(plane), ERR_MALLOC);
	object_add(&rt->scene.objects, object);
	return (ERR_NONE);
}
