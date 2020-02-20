/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:19:13 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/20 14:13:20 by jnovotny         ###   ########.fr       */
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

int		ford_fulkerson(t_node *graph, t_paths **all_paths, int ants)
{
	int		max_flow;
	t_que	*i;
	t_paths	*parents;
	t_paths	*best;

	ft_printf("init ff\n");
	max_flow = 0;
	parents = NULL;
	best = NULL;
	while (bfs(find_start(graph), find_end(graph), &parents))
	{
		i = get_p_last(parents);
		max_flow += CAPACITY;
		augment_path(i);
		reset_visits(graph);
		delete_paths(*all_paths);
		*all_paths = NULL;
		get_flow_paths(find_start(graph), find_end(graph), all_paths);
		if (len_solution(best, ants) > len_solution(*all_paths, ants))
			new_solution(&best, all_paths);
		else if (!FF_ALL)
			break ;
		reset_visits(graph);
	}
	delete_paths(parents);
	delete_paths(*all_paths);
	*all_paths = best;
	return (max_flow);
}
