/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:29:16 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/12 15:25:50 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int argc, char **argv)
{
	t_prop *xt;
	t_paths *paths;

	xt = (t_prop *)malloc(sizeof(t_prop));
	xt->elems = 0;
	xt->n_start = 0;
	xt->n_end = 0;
	xt->n_ants = 0;
	xt->ant_cnt = 1;
	paths = read_input(xt);
	assign_ants(xt, paths);
	free(xt);
}
