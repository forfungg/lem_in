/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 21:06:39 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/01 21:11:45 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	print_list(t_node *head)
{
	int i;

	while (head)
	{
		printf("%s\n", head->name);
		if (head->start)
			printf("START\n");
		if (head->end)
			printf("END\n");
		i = 0;
		printf("NGB:");
		while (head->ngb[i])
			printf(" %s", head->ngb[i++]->name);
		printf("\n\n");
		head = head->next;
	}
}
