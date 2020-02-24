/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:29:16 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/24 16:59:14 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		clear_memory(t_prop *xt)
{
	delete_list(xt->elems);
	delete_paths(xt->all_paths);
	free(xt->input);
	free(xt);
}

static t_prop	*initialize_lemin(void)
{
	t_prop	*xt;

	xt = (t_prop *)ft_memalloc(sizeof(t_prop));
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
	// while(1);
}
