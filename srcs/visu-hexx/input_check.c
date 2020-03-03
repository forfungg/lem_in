/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:46:34 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/03 14:11:06 by jnovotny         ###   ########.fr       */
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

static int		check_lines(t_prop *xt)
{
	if (!xt->lines)
		return (1);
	else
		return (0);
}

void			check_input(t_prop *xt)
{
	int err;

	err = 0;
	err += check_n_start_end(xt);
	err += check_lines(xt);
	err += check_ants(xt);
	if (err != 0)
		error_exit("Input is incorrect");
	capacitize_ngbs(xt->elems);
}
