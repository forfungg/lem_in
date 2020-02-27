/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:13:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/27 12:43:51 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** turns start/end flags and keeps count of occurences
** !Add dealing with other comments!
*/

void	save_commands(char *str, t_prop *xt)
{
	if (ft_strequ(str, "##start") == 1)
	{
		xt->f_start = 1;
		xt->n_start += 1;
	}
	else if (ft_strequ(str, "##end") == 1)
	{
		xt->f_end = 1;
		xt->n_end += 1;
	}
}

void	save_ants(char *str, t_prop *xt)
{
	xt->f_ants = ft_atoi(str);
	xt->n_ants += 1;
}

/*
** reads commands, rooms and links, cuts out crap and launches compliance check
*/

void	read_input(t_prop *xt)
{
	char	*line;

	xt->all_paths = NULL;
	ft_start_timer(xt->stopwatch);
	load_input(xt, FILE);
	// ft_printf("Input Saved to stuct\n");
	if (FILE > 2)
		close_graph_file(xt);
	process_input(xt);
	// ft_printf("Reading done\n");
	// debug_print(xt->elems);
	check_input(xt);
	ft_markdown(xt->stopwatch, "INPUT");
	// exit(0);
	xt-> pot_flow = ford_fulkerson(xt);
	ft_markdown(xt->stopwatch, "FF");
	// ft_printf("%d\n", maxflow);
	// print_paths(xt->all_paths);
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