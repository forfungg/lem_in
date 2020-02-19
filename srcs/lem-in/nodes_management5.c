/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_management5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:52:11 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/19 12:16:14 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Resets "visited" value of all nodes in the list
*/

void			reset_visits(t_node *list)
{
	while (list)
	{
		list->visited = FALSE;
		list = list->next;
	}
}

/*
** Create capacities for edges
*/

void			capacitize_ngbs(t_node *list)
{
	int i;
	int	cnt;

	while (list)
	{
		if (list->ngb)
		{
			cnt = count_neighbors(list->ngb);
			list->cap = (int *)ft_memalloc(sizeof(int) * cnt);
			if (!(list->cap))
				error_exit("Malloc at capacitize_ngbs");
			i = 0;
			while (i < cnt)
				list->cap[i++] = CAPACITY;
		}
		list = list->next;
	}
}
