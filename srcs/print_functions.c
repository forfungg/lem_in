/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:06:39 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/12 12:37:51 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

void	print_list(t_node *head)
{
	int i;

	while (head)
	{
		ft_printf("Elem: %s\n", head->name);
		if (head->start)
			ft_printf("START\n");
		if (head->end)
			ft_printf("END\n");
		i = 0;
		ft_printf("NGB:");
		if (head->ngb != 0)
		{
			while (head->ngb[i])
				ft_printf(" %s", head->ngb[i++]->name);
		}
		ft_printf("\n\n");
		head = head->next;
	}
}

void	print_queue(t_que *queue)
{
	while (queue)
	{
		printf(" - %s", queue->node->name);
		queue = queue->next;
	}
	printf("\n");
}

/*
** Print Paths
*/

void	print_paths(t_paths *paths)
{
	while (paths)
	{
		print_queue(paths->path);
		paths = paths->next;
	}
}
