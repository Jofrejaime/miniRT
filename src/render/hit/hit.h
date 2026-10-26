/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:36:39 by jmutumbu          #+#    #+#             */
/*   Updated: 2026/08/18 15:36:41 by jmutumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "minirt.h"

# define EPSILON 1e-6
# define PARALLEL_EPSILON 1e-4

typedef struct s_hit
{
	double		t;

	t_vec3		point;
	t_vec3		normal;

	t_object	*object;

	int			front_face;
}				t_hit;

typedef struct s_quadratic
{
	double		a;
	double		b;
	double		c;
	double		delta;
}				t_quadratic;

/*
** hit.c
*/
t_vec3			ray_at(t_ray ray, double t);

void			hit_set_face_normal(t_hit *hit, t_ray ray,
					t_vec3 outward_normal);
void			hit_fill(t_hit *hit, t_ray ray, double t, t_vec3 normal);
/*
** hit_scene.c
*/
int				hit_scene(t_scene *scene, t_ray ray, t_hit *hit);

/*
** intersect_object.c
*/
int				intersect_object(t_ray ray, t_object *obj, t_hit *hit);

/*
** primitives
*/
int				intersect_sphere(t_ray ray, t_object *obj, t_hit *hit);

int				intersect_plane(t_ray ray, t_object *obj, t_hit *hit);

int				intersect_cylinder(t_ray ray, t_object *obj, t_hit *hit);

/* cylinder helpers (internal but reused across hit files) */
t_quadratic		cylinder_equation(t_ray ray, t_cylinder *cy);
double			cylinder_side_distance(t_ray ray, t_cylinder *cy);
double			cylinder_cap_t(t_ray ray, t_cylinder *cy, t_vec3 cap_center);
t_vec3			cylinder_side_normal(t_cylinder *cy, t_vec3 point);

double			smallest_positive_root(double t1, double t2);

#endif
