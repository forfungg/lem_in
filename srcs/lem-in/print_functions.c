/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:06:39 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/17 17:44:02 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Prints Colony information
** Ants, Start, End, Rest of Nodes, Edges
*/

void	print_colony(t_prop *xt)
{
	t_node *start;
	t_node *end;

	ft_printf("#Amount of ants\n%d\n", xt->f_ants);
	start = find_start(xt->elems);
	ft_printf("##start\n%s %d %d\n", start->name, start->x, start->y);
	end = find_end(xt->elems);
	ft_printf("##end\n%s %d %d\n", end->name, end->x, end->y);
	ft_printf("#Other Rooms\n");
	print_list(xt->elems);
	ft_printf("#Edges\n");
	print_edges(xt->elems);
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
	while (paths)
	{
		ft_printf("%8d:\t", i);
		print_queue(paths->path);
		paths = paths->next;
		i++;
	}
}
