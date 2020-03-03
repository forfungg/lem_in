/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:30:01 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/02 11:56:47 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void			clear_split(char **props)
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
	xt->spdmod = 1;
	xt->imgs = (t_img *)malloc(sizeof(t_img));
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(xt->mlx_ptr, W_W, W_H, W_NAME);
	return (xt);
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

int				main(int argc, char **argv)
{
	t_prop	*xt;

	xt = init_visuhexx();
	if (argc > 1)
		read_flags(xt, argc, argv);
	read_input(xt);
	draw_farm(xt);
}
