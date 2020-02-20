/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:58:05 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/20 20:17:56 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

int		is_around(int num, int val, double step)
{
	ft_printf("NUM %d AGAINST %d\n", num, val);
	if (num < val)
	{
		if (num >= val * 0.999)
			return (1);
	}
	if (num > val)
	{
		if (num <= val * 1.001)
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
			ft_printf(" WHEN CHECKING NEXTPOS X: %d, NEXTPOS Y: %d\n", temp->nextpos->nx, temp->nextpos->ny);
			ft_printf("CUR POS X: %f, CUR POS Y: %f\n", temp->x, temp->y);
			if (is_around(temp->x, temp->nextpos->nx, temp->stpx) || is_around(temp->y, temp->nextpos->ny, temp->stpy))
			{
				if (temp->curpos != end)
					return (1);
			}
		}
		temp = temp->next;
	}
	return (0);
}

void	get_ant_steps(t_ant *ant)
{
	t_ant *temp;

	temp = ant;
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
		get_ant_steps(temp);
		while (temp)
		{
			if (temp->nextpos)
				draw_ant_algo(temp);
			temp = temp->next;
		}
	}
}
