/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:10:52 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/19 15:10:53 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	valid_fov(double fov)
{
	return (fov > 0.0 && fov < 180.0);
}

static t_error	parse_camera_data(t_camera *camera, t_token *token)
{
	t_error	err;

	err = parse_vec3(&camera->pos, token->values[1]);
	if (err)
		return (err);
	err = parse_vec3(&camera->dir, token->values[2]);
	if (err)
		return (err);
	if (!valid_orientation(camera->dir))
		return (ERR_INVALID_ORIENTATION);
	err = parse_double(&camera->fov, token->values[3]);
	if (err)
		return (err);
	if (!valid_fov(camera->fov))
		return (ERR_INVALID_FOV);
	camera->dir = vec3_normalize(camera->dir);
	return (ERR_NONE);
}

t_error	parse_camera(t_rt *rt, t_token *token)
{
	t_camera	*camera;
	t_error		err;

	if (expect_token_count(token, 4))
		return (ERR_INVALID_ARGUMENT_COUNT);
	if (rt->scene.camera)
		return (ERR_DUPLICATE_CAMERA);
	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (ERR_MALLOC);
	err = parse_camera_data(camera, token);
	if (err)
		return (free(camera), err);
	rt->scene.camera = camera;
	return (ERR_NONE);
}
