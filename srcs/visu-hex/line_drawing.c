/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:54:49 by solopov           #+#    #+#             */
/*   Updated: 2020/02/14 17:16:39 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

static void	increment_x(t_prop *xt, t_node *beg, t_node *end, int cnt)
{
	int		error;
	t_pcur	*pcur;

	pcur = (t_pcur *)malloc(sizeof(t_pcur));
	error = (2 * xt->dy) - xt->dx;
	pcur->y = beg->ny;
	pcur->x = beg->nx + xt->stpx;
	IMGS->linedat[beg->ny * W_W + beg->nx] = 0x00ff00;
	while (cnt++ <= xt->dx - 1)
	{
		if (error > 0)
		{
			error = error + 2 * (xt->dy - xt->dx);
			pcur->y += xt->stpy;
		}
		else
			error = error + 2 * xt->dy;
		IMGS->linedat[pcur->y * W_W + pcur->x] = 0x00ff00;
		pcur->x += xt->stpx;
	}
	free(pcur);
}

static void	increment_y(t_prop *xt, t_node *beg, t_node *end, int cnt)
{
	int		error;
	t_pcur	*pcur;

	pcur = (t_pcur *)malloc(sizeof(t_pcur));
	error = (2 * xt->dx) - xt->dy;
	pcur->x = beg->nx;
	pcur->y = beg->ny + xt->stpy;
	IMGS->linedat[beg->ny * W_W + beg->nx] = 0x00ff00;
	while (cnt++ <= xt->dy - 1)
	{
		if (error > 0)
		{
			error = error + 2 * (xt->dx - xt->dy);
			pcur->x += xt->stpx;
		}
		else
			error = error + 2 * xt->dx;
		IMGS->linedat[pcur->y * W_W + pcur->x] = 0x00ff00;
		pcur->y += xt->stpy;
	}
	free(pcur);
}

static int	ft_abs(int x)
{
	return (x > 0 ? x : -x);
}

void	connect_rooms(t_prop *xt, t_node *beg, t_node *end)
{
	int cnt;

	cnt = 0;
	xt->dx = ft_abs(end->nx - beg->nx);
	xt->dy = ft_abs(end->ny - beg->ny);
	xt->stpx = end->nx >= beg->nx ? 1 : -1;
	xt->stpy = end->ny >= beg->ny ? 1 : -1;
	if (xt->dx > xt->dy)
		increment_x(xt, beg, end, cnt);
	else
		increment_y(xt, beg, end, cnt);
}