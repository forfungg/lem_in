/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_display_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:29:34 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 23:30:03 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void	display_background(t_prop *xt)
{
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->bg, 0, 0);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->sand, 0, W_H / 6);
}

void	display_lines(t_prop *xt)
{
	t_node	*temp;
	int		shift;

	shift = IMGS->roomsize / 2;
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->line, shift, shift);
	temp = xt->elems;
	while (temp)
	{
		if (IMGS->disp_names == 1)
			mlx_string_put(MLX_PTR, WIN_PTR, temp->nx - 10,\
				temp->ny - 20, 0x000000, temp->name);
		temp = temp->next;
	}
}

void	display_path(t_prop *xt)
{
	t_paths	*tpaths;
	t_node	*temp;
	int		shift;

	shift = IMGS->roomsize / 2;
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->path, shift, shift);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->path, shift + 1, shift);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->path, shift, shift + 1);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->path, shift - 1, shift);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->path, shift, shift - 1);
	tpaths = xt->all_paths;
	while (tpaths)
	{
		temp = tpaths->node;
		while (temp)
		{
			if (IMGS->disp_names == 1 && IMGS->disp_black != 1)
				mlx_string_put(MLX_PTR, WIN_PTR, temp->nx - 10,
					temp->ny - 20, 0x000000, temp->name);
			temp = temp->path;
		}
		tpaths = tpaths->next;
	}
}

void	display_ants(t_prop *xt)
{
	t_ant *ant;

	ant = xt->ants;
	while (ant)
	{
		if (IMGS->disp_names && IMGS->disp_black)
			mlx_string_put(MLX_PTR, WIN_PTR, ant->x + IMGS->roomsize,\
				ant->y - 20, 0xffffff, ft_itoa(ant->cnt));
		else if (IMGS->disp_names)
			mlx_string_put(MLX_PTR, WIN_PTR, ant->x + IMGS->roomsize,\
				ant->y - 20, 0x000000, ft_itoa(ant->cnt));
		mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->ant, ant->x, ant->y);
		ant = ant->next;
	}
}

void	display_uniroom(t_prop *xt)
{
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->uniroom, 0, 1);
}
