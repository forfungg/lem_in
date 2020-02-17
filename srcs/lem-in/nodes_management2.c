/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_management2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:39:15 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/17 11:12:07 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Adds node to the front of the list and returs a pointer to it
*/

t_node	*add_front(t_node *head, t_node *node)
{
	if (!node)
		return (head);
	else
	{
		node->next = head;
		return (node);
	}
}

/*
** Adds the node at the back of the list and returns a pointer to head
*/

t_node	*add_back(t_node *head, t_node *node)
{
	t_node *tmp;

	if (!head)
		return (node);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (head);
}

/*
**	Returns pointer to a node with corresponding name, otherwise NULL
*/

t_node	*find_node(t_node *head, char *name)
{
	t_node *tmp;

	tmp = head;
	while (tmp)
	{
		if (ft_strequ(name, tmp->name))
			break ;
		else
			tmp = tmp->next;
	}
	return (tmp);
}

/*
** Counts amount of neighbors of the given node
*/

int		count_neighbors(t_node **neighbors)
{
	int		count;

	count = 0;
	while (neighbors[count])
		count++;
	return (count);
}

/*
** Returns the starting node of the graph
*/

t_node	*find_start(t_node *list)
{
	while (list)
	{
		if (list->start)
			return (list);
		list = list->next;
	}
	return (NULL);
}
