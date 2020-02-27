/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:13:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/27 13:06:56 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** reads commands, rooms and links, cuts out crap and launches compliance check
*/

void	read_input(t_prop *xt)
{
	char	*line;

	xt->all_paths = NULL;
	ft_start_timer(xt->stopwatch);
	load_input(xt, FILE);
	if (FILE > 2)
		close_graph_file(xt);
	process_input(xt);
	check_input(xt);
	ft_markdown(xt->stopwatch, "INPUT");
	xt->pot_flow = ford_fulkerson(xt);
	ft_markdown(xt->stopwatch, "FF");
	if (xt->pot_flow == 0)
		error_exit("No solution found");
}

/*
** Checks if given string containes valid coordinate, and returns it as int.
*/

int		get_coord(char *str)
{
	long	nb;

	nb = ft_latoi(str);
	if (nb > INT_MAX || nb < 0)
		error_exit("Coordinates out of int range");
	return ((int)nb);
}
