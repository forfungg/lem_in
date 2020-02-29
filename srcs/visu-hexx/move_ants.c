/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:58:05 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/01 00:15:34 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static int		is_around(int num, int val, double step)
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

static int		is_antfinished(t_prop *xt)
{
	t_ant	*temp;
	t_node	*end;

	end = find_end(xt->elems);
	temp = xt->ants;
	while (temp)
	{
		if (temp->nextpos)
		{
			if (is_around(temp->x, temp->nextpos->nx, temp->stpx))
			{
				if (is_around(temp->y, temp->nextpos->ny, temp->stpy))
				{
					if (temp->curpos != end)
						return (1);
				}
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

static void		get_ant_steps(t_ant *ant)
{
	t_ant *temp;

	temp = ant;
	while (temp)
	{
		if (temp->nextpos)
		{
			temp->stpx = ft_abs(temp->nextpos->nx - temp->curpos->nx)\
				/ (double)FRAMES;
			temp->stpy = ft_abs(temp->nextpos->ny - temp->curpos->ny)\
				/ (double)FRAMES;
		}
		temp = temp->next;
	}
}

void			recalc_ant_movement(t_prop *xt)
{
	t_ant *temp;

	temp = xt->ants;
	get_ant_steps(temp);
	if (is_antfinished(xt) == 1)
	{
		move_ants(xt);
		if (xt->cpy)
			update_ant_positions(xt, xt->cpy->str);
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
