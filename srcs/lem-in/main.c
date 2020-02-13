/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:29:16 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/13 13:29:40 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void			delete_elems(t_node **elems)
{
	t_node *temp;

	while (*elems)
	{
		temp = (*elems)->next;
		free((*elems)->name);
		free((*elems)->ngb);
		free(*elems);
		(*elems) = temp;
	}
	free(*elems);
	*elems = NULL;
}

static void		clear_memory(t_prop *xt)
{
	delete_elems(&xt->elems);
	delete_paths(xt->all_paths);
	free(xt);
}

static t_prop	*initialize_lemin(void)
{
	t_prop	*xt;

	xt = (t_prop *)malloc(sizeof(t_prop));
	ft_bzero(xt, sizeof(xt));
	xt->elems = NULL;
	xt->all_paths = NULL;
	xt->n_start = 0;
	xt->n_end = 0;
	xt->n_ants = 0;
	xt->ant_cnt = 1;
	return (xt);
}

int				main(int argc, char **argv)
{
	t_prop	*xt;

	xt = initialize_lemin();
	read_input(xt);
	assign_ants(xt);
	clear_memory(xt);
}