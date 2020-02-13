/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:25:04 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/13 13:29:46 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Breath First Search of All pathways
** Might change to bfs(start node, end node) ?
*/

void	bfs(t_node *start, t_node *end, t_paths **all_paths)
{
	int		i;
	t_paths	*q;
	t_node	*current;
	t_que	*path;
	t_que	*new_path;

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
			// ft_putstr("\nPath Found:\n");
			// print_queue(path);
			*all_paths = append_path(*all_paths, path);
			continue ;
		}
		if (!(current->visited))
		{
			i = 0;
			while (current->ngb && current->ngb[i])
			{
				new_path = NULL;
				new_path = que_copy(path);
				new_path = enqueue(new_path, current->ngb[i]);
				q = append_path(q, new_path);
				i++;
			}
		}
		current->visited = TRUE;
		que_delete(path);
	}
}
