/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_build_basis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 09:35:45 by lvitorin          #+#    #+#             */
/*   Updated: 2026/08/06 09:35:48 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"
#include "raios.h"

void    camera_build_basis(t_camera *cam, double aspect_ratio)
{
    t_vec3  world_up;
    t_vec3  reference;
    double  fov_rad;

    world_up = (t_vec3){0.0, 1.0, 0.0};
    cam->dir = vec3_normalize(cam->dir);
    reference = world_up;
    if (fabs(vec3_dot(cam->dir, reference)) > 0.999)
        reference = (t_vec3){1.0, 0.0, 0.0};
    cam->right = vec3_normalize(vec3_cross(cam->dir, reference));
    cam->up = vec3_cross(cam->dir, cam->right);
    fov_rad = cam->fov * M_PI / 180.0;
    cam->half_w = tan(fov_rad / 2.0);
    cam->half_h = cam->half_w / aspect_ratio;
}

t_ray   camera_get_ray(t_camera *cam, int px, int py, int width, int height)
{
    t_ray   ray;
    double  u;
    double  v;
    t_vec3  dir;

    u = (px + 0.5) / width * 2.0 - 1.0;
    v = -(((py + 0.5) / height * 2.0 - 1.0));
    dir = vec3_add(cam->dir, vec3_add(vec3_scale(cam->right, u * cam->half_w), 
        vec3_scale(cam->up, v * cam->half_h)));
    ray.origin = cam->pos;
    ray.dir = dir;
    return (ray);
}

void render_test_gradient(t_camera *cam, t_img *img, int width, int height)
{
    int     x;
    int     y;
    t_ray   ray;
    int     color;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            ray = camera_get_ray(cam, x, y, width, height);
            color = ((int)((ray.dir.x + 1.0) * 0.5 * 255) << 16)
                  | ((int)((ray.dir.y + 1.0) * 0.5 * 255) << 8)
                  | ((int)(((x % 100) / 100.0) * 255));
            img_put_pixel(img, x, y, color);
            x++;
        }
        y++;
    }
}