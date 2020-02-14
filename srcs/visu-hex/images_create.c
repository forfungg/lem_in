/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:30:39 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/14 17:16:59 by solopov          ###   ########.fr       */
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
		IMGS->room = mlx_new_image(MLX_PTR, IMGS->roomsize, IMGS->roomsize);
		IMGS->roomdat = (int *)mlx_get_data_addr(IMGS->room, &bpp, &size, &endian);
		fill_frame(IMGS->roomdat, IMGS->roomsize, IMGS->roomsize, 0x996633);
	}
}

void		create_background(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	IMGS->bg = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->bgdat = (int *)mlx_get_data_addr(IMGS->bg, &bpp, &size, &endian);
	fill_rectangle(IMGS->bgdat, W_W, W_H, 0x99ccff);
}

void	create_sand(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	IMGS->sand = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->sanddat = (int *)mlx_get_data_addr(IMGS->sand, &bpp, &size, &endian);
	fill_rectangle_pattern(IMGS->sanddat, W_W, W_H, 0xffcc99, 0xcc9966);
}

void	create_connections(t_prop *xt)
{
	t_node *temp;
	int cnt;

	temp = xt->elems;
	while (temp)
	{
		cnt = 0;
		while (temp->ngb[cnt] != 0)
		{
			connect_rooms(xt, temp, temp->ngb[cnt]);
			cnt += 1;
		}
		temp = temp->next;
	}
}

void	create_lines(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	IMGS->line = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->linedat = (int *)mlx_get_data_addr(IMGS->line, &bpp, &size, &endian);
	fill_rectangle(IMGS->linedat, W_W, W_H, 0xff000000);
	create_connections(xt);
}
