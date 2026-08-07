#ifndef WINDOWS_H
# define WINDOWS_H

#include "mlx.h"

typedef struct s_rt t_rt;

typedef struct s_img
{
    void    *mlx_img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    t_img   image;
    
}   t_mlx;

int windows_ini(t_mlx *mlx, int width, int height, t_rt *rt);

#endif