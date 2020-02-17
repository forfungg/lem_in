/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:30:55 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/17 11:05:17 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Deletes the queue
*/

void			que_delete(t_que *head)
{
	t_que *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/*
** Returns pointer to the last graph_node of the queue
*/

t_node			*que_getlast(t_que *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head->node);
}
