/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:29:16 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/26 21:00:10 by jnovotny         ###   ########.fr       */
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
	FILE = 0;
	DEBUG = 0;
	ft_stopwatch_init(&(xt->stopwatch));
	return (xt);
}

static void		read_flags(t_prop *xt, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (ft_strchr(argv[i], 'f') && i + 1 < argc)
				open_graph_file(xt, argv[i + 1]);
			if (ft_strchr(argv[i], 'd'))
				xt->flags.debug = 1;
			if (ft_strchr(argv[i], 'u'))
				show_usage();
			if (ft_strchr(argv[i], 'i'))
				show_product_info();
		}
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_prop	*xt;

	xt = initialize_lemin();
	if (argc > 1)
		read_flags(xt, argc, argv);
	read_input(xt);
	assign_ants(xt);
	clear_memory(xt);
	// while(1);
}
