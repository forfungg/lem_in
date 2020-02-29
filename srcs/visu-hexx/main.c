/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:30:01 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 21:24:19 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void	clear_split(char **props)
{
	int i;

	i = 0;
	while (props[i])
	{
		if (props[i])
			free(props[i]);
		i += 1;
	}
	free(props);
}

static t_prop	*init_visuhexx(void)
{
	t_prop	*xt;

	xt = (t_prop *)malloc(sizeof(t_prop));
	ft_bzero(xt, sizeof(xt));
	xt->elems = NULL;
	xt->all_paths = NULL;
	xt->n_start = 0;
	xt->n_end = 0;
	xt->n_ants = 0;
	xt->n_rooms = 0;
	xt->imgs = (t_img *)malloc(sizeof(t_img));
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(xt->mlx_ptr, W_W, W_H, W_NAME);
	return (xt);
}

static void		delete_lines(t_lines *lines)
{
	t_lines *temp;

	temp = lines;
	while (lines)
	{
		temp = lines->next;
		free(lines->str);
		free(lines);
		lines = temp;
	}
}

static void		delete_ants(t_ant *ants)
{
	t_ant *temp;

	if (!ants)
		return ;
	temp = ants;
	while (temp)
	{
		temp = ants->next;
		free(ants->curpos);
		free(ants->nextpos);
		free(ants);
		ants = temp;
	}
}

static void		delete_pathss(t_paths *paths)
{
	t_paths *temp;

	temp = paths;
	while (paths)
	{
		temp = paths->next;
		free(paths->node);
		free(paths);
		paths = temp;
	}
}

void		clear_memory(t_prop *xt)
{
	delete_list(xt->elems);
	delete_lines(xt->lines);
	mlx_destroy_window(MLX_PTR, WIN_PTR);
	free(xt->imgs);
	free(xt->moves);
	free(xt->ants);
	free(MLX_PTR);
	free(xt);
}

static void		read_flags(t_prop *xt, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (ft_strchr(argv[i], 'f') && i + 1 < argc)
				open_file(xt, argv[i + 1]);
			else if (ft_strchr(argv[i], 'f') && i + 1 >= argc)
				error_exit("Failed : no file provided");
			if (ft_strchr(argv[i], 'u'))
				show_usage();
			if (ft_strchr(argv[i], 'i'))
				show_product_info();
		}
		i++;
	}
}

void			print_liness(t_lines *lines)
{
	while (lines)
	{
		ft_printf("%s\n", lines->str);
		lines = lines->next;
	}
}

int				main(int argc, char **argv)
{
	t_prop	*xt;

	xt = init_visuhexx();
	if (argc > 1)
		read_flags(xt, argc, argv);
	read_input(xt);
	draw_farm(xt);
}
