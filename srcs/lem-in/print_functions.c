/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:06:39 by jnovotny          #+#    #+#             */
/*   Updated: 2020/03/03 14:13:08 by jnovotny         ###   ########.fr       */
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
