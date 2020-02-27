/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:13:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/27 13:02:09 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Adds node to the list. If the node is starting point of given graph,
** then it'll be attached to the front, if it's end, then it'll be appended
** otherwise it'll be attached in 2nd position if available.
*/

void	attach_room(t_prop *xt, char *name, int x, int y)
{
	t_node *new;

	new = create_node(name, x, y);
	if (xt->f_start == 1)
	{
		xt->elems = add_front(xt->elems, new);
		new->start = 1;
		xt->f_start = 0;
	}
	else if (xt->f_end == 1)
	{
		xt->elems = add_back(xt->elems, new);
		new->end = 1;
		xt->end_node = new;
		xt->f_end = 0;
	}
	else
		xt->elems = add_default_room(xt->elems, new);
}
