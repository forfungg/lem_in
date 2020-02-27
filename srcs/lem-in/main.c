/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:29:16 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 17:41:35 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		clear_memory(t_prop *xt)
{
	ft_stopwatch_del(xt->stopwatch);
	delete_list(xt->elems);
	delete_paths(xt->all_paths);
	delete_paths(xt->augment_paths);
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
	xt->augment_paths = NULL;
	xt->n_start = 0;
	xt->n_end = 0;
	xt->n_ants = 0;
	xt->ant_cnt = 1;
	FILE = 0;
	DEBUG = 0;
	xt->stopwatch = ft_stopwatch_init();
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
			if (ft_strchr(argv[i], 't'))
				xt->flags.time = 1;
			if (ft_strchr(argv[i], 'b'))
				xt->flags.bfs = 1;
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
