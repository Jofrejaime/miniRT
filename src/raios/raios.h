#ifndef RAIOS_H
# define RAIOS_H

# include "minirt.h"
# include "windows.h"
# include "vec3.h"
# include <math.h>

/* camera_build_basis.c */
void    camera_build_basis(t_camera *cam, double aspect_ratio);
t_ray   camera_get_ray(t_camera *cam, int px, int py, int width, int height);
void    render_test_gradient(t_camera *cam, t_img *img, int width, int height);

/* Wrapper for windows_ini to match expected function name */
static inline int window_init(t_mlx *mlx, int width, int height)
{
    return (windows_ini(mlx, width, height));
}

/* img_put_pixel - putpixel function for image */
static inline void img_put_pixel(t_img *img, int x, int y, int color)
{
    char    *dst;
    int     offset;

    offset = (y * img->line_len) + (x * (img->bpp / 8));
    dst = img->addr + offset;
    *(unsigned int *)dst = color;
}

#endif
