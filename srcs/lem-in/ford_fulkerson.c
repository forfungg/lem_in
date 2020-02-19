/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:19:13 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/19 14:23:26 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Get pointer to the last path
*/

static t_que	*get_p_last(t_paths *paths)
{
	t_paths	*tmp;

	if (!paths)
		return (NULL);
	tmp = paths;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->path);
}

static void	augment_path(t_que *path)
{
	t_que	*tmp;
	t_node	*a;
	t_node	*b;
	int		i;

	if (!path)
		return ;
	tmp = path;
	while (tmp && tmp->next)
	{
		a = tmp->node;
		b = tmp->next->node;
		i = 0;
		while (a->ngb[i])
		{
			if (ft_strequ(a->ngb[i]->name, b->name))
				break ;
			i++;
		}
		a->cap[i] = 0;
		i = 0;
		while (b->ngb[i])
		{
			if (ft_strequ(b->ngb[i]->name, a->name))
				break ;
			i++;
		}
		b->cap[i] = 1;
		tmp = tmp->next;
	}
}

/*
** Ford-Fulkerson max flow algorithm
** while bfs paths exits
*/

int		ford_fulkerson(t_node *graph, t_paths **all_paths)
{
	int		max_flow;
	t_que	*i;

	max_flow = 0;
	while (bfs(find_start(graph), find_end(graph), all_paths))
	{
		i = get_p_last(*all_paths);
		if (i == NULL)
			error_exit("FUCK THIS SHIT FUCK!");
		max_flow += CAPACITY;
		augment_path(i);
		reset_visits(graph);
		// print_graph(graph);
	}
	return (max_flow);
}
