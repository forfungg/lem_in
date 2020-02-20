/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:25:04 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/17 14:17:06 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

/*
** Breath First Search of All pathways
** Might change to bfs(start node, end node) ?
*/

static void	explore_ngbs(t_node *current, t_que *path, t_paths **q)
{
	t_que	*new_path;
	int		i;

	i = 0;
	while (current->ngb && current->ngb[i])
	{
		new_path = NULL;
		new_path = que_copy(path);
		new_path = enqueue(new_path, current->ngb[i]);
		*q = append_path(*q, new_path);
		i++;
	}
}

void		bfs(t_node *start, t_node *end, t_paths **all_paths)
{
	t_paths	*q;
	t_node	*current;
	t_que	*path;

	q = NULL;
	path = NULL;
	if (!start || !end)
		return ;
	q = append_path(q, enqueue(path, start));
	while (q)
	{
		path = pop_path(&q);
		current = que_getlast(path);
		if (current->end)
		{
			*all_paths = append_path(*all_paths, path);
			continue ;
		}
		if (!(current->visited))
			explore_ngbs(current, path, &q);
		current->visited = TRUE;
		que_delete(path);
	}
}
