/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:58:55 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/19 15:01:35 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

static int	ft_abs(int x)
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

void	increment_x(t_ant *ant, int dx, int dy)
{
	if (ant->error >= 0)
	{
		ant->error = ant->error - ant->stpy * (dy - dx);
		ant->y += ant->stpy;
	}
	else
		ant->error = ant->error - ant->stpy * dy;
	ant->x += ant->stpx;
}

void	increment_y(t_ant *ant, int dx, int dy)
{
	if (ant->error >= 0)
	{
		ant->error = ant->error - ant->stpx * (dx - dy);
		ant->x += ant->stpx;
	}
	else
		ant->error = ant->error - ant->stpx * dx;
	ant->y += ant->stpy;
}

void	draw_ant_algo(t_ant *ant)
{
	int	dx;
	int	dy;

	dx = ft_abs(ant->nextpos->nx - ant->curpos->nx);
	dy = ft_abs(ant->nextpos->ny - ant->curpos->ny);
	if (dx > dy)
		increment_x(ant, dx, dy);
	else
		increment_y(ant, dx, dy);
}
