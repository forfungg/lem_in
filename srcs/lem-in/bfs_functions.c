/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:25:04 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/17 18:17:44 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Breath First Search of All pathways
** Might change to bfs(start node, end node) ?
*/

static int		path_len(t_que *list)
{
	int cnt;

	cnt = 0;
	while (list)
	{
		cnt += 1;
		list = list->next;
	}
	return (cnt);
}

static int	not_in_path(t_que *path, t_node *node)
{
	while (path && path->next)
	{
		if (ft_strequ(path->node->name, node->name))
			return (FALSE);
		path = path->next;
	}
	return (TRUE);
}

static void	explore_ngbs(t_node *current, t_que *path, t_paths **q)
{
	t_que	*new_path;
	int		i;

	i = 0;
	while (current->ngb && current->ngb[i])
	{
		if (not_in_path(path, current->ngb[i]))
		{
			new_path = NULL;
			new_path = que_copy(path);
			new_path = enqueue(new_path, current->ngb[i]);
			*q = append_path(*q, new_path);
		}
		i++;
	}
}

void		bfs(t_node *start, t_node *end, t_paths **all_paths,\
				int ants)
{
	t_paths	*q;
	t_node	*current;
	t_que	*path;
	int		max_len;

	max_len = INT_MAX;
	q = NULL;
	path = NULL;
	if (!start || !end)
		return ;
	q = append_path(q, enqueue(path, start));
	while (q)
	{
		path = pop_path(&q);
		if (path_len(path) >= max_len)
			return ;
		current = que_getlast(path);
		if (current->end)
		{
			if (*all_paths == NULL)
				max_len = path_len(path) + ants / 2;
			*all_paths = append_path(*all_paths, path);
			print_queue(path);
			continue ;
		}
		if (not_in_path(path, current))
			explore_ngbs(current, path, &q);
		current->visited = TRUE;
		que_delete(path);
	}
}
