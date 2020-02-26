/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:47:17 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/24 18:29:40 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Checks whether a room with given name or coordinates already exists
*/

void		is_valid_room(t_prop *xt, char *name, int x, int y)
{
	t_node *list;

	list = xt->elems;
	while (list)
	{
		if (ft_strequ(list->name, name))
		{
			if (DEBUG)
				ft_printf("Conflict: %s (%d,%d)\n", name, x, y);
			error_exit("Duplicate Room's Name");
		}
		else if (x == list->x && y == list->y)
		{
			if (DEBUG)
				ft_printf("Conflict: %s (%d,%d)\n", name, x, y);
			error_exit("Duplicate Room's Coordinates");
		}
		list = list->next;
	}
	attach_room(xt, name, x, y);
}
