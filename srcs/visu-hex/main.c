/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:30:01 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/15 09:35:16 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	init_xt(t_prop *xt)
{
	ft_bzero(xt, sizeof(xt));
	xt->elems = NULL;
	xt->n_start = 0;
	xt->n_end = 0;
	xt->n_ants = 0;
	xt->n_rooms = 0;
	xt->imgs = (t_img *)malloc(sizeof(t_img));
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(xt->mlx_ptr, W_W, W_H, W_NAME);
}

int	main(int argc, char **argv)
{
	t_prop	*xt;

	if (!(xt = (t_prop *)malloc(sizeof(t_prop))))
		error_exit("Malloc (xt)");
	init_xt(xt);
	read_input(xt);
	draw_farm(xt);
}
