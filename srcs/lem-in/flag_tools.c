/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:16:15 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/26 18:50:17 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	show_usage(void)
{
	ft_printf("{GREEN}{U}Lem_In Usage{EOC}\n");
	ft_printf("./lem-in [flags] < [graph file]\n");
	exit (0);
}

void	show_product_info(void)
{
	system("cat README.md");
	exit(0);
}
