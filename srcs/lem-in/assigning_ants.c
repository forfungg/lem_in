/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:59:07 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/26 18:59:41 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_len(t_que *list)
{
	int cnt;

	cnt = 0;
	while (list)
	{
		cnt += 1;
		list = list->next;
	}
	return (cnt);
}

int		get_t_len(t_paths *paths)
{
	int total;

	total = 0;
	total += get_len(paths->path);
	total += paths->ants;
	return (total);
}

void	several(int ants, t_paths *paths)
{
	t_paths	*tmp;
	int		len;

	if (!paths)
		return ;
	ants = first_square(paths, ants);
	while (ants > 0)
	{
		tmp = shortest_path(paths);
		tmp->ants += 1;
		ants--;
	}
	tmp = paths;
	while (tmp)
	{
		tmp->dbg_a = tmp->ants;
		tmp = tmp->next;
	}
}

void	assign_ants(t_prop *xt)
{
	if (xt->all_paths->next)
		several(xt->f_ants, xt->all_paths);
	else
		xt->all_paths->ants = xt->f_ants;
	move_ants(xt, xt->all_paths);
}
