/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:11:02 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/19 15:11:03 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_error	parse_cylinder_axis(t_cylinder *cylinder, t_token *token)
{
	t_error	err;

	err = parse_vec3(&cylinder->center, token->values[1]);
	if (err)
		return (err);
	err = parse_vec3(&cylinder->axis, token->values[2]);
	if (err)
		return (err);
	if (!valid_orientation(cylinder->axis))
		return (ERR_INVALID_ORIENTATION);
	if (is_zero_vector(cylinder->axis))
		return (ERR_INVALID_ORIENTATION);
	cylinder->axis = vec3_normalize(cylinder->axis);
	return (ERR_NONE);
}

static t_error	parse_cylinder_dimensions(t_cylinder *cylinder, t_token *token)
{
	t_error	err;

	err = parse_double(&cylinder->diameter, token->values[3]);
	if (err)
		return (err);
	if (cylinder->diameter <= 0.0)
		return (ERR_INVALID_DIAMETER);
	err = parse_double(&cylinder->height, token->values[4]);
	if (err)
		return (err);
	if (cylinder->height <= 0.0)
		return (ERR_INVALID_HEIGHT);
	return (ERR_NONE);
}

t_error	parse_cylinder(t_rt *rt, t_token *token)
{
	t_cylinder	*cylinder;
	t_object	*object;
	t_color		color;
	t_error		err;

	if (expect_token_count(token, 6))
		return (ERR_INVALID_ARGUMENT_COUNT);
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (ERR_MALLOC);
	err = parse_cylinder_axis(cylinder, token);
	if (err)
		return (free(cylinder), err);
	err = parse_cylinder_dimensions(cylinder, token);
	if (err)
		return (free(cylinder), err);
	err = parse_color(&color, token->values[5]);
	if (err)
		return (free(cylinder), err);
	object = object_new(OBJ_CYLINDER, cylinder, color);
	if (!object)
		return (free(cylinder), ERR_MALLOC);
	object_add(&rt->scene.objects, object);
	return (ERR_NONE);
}
