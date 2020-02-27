/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:00:07 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/27 13:26:35 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"
#include <math.h>

double		get_size(int x, int y, int nb)
{
	double	px;
	double	sx;
	double	sy;
	double	py;

	px = ceil(sqrt(nb * x / y));
	if (floor(px * y / x) * px < nb)
		sx = y / ceil(px * y / x);
	else
		sx = x / px;
	py = ceil(sqrt(nb * y / x));
	if (floor(py * x / y) * py < nb)
		sy = x / ceil(x * py / y);
	else
		sy = y / py;
	if (sx > sy)
		return (sx) * 0.25;
	else
		return (sy) * 0.25;
}

void		create_uniroom(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	t_node	*temp;
	int		y;
	int		x;
	int		color;

	y = 0;
	x = 0;
	temp = xt->elems;
	IMGS->roomsize = get_size(W_W, W_H, xt->n_rooms);
	IMGS->uniroom = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->uniroomdat = (int *)mlx_get_data_addr(IMGS->uniroom, &bpp, &size, &endian);
	fill_rectangle(IMGS->uniroomdat, W_W, W_H, 0xff000000);
	while (temp)
	{
		if (temp->start == 1)
			color = 0x00ff40;
		else if (temp->end == 1)
			color = 0xff4000;
		else
			color = 0x996633;
		temp->nx = get_cor_x(temp->x, xt);
		temp->ny = get_cor_y(temp->y, xt);
		while (y++ < IMGS->roomsize)
		{
			x = 0;
			while (x++ < IMGS->roomsize)
				IMGS->uniroomdat[(temp->ny + y) * W_W + (temp->nx + x)] = color;
		}
		y = 0;
		temp = temp->next;
	}
}
