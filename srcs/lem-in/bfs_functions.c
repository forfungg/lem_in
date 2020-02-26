/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:25:04 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/22 20:40:14 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Breath First Search
*/

static void	explore_ngbs(t_node *current, t_que *path, t_paths **q)
{
	t_que	*new_path;
	int		i;

	i = 0;
	while (current->ngb && current->ngb[i])
	{
		if (!(current->ngb[i]->visited) && current->cap[i] > 0)
		{
			current->ngb[i]->visited = TRUE;
			new_path = NULL;
			new_path = que_copy(path);
			new_path = enqueue(new_path, current->ngb[i]);
			*q = append_path(*q, new_path);
		}
		i++;
	}
}

t_que		*bfs(t_node *start, t_node *end)
{
	t_paths	*q;
	t_node	*current;
	t_que	*path;

	q = NULL;
	path = NULL;
	if (!start || !end)
		return (FALSE);
	q = append_path(q, enqueue(path, start));
	start->visited = TRUE;
	while (q)
	{
		path = pop_path(&q);
		current = que_getlast(path);
		if (current->end)
		{
			delete_paths(q);
			return (path);
		}
		explore_ngbs(current, path, &q);
		que_delete(path);
	}
	return (NULL);
}
