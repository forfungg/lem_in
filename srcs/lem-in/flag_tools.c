/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:16:15 by jnovotny          #+#    #+#             */
/*   Updated: 2020/03/03 12:21:05 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		show_usage(void)
{
	print_logo();
	ft_printf("{GREEN}{U}Lem_In Usage{EOC}\n\n");
	ft_printf("Using Redirect:");
	ft_printf("\t./lem-in [flags] < [graph file]\n\n");
	ft_printf("Using a flag: ./lem-in -f [filename]\n\n");
	ft_printf("Available Flags:\n");
	ft_printf("\t-f [filename] ... reads the input from file\n");
	ft_printf("\t-d .............. shows debug output\n");
	ft_printf("\t    -db ......... shows augmenting paths as well\n");
	ft_printf("\t-u .............. shows program's usage\n");
	ft_printf("\t-i .............. ./shows program's information\n");
	exit(0);
}

void		show_product_info(void)
{
	system("cat README.md");
	exit(0);
}

void		print_time_stats(t_prop *xt, unsigned long i)
{
	clock_t	now;

	system("clear");
	print_logo();
	now = clock();
	ft_printf("Run Time:\t\t%f sec\n",\
		ft_time_lapsed(xt->stopwatch->start, now));
	ft_printf("Lines Processed:\t%lu\n", i);
}
