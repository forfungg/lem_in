/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:06:39 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 12:56:21 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Print Graph
*/

void		print_graph(t_node *graph)
{
	t_node	*tmp;
	int		i;

	tmp = graph;
	while (tmp)
	{
		ft_printf("%15s |", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
	while (graph)
	{
		if (graph->ngb)
		{
			i = 0;
			while (graph->ngb[i])
			{
				ft_printf("%s: %d, ", graph->ngb[i]->name, graph->cap[i]);
				i++;
			}
		}
		ft_printf("| ");
		graph = graph->next;
	}
	ft_printf("\n");
}

/*
** Print Debug stuff
*/

static int	count_paths(t_paths *p)
{
	int i;

	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void		print_debug(t_prop *xt)
{
	ft_printf("{GREEN}{B}{U}Lem-In Stats{EOC}\n");
	ft_printf("Ants:\t%d\n", xt->f_ants);
	ft_printf("Potentional Flow: %d\n", xt->pot_flow);
	ft_printf("Utilized Flow: %d\n", count_paths(xt->all_paths));
	ft_printf("Solution Lenght: %d\n", xt->out_len);
	ft_printf("Time to Process Input: %f sec\n",\
		ft_time_lapsed(xt->stopwatch->start,\
		xt->stopwatch->marks[0]->timestamp));
	ft_printf("Ford-Fulkerson Time: %f sec\n",\
		ft_time_lapsed(xt->stopwatch->marks[0]->timestamp,\
		xt->stopwatch->marks[1]->timestamp));
	ft_stop_timer(xt->stopwatch);
	ft_printf("Total Time: %f sec\n",\
		ft_time_lapsed(xt->stopwatch->start, xt->stopwatch->end));
	print_paths(xt->all_paths);
}
