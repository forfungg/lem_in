/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:54:49 by solopov           #+#    #+#             */
/*   Updated: 2020/02/18 15:20:31 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

static void	increment_x(int *img, t_prop *xt, t_node *beg, t_node *end)
{
	int		error;
	t_pcur	*pcur;
	int		cnt;

	cnt = 0;
	pcur = (t_pcur *)malloc(sizeof(t_pcur));
	error = (2 * xt->dy) - xt->dx;
	pcur->y = beg->ny;
	pcur->x = beg->nx + xt->stpx;
	img[beg->ny * W_W + beg->nx] = xt->color;
	while (cnt++ <= xt->dx - 1)
	{
		if (error > 0)
		{
			error = error + 2 * (xt->dy - xt->dx);
			pcur->y += xt->stpy;
		}
		else
			error = error + 2 * xt->dy;
		img[pcur->y * W_W + pcur->x] = xt->color;
		pcur->x += xt->stpx;
	}
	free(pcur);
}

static void	increment_y(int *img, t_prop *xt, t_node *beg, t_node *end)
{
	int		error;
	t_pcur	*pcur;
	int		cnt;

	cnt = 0;
	pcur = (t_pcur *)malloc(sizeof(t_pcur));
	error = (2 * xt->dx) - xt->dy;
	pcur->x = beg->nx;
	pcur->y = beg->ny + xt->stpy;
	img[beg->ny * W_W + beg->nx] = xt->color;
	while (cnt++ <= xt->dy - 1)
	{
		if (error > 0)
		{
			error = error + 2 * (xt->dx - xt->dy);
			pcur->x += xt->stpx;
		}
		else
			error = error + 2 * xt->dx;
		img[pcur->y * W_W + pcur->x] = xt->color;
		pcur->y += xt->stpy;
	}
	free(pcur);
}

static int	ft_abs(int x)
{
	return (x > 0 ? x : -x);
}

void	connect_nodes(int *image, t_prop *xt, t_node *beg, t_node *end)
{
	xt->dx = ft_abs(end->nx - beg->nx);
	xt->dy = ft_abs(end->ny - beg->ny);
	xt->stpx = end->nx >= beg->nx ? 1 : -1;
	xt->stpy = end->ny >= beg->ny ? 1 : -1;
	if (xt->dx > xt->dy)
		increment_x(image, xt, beg, end);
	else
		increment_y(image, xt, beg, end);
}
