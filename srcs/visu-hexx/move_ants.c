/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:58:05 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/27 13:27:06 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int		is_around(int num, int val, double step)
{
	if (num <= val)
	{
		if (num >= val - step * 2)
			return (1);
	}
	if (num >= val)
	{
		if (num <= val + step * 2)
			return (1);
	}
	return (0);
}

int		is_antfinished(t_prop *xt)
{
	t_ant	*temp;
	t_node	*end;

	end = find_end(xt->elems);
	temp = xt->ants;
	while (temp)
	{
		if (temp->nextpos)
		{
			//ft_printf("STEP X: %f,	STEP Y: %f\n", temp->stpx, temp->stpy);
			//ft_printf("NEXTPOS X: %d,	NEXTPOS Y: %d\n", temp->nextpos->nx, temp->nextpos->ny);
			//ft_printf("CUR POS X: %f,	CUR POS Y: %f\n", temp->x, temp->y);
			if (is_around(temp->x, temp->nextpos->nx, temp->stpx) && is_around(temp->y, temp->nextpos->ny, temp->stpy))
			{
				if (temp->curpos != end)
					return (1);
			}
		}
		temp = temp->next;
	}
	return (0);
}

static double	ft_abs(double x)
{
	return (x > 0 ? x : -x);
}

void	get_ant_steps(t_ant *ant)
{
	t_ant *temp;

	temp = ant;
	while (temp)
	{
		if (temp->nextpos)
		{
			temp->stpx = ft_abs(temp->nextpos->nx - temp->curpos->nx) / (double)FRAMES;
			temp->stpy = ft_abs(temp->nextpos->ny - temp->curpos->ny) / (double)FRAMES;
		}
		temp = temp->next;
	}
}

void	recalc_ant_movement(t_prop *xt)
{
	t_ant *temp;

	temp = xt->ants;
	get_ant_steps(temp);
	if (is_antfinished(xt) == 1)
	{
		move_ants(xt);
		if (xt->lines)
			update_ant_positions(xt, xt->lines->str);
	}
	else
	{
		while (temp)
		{
			if (temp->nextpos)
				draw_ant_algo(temp);
			temp = temp->next;
		}
	}
}
