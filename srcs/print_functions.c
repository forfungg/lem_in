/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:06:39 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/10 17:02:26 by asolopov         ###   ########.fr       */
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
		while (head->ngb[i])
			ft_printf(" %s", head->ngb[i++]->name);
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
