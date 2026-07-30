/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:29:47 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/30 13:29:48 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "windows.h"

int windows_ini(t_mlx *mlx, int width, int height)
{
    mlx->mlx = mlx_init();
    if (!mlx->mlx)
        return (-1);
    mlx->win = mlx_new_window(mlx->mlx, width, height, "miniRT");
    if (!mlx->win)
        return (-1);
    mlx->image.mlx_img = mlx_new_image(mlx->mlx, width, height);
    if (!mlx->image.mlx_img)
        return (-1);
    mlx->image.addr = mlx_get_data_addr(mlx->image.mlx_img,
            &mlx->image.bpp, &mlx->image.line_len, &mlx->image.endian);
    return (0);
}