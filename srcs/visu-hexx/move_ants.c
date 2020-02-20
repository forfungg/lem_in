/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:58:05 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/20 12:32:55 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

int		is_around(int num, int val, double step)
{
	if (num < val)
	{
		if (num >= val - step)
			return (1);
	}
	if (num > val)
	{
		if (num <= val + step)
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

void	get_ant_steps(t_prop *xt)
{
	t_ant *temp;

	temp = xt->ants;
	while (temp)
	{
		if (temp->nextpos)
		{
			temp->stpx = (temp->nextpos->nx - temp->curpos->nx) / (double)FRAMES;
			temp->stpy = (temp->nextpos->ny - temp->curpos->ny) / (double)FRAMES;
		}
		temp = temp->next;
	}
}

void	recalc_ant_movement(t_prop *xt)
{
	t_ant *temp;

	temp = xt->ants;
	if (is_antfinished(xt) == 1)
	{
		move_ants(xt);
		if (xt->lines)
			update_ant_positions(xt, xt->lines->str);
	}
	else
	{
		get_ant_steps(xt);
		while (temp)
		{
			if (temp->nextpos)
				draw_ant_algo(temp);
			temp = temp->next;
		}
	}
}
