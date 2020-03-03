/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_management2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:46:44 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/02 11:56:20 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int				add_neighbor(t_prop *xt, t_node *node, t_node *neighbor)
{
	if (!node || !neighbor)
		return (FALSE);
	if (node->ngb == NULL)
	{
		create_neighbor(node, neighbor);
		xt->n_links += 1;
	}
	else
	{
		if (already_exists(node, neighbor->name))
			return (TRUE);
		append_neighbor(node, neighbor);
		xt->n_links += 1;
	}
	return (TRUE);
}

/*
** Counts amount of neighbors of the given node
*/

int				count_neighbors(t_node **neighbors)
{
	int		count;

	count = 0;
	while (neighbors[count])
		count++;
	return (count);
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
			if (!list->cap)
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
