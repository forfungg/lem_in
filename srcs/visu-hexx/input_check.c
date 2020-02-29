/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:46:34 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 23:36:00 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static int		check_n_start_end(t_prop *xt)
{
	t_node *temp;

	temp = xt->elems;
	if (xt->n_start != 1 || xt->n_end != 1)
		return (1);
	while (temp)
	{
		if (temp->start == 1 && temp->end == 1)
			error_exit("Wrong Input: Start == End");
		temp = temp->next;
	}
	return (0);
}

static int		check_ants(t_prop *xt)
{
	if (xt->n_ants != 1)
		return (1);
	if (xt->f_ants < 1)
		return (1);
	return (0);
}

static int		get_len(t_node **array)
{
	int cnt;

	cnt = 0;
	if (!array)
		return (0);
	while (array[cnt] != 0)
		cnt += 1;
	return (cnt);
}

static int		check_duplicate(t_node **array)
{
	int x;
	int y;
	int len;

	if (!array)
		return (0);
	x = 0;
	len = get_len(array);
	while (x < len)
	{
		y = x + 1;
		while (y < len)
		{
			if (ft_strequ(array[x]->name, array[y]->name) == 1)
				return (1);
			y += 1;
		}
		x += 1;
	}
	return (0);
}

void			check_input(t_prop *xt)
{
	int err;

	err = 0;
	err += check_n_start_end(xt);
	err += check_ants(xt);
	if (err != 0)
		error_exit("Input is incorrect");
	capacitize_ngbs(xt->elems);
}
