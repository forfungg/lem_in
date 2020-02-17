/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:00:07 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/17 16:06:05 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"
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

void		create_room(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	t_node	*temp;

	temp = xt->elems;
	IMGS->roomsize = get_size(W_W, W_H, xt->n_rooms);
	while (temp)
	{
		temp->nx = get_cor_x(temp->x, xt);
		temp->ny = get_cor_y(temp->y, xt);
		temp = temp->next;
	}
	if (xt->n_rooms != 0)
	{
		IMGS->room = mlx_new_image(MLX_PTR, IMGS->roomsize, IMGS->roomsize);
		IMGS->roomdat = (int *)mlx_get_data_addr(IMGS->room, &bpp, &size, &endian);
		fill_frame(IMGS->roomdat, IMGS->roomsize, IMGS->roomsize, 0x996633);
	}
}

void	create_start(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	if (xt->n_rooms != 0)
	{
		IMGS->start = mlx_new_image(MLX_PTR, IMGS->roomsize, IMGS->roomsize);
		IMGS->startdat = (int *)mlx_get_data_addr(IMGS->start, &bpp, &size, &endian);
		fill_frame(IMGS->startdat, IMGS->roomsize, IMGS->roomsize, 0x99ffcc);
	}
}

void	create_end(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	if (xt->n_rooms != 0)
	{
		IMGS->end = mlx_new_image(MLX_PTR, IMGS->roomsize, IMGS->roomsize);
		IMGS->enddat = (int *)mlx_get_data_addr(IMGS->end, &bpp, &size, &endian);
		fill_frame(IMGS->enddat, IMGS->roomsize, IMGS->roomsize, 0xff99cc);
	}
}
