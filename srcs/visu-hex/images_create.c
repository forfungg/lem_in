/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:30:39 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/14 14:24:04 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"
#include <math.h>

double		get_size(int x, int y, int nb)
{
	double	px;
	double	sx;
	double	sy;

	px = ceil(sqrt(nb * x / y));
	if (floor(px * y / x) * px < nb)
        sx = y / ceil(px * y / x);
    else
        sx = x / px;
    double py = ceil(sqrt(nb * y / x));
    if (floor(py * x / y) * py < nb)
        sy = x / ceil(x * py / y);
    else
        sy = y / py;
    if (sx > sy)
		return (sx) * 0.25;
	else
		return (sy) * 0.25;
}

void		create_room(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	IMGS->roomsize = get_size(W_W, W_H, xt->n_rooms);
	if (xt->n_rooms != 0)
	{
		xt->imgs->room = mlx_new_image(MLX_PTR, IMGS->roomsize, IMGS->roomsize);
		IMGS->roomdat = (int *)mlx_get_data_addr(IMGS->room, &bpp, &size, &endian);
		fill_frame(IMGS->roomdat, IMGS->roomsize, IMGS->roomsize, 0x996633);
	}
}

void		create_background(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	xt->imgs->bg = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->bgdat = (int *)mlx_get_data_addr(IMGS->bg, &bpp, &size, &endian);
	fill_rectangle(IMGS->bgdat, W_W, W_H, 0x99ccff);
}

void	create_sand(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	xt->imgs->sand = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->sanddat = (int *)mlx_get_data_addr(IMGS->sand, &bpp, &size, &endian);
	fill_rectangle_pattern(IMGS->sanddat, W_W, W_H, 0xffcc99, 0xcc9966);
}
