/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:58:55 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 19:52:16 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"
#include <math.h>

static double	ft_abs(double x)
{
	return (x > 0 ? x : -x);
}

void	move_ants(t_prop *xt)
{
	t_ant	*temp;
	t_node	*end;

	end = find_end(xt->elems);
	temp = xt->ants;
	while (temp)
	{
		if (temp->nextpos && temp->curpos != end)
		{
			temp->curpos = temp->nextpos;
			temp->x = temp->nextpos->nx;
			temp->y = temp->nextpos->ny;
		}
		temp = temp->next;
	}
}

void	draw_ant_algo(t_ant *ant)
{
	double		dx;
	double		dy;
	double		err;
	double		direction;
	double		speed;

	dx = (ant->nextpos->nx - ant->curpos->nx);
	dy = (ant->nextpos->ny - ant->curpos->ny);
	direction = atan2(dy, dx);
	speed = sqrt(ant->stpx * ant->stpx + ant->stpy * ant->stpy);
	ant->x = ant->x + (speed * cos(direction));
	ant->y = ant->y + (speed * sin(direction));
}
