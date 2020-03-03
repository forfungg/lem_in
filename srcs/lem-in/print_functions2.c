/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:06:39 by jnovotny          #+#    #+#             */
/*   Updated: 2020/03/03 20:55:05 by jnovotny         ###   ########.fr       */
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

static void	print_debug2(t_prop *xt)
{
	if (BFS)
	{
		ft_printf("Augmenting Paths\n");
		print_paths(xt->augment_paths);
	}
	ft_printf("\nSolution Paths\n");
	print_paths(xt->all_paths);
}

void		print_debug(t_prop *xt)
{
	print_logo();
	ft_printf("{GREEN}{B}{U}Lem-In Stats{EOC}\n\n");
	ft_printf("{LIGHT}Input size (chars):\t%lu\n{EOC}",\
		(unsigned long)(xt->input_length));
	ft_printf("Input size (lines):\t%lu\n", (unsigned long)(xt->input_lines));
	ft_printf("{LIGHT}Ants:\t\t\t%d\n{EOC}", xt->f_ants);
	ft_printf("Amount of Vertices:\t%lu\n", count_nodes(xt->elems));
	ft_printf("{LIGHT}Amount of Edges:\t%lu\n{EOC}", count_edges(xt->elems));
	ft_printf("Potentional Flow:\t%d\n", xt->pot_flow);
	ft_printf("{LIGHT}Utilized Flow:\t\t%d\n{EOC}", count_paths(xt->all_paths));
	ft_printf("Solution Lenght:\t%d\n", xt->out_len);
	ft_printf("{LIGHT}Time to Process Rooms:\t%f sec\n{EOC}",\
		ft_time_lapsed(xt->stopwatch->start,\
		xt->stopwatch->marks[0]->timestamp));
	ft_printf("Time to Process Links:\t%f sec\n",\
		ft_time_lapsed(xt->stopwatch->marks[0]->timestamp,\
		xt->stopwatch->marks[1]->timestamp));
	ft_printf("{LIGHT}Time to Process Input:\t%f sec\n{EOC}",\
		ft_time_lapsed(xt->stopwatch->start,\
		xt->stopwatch->marks[1]->timestamp));
	ft_printf("Ford-Fulkerson Time:\t%f sec\n",\
		ft_time_lapsed(xt->stopwatch->marks[1]->timestamp,\
		xt->stopwatch->marks[2]->timestamp));
	ft_stop_timer(xt->stopwatch);
	ft_printf("{LIGHT}Total Time:\t\t%f sec\n\n{EOC}",\
		ft_time_lapsed(xt->stopwatch->start, xt->stopwatch->end));
	print_debug2(xt);
}
