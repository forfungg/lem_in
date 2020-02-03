/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:25:04 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/03 10:26:29 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Breath First Search of All pathways
** Might change to bfs(start node, end node) ?
*/

void	bfs(t_node *start, t_node *end)
{
	int		i;
	t_que	*q;
	t_node	*current;
	t_que	*path;

	q = NULL;
	path = NULL;
	if (!start || !end)
		return ;
	q = enqueue(q, start);
	while (q)
	{
		current = que_getnext(&q);
		if (!(current->visited))
		{
			path = enqueue(path, current);
			i = 0;
			while (current->ngb && current->ngb[i])
			{
				q = enqueue(q, current->ngb[i]);
				if (current->ngb[i]->end)
				{
					path = enqueue(path, current->ngb[i]);
					ft_putstr("\nShorthest path:\n");
					print_queue(path);
					return ;
				}
				i++;
			}
		}
		current->visited = TRUE;
		print_queue(q);
	}
}
