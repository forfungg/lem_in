/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:19:13 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/22 20:36:47 by jnovotny         ###   ########.fr       */
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
	que_delete(path);
}

/*
** Ford-Fulkerson max flow algorithm
** while bfs paths exits
*/

int		ford_fulkerson(t_prop *xt)
{
	int		max_flow;
	t_que	*i;
	t_paths	*parents;
	t_paths	*best;

	max_flow = 0;
	parents = NULL;
	best = NULL;
	while ((i = bfs(START, END)))
	{
		ft_printf("FF new augment path: ");
		print_queue(i);
		max_flow += CAPACITY;
		augment_path(i);
		reset_visits(START);
		delete_paths(xt->all_paths);
		xt->all_paths = NULL;
		get_flow_paths(START, END, &(xt->all_paths));
		if (len_solution(best, ANTS) > len_solution(xt->all_paths, ANTS))
			new_solution(&best, &(xt->all_paths));
		else if (!FF_ALL)
			break ;
		reset_visits(START);
	}
	delete_paths(parents);
	delete_paths(xt->all_paths);
	// print_paths(best);
	xt->all_paths = best;
	return (max_flow);
}
