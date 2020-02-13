/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:11:02 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/13 15:16:41 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_n_start_end(t_prop *xt)
{
	t_node *temp;

	temp = xt->elems;
	if (xt->n_start != 1 || xt->n_end != 1)
		return (1);
	while (temp)
	{
		if (temp->start == 1 && temp->end == 1)
			error_exit("WHAT DO I DO???");
		temp = temp->next;
	}
	return (0);
}

static int	check_ants(t_prop *xt)
{
	if (xt->n_ants != 1)
		return (1);
	if (xt->f_ants < 1)
		return (1);
	return (0);
}

static int	get_len(t_node **array)
{
	int cnt;

	cnt = 0;
	if (!array)
		return (0);
	while (array[cnt] != 0)
		cnt += 1;
	return (cnt);
}

static int	check_duplicate(t_node **array)
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

static int	check_duplicate_ngb(t_prop *xt)
{
	int cnt;
	int len;
	t_node *temp;

	temp = xt->elems;
	while (temp != 0)
	{
		if (check_duplicate(temp->ngb) == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	check_input(t_prop *xt)
{
	int err;

	err = 0;
	err += check_n_start_end(xt);
	err += check_ants(xt);
	//err += check_duplicate_ngb(xt);
	if (err != 0)
		error_exit("Input is shit");
}
