/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 12:55:24 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/09/14 12:59:55 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "errors.h"
# include "libft.h"
# include "mlx.h"
# include "objects.h"
# include "vec3.h"
# include "windows.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ambient
{
	double			ratio;
	t_color			color;
}					t_ambient;

typedef struct s_light
{
	t_vec3			pos;
	double			ratio;
	t_color			color;
}					t_light;

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			dir;
}					t_ray;

typedef struct s_camera
{
	t_vec3			pos;
	t_vec3			dir;
	double			fov;
	t_vec3			right;
	t_vec3			up;
	double			half_w;
	double			half_h;
	int				width;
	int				height;
}					t_camera;

typedef struct s_scene
{
	t_ambient		*ambient;
	t_light			*light;
	t_camera		*camera;
	t_object		*objects;
}					t_scene;

typedef struct s_rt
{
	t_scene			scene;
	t_error_info	error;
	t_mlx			mlx;
}					t_rt;

#endif
