/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:30:55 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/17 11:05:26 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Creates queue node
*/

static t_que	*create_quenode(t_node *node)
{
	t_que *new_q;

	if (!(new_q = (t_que *)malloc(sizeof(t_que))))
		return (NULL);
	new_q->next = NULL;
	new_q->node = node;
	new_q->shift = 0;
	return (new_q);
}

/*
** Queues up a node
*/

t_que			*enqueue(t_que *head, t_node *node)
{
	t_que *tmp;

	if (head)
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_quenode(node);
		return (head);
	}
	else
		return (create_quenode(node));
}

/*
** Returns pointer to the first t_node in the queue.
** Removes it from the queue.
*/

static void		delete_qnode(t_que *node)
{
	if (!node)
		return ;
	free(node);
}

t_node			*que_getnext(t_que **queue)
{
	t_que	*tmp;
	t_node	*ret;

	if (!queue || !*queue)
		return (NULL);
	tmp = *queue;
	*queue = tmp->next;
	ret = tmp->node;
	delete_qnode(tmp);
	return (ret);
}

/*
** Copies given que and returns pointer to it's head
*/

t_que			*que_copy(t_que *node)
{
	t_que	*new;

	new = NULL;
	while (node)
	{
		new = enqueue(new, node->node);
		node = node->next;
	}
	return (new);
}
