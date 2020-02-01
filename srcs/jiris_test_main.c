/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jiris_test_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:37:48 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/01 21:15:33 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

/*
** Manual generation of ../resources/example03
*/

t_node	*generate_stuff(void)
{
	t_node	*head;
	t_node	*tmp;

	head = NULL;
	head = create_front(head, "1", 19, 3);
	head = create_front(head, "2", 16, 7);
	head = create_front(head, "3", 16, 3);
	head = create_front(head, "4", 13, 5);
	head = create_front(head, "5", 9, 3);
	head = create_front(head, "6", 1, 5);
	head = create_front(head, "7", 4, 8);
	head = create_front(head, "0", 9, 5);
	tmp = find_node(head, "1");
	tmp->start = TRUE;
	tmp = find_node(head, "0");
	tmp->end = TRUE;
	if (!add_neighbor(find_node(head, "1"), find_node(head, "2")))
		printf("Error on 1-2\n");
	if (!add_neighbor(find_node(head, "2"), find_node(head, "1")))
		printf("Error on 2-1\n");
	if (!add_neighbor(find_node(head, "2"), find_node(head, "3")))
		printf("Error on 2-3\n");
	if (!add_neighbor(find_node(head, "3"), find_node(head, "2")))
		printf("Error on 3-2\n");
	if (!add_neighbor(find_node(head, "3"), find_node(head, "4")))
		printf("Error on 3-4\n");
	if (!add_neighbor(find_node(head, "4"), find_node(head, "3")))
		printf("Error on 4-3\n");
	if (!add_neighbor(find_node(head, "4"), find_node(head, "5")))
		printf("Error on 4-5\n");
	if (!add_neighbor(find_node(head, "5"), find_node(head, "4")))
		printf("Error on 5-4\n");
	if (!add_neighbor(find_node(head, "5"), find_node(head, "6")))
		printf("Error on 5-6\n");
	if (!add_neighbor(find_node(head, "6"), find_node(head, "5")))
		printf("Error on 6-5\n");
	if (!add_neighbor(find_node(head, "5"), find_node(head, "7")))
		printf("Error on 5-7\n");
	if (!add_neighbor(find_node(head, "7"), find_node(head, "5")))
		printf("Error on 7-5\n");
	if (!add_neighbor(find_node(head, "6"), find_node(head, "7")))
		printf("Error on 6-7\n");
	if (!add_neighbor(find_node(head, "7"), find_node(head, "6")))
		printf("Error on 7-6\n");
	if (!add_neighbor(find_node(head, "7"), find_node(head, "0")))
		printf("Error on 7-0\n");
	if (!add_neighbor(find_node(head, "0"), find_node(head, "7")))
		printf("Error on 0-7\n");
	return (head);
}

int main()
{
	t_node *my_list;

	my_list = generate_stuff();
	print_list(my_list);
	return (0);
}