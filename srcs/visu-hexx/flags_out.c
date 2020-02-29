/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:58:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 21:55:57 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void	print_logo(void)
{
	PRT("{BLUE}{B}\n");
	PRT("	 (    (                  )          )     )  \n");
	PRT("         )\\ ) )\\ )            ( /(       ( /(  ( /(  \n");
	PRT(" (   (  (()/((()/(    (       )\\()) (    )\\()) )\\()) \n");
	PRT(" )\\  )\\  /(_))/(_))   )\\     ((_)\\  )\\  ((_)\\ ((_)\\  \n");
	PRT("((_)((_)(_)) (_))  _ ((_)    |_((_)((_) __((_)__((_) \n");
	PRT("\\ \\ / / |_ _|/ __|| | | |    | || || __|\\ \\/ /\\ \\/ / \n");
	PRT(" \\ V /   | | \\__ \\| |_| |    | __ || _|  >  <  >  <  \n");
	PRT("  \\_/   |___||___/ \\___/     |_||_||___|/_/\\_\\/_/\\_\\ \n");
	PRT("{EOC}\n\n");
}

void	show_usage(void)
{
	print_logo();
	ft_printf("{GREEN}{U}Visu-hexx Usage{EOC}\n\n");
	ft_printf("Using Pipe:");
	ft_printf("\t./lem-in [flags] < [graph file] | ./visu-hexx\n\n");
	ft_printf("Using a flag: ./visu-hexx -f [lem-in output file]\n\n");
	ft_printf("Available Flags:\n");
	ft_printf("\t-f [filename] ... reads the input from file\n");
	ft_printf("\t-u .............. shows program's usage\n");
	ft_printf("\t-i .............. shows program's information\n");
	exit(0);
}

void	show_product_info(void)
{
	system("cat README.md");
	exit(0);
}

void	open_file(t_prop *xt, char *argv)
{
	xt->fd = open(argv, O_RDONLY);
	if (xt->fd <= 0)
		error_exit("Failed to open the given file");
}

void	close_file(t_prop *xt)
{
	if (close(xt->fd) < 0)
		error_exit("Failed to close the given file");
}
