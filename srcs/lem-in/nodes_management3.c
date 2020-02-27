/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_management3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:39:15 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 17:39:04 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Returns the ending node of the graph
*/

t_node			*find_end(t_node *list)
{
	while (list)
	{
		if (list->end)
			return (list);
		list = list->next;
	}
	return (NULL);
}

/*
** Counts amount of nodes in the list
*/

unsigned long	count_nodes(t_node *head)
{
	unsigned long	cnt;

	cnt = 0;
	while (head)
	{
		cnt++;
		head = head->next;
	}
	return (cnt);
}

/*
**  Counts total amount of neighbors -> endges in the graph
*/

unsigned long	count_edges(t_node *head)
{
	unsigned long	cnt;

	cnt = 0;
	while (head)
	{
		if (head->ngb)
			cnt += count_neighbors(head->ngb);
		head = head->next;
	}
	return (cnt / 2);
}
