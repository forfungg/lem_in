/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:06:39 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/26 20:56:31 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Prints Colony information
** Ants, Start, End, Rest of Nodes, Edges
*/

void	print_colony(t_prop *xt)
{
	ft_printf("#Amount of ants\n%d\n", xt->f_ants);
	ft_printf("##start\n%s %d %d\n", xt->elems->name, xt->elems->x,\
		xt->elems->y);
	ft_printf("##end\n%s %d %d\n", xt->end_node->name, xt->end_node->x,\
		xt->end_node->y);
	ft_printf("#Other Rooms\n");
	print_list(xt->elems);
	ft_printf("#Edges\n");
	ft_putendl(xt->pathways);
}

void	print_list(t_node *head)
{
	while (head)
	{
		if (!head->start && !head->end)
			ft_printf("%s %d %d\n", head->name, head->x, head->y);
		head = head->next;
	}
}

void	print_edges(t_node *head)
{
	int i;

	while (head)
	{
		if (head->ngb)
		{
			i = 0;
			while (head->ngb[i])
			{
				ft_printf("%s-%s\n", head->name, head->ngb[i]->name);
				i++;
			}
		}
		head = head->next;
	}
}

void	print_queue(t_que *queue)
{
	int i;

	if (!queue)
		return ;
	ft_printf("%s", queue->node->name);
	queue = queue->next;
	while (queue)
	{
		ft_printf(" - %s", queue->node->name);
		queue = queue->next;
	}
	ft_printf("\n");
}

/*
** Print Paths
*/

void	print_paths(t_paths *paths)
{
	int i;

	i = 1;
	if (!paths)
	{
		ft_printf("Empty PATHS!\n");
		return ;
	}
	while (paths)
	{
		ft_printf("%4d | Ants %6d |\t", i, paths->dbg_a);
		print_queue(paths->path);
		paths = paths->next;
		i++;
	}
}

/*
** Print Graph
*/

void	print_graph(t_node *graph)
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
	tmp = graph;
	while (tmp)
	{
		if (tmp->ngb)
		{
			i = 0;
			while (tmp->ngb[i])
			{
				ft_printf("%s: %d, ", tmp->ngb[i]->name, tmp->cap[i]);
				i++;
			}
		}
		ft_printf("| ");
		tmp = tmp->next;
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

void	print_debug(t_prop *xt)
{
	ft_printf("{GREEN}{B}{U}Lem-In Stats{EOC}\n");
	ft_printf("Ants:\t%d\n", xt->f_ants);
	ft_printf("Potentional Flow: %d\n", xt->pot_flow);
	ft_printf("Utilized Flow: %d\n", count_paths(xt->all_paths));
	ft_printf("Solution Lenght: %d\n", xt->out_len);
	ft_printf("Time to Process Input: %f sec\n", ft_time_lapsed(xt->stopwatch.start, xt->stopwatch.marks[0]->timestamp));
	ft_printf("Ford-Fulkerson Time: %f sec\n", ft_time_lapsed(xt->stopwatch.marks[0]->timestamp, xt->stopwatch.marks[1]->timestamp));
	ft_stop_timer(&(xt->stopwatch));
	ft_printf("Total Time: %f sec\n", ft_time_lapsed(xt->stopwatch.start, xt->stopwatch.end));
	print_paths(xt->all_paths);
}
