/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw_visu-hexx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:14:11 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/20 15:56:05 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"
#include <math.h>

void	display_background(t_prop *xt)
{
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->bg, 0, 0);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->sand, 0, W_H / 6);
	mlx_string_put(MLX_PTR, WIN_PTR, 500, 50, 0xff00ff, "Artem's and Jiri's ANT FARM");
}

int		get_cor_x(int coord, t_prop *xt)
{
	int	ret;
	double coef;

	coef = (W_W - IMGS->roomsize - 20) / (double)xt->max_x;
	ret = 10 + coord * coef;
	return (ret);
}

int		get_cor_y(int coord, t_prop *xt)
{
	int		ret;
	double	coef;
	int		allowed_len;

	allowed_len = (W_H - (W_H / 6)) - IMGS->roomsize - 20;
	coef = allowed_len / (double)xt->max_y;
	ret = 10 + (W_H / 6) + (coord * coef);
	return (ret);
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
			mlx_string_put(MLX_PTR, WIN_PTR, temp->nx - 10, temp->ny - 20, 0x000000, temp->name);
		temp = temp->next;
	}
}

void	display_path(t_prop *xt)
{
	t_node	*temp;
	int		shift;

	shift = IMGS->roomsize / 2;
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->path, shift, shift);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->path, shift + 1, shift);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->path, shift, shift + 1);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->path, shift - 1, shift);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->path, shift, shift - 1);
	temp = xt->elems;
	while (temp)
	{
		if (IMGS->disp_names == 1)
			mlx_string_put(MLX_PTR, WIN_PTR, temp->nx - 10, temp->ny - 20, 0x000000, temp->name);
		temp = temp->next;
	}
}

void	display_ants(t_prop *xt)
{
	t_ant *ant;

	ant = xt->ants;
	while (ant)
	{
		if (IMGS->disp_names == 1)
			mlx_string_put(MLX_PTR, WIN_PTR, ant->x + 15, ant->y - 20, 0x000000, ft_itoa(ant->cnt));
		mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->ant, ant->x, ant->y);
		ant = ant->next;
	}
}

void	display_all(t_prop *xt)
{
	display_background(xt);
	display_lines(xt);
	display_rooms(xt);
	display_ants(xt);
}

void	display_paths(t_prop *xt)
{
	display_background(xt);
	display_path(xt);
	display_rooms(xt);
	display_ants(xt);
}

void	redraw(t_prop *xt)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	if (IMGS->disp_all == 1)
		display_all(xt);
	if (IMGS->disp_path == 1)
		display_paths(xt);
}

void	create_stuff(t_prop *xt)
{
	get_minmax_xy(xt);
	create_background(xt);
	create_sand(xt);
	create_room(xt);
	create_start(xt);
	create_end(xt);
	create_lines(xt);
	create_path(xt);
	create_ant(xt);
	create_ant_list(xt);
}

int		onupdate(t_prop *xt)
{
	if (IMGS->pause == 0)
	{
		recalc_ant_movement(xt);
		redraw(xt);
	}
	return (0);
}

void	draw_farm(t_prop *xt)
{
	IMGS->disp_names = 0;
	IMGS->disp_path = 0;
	IMGS->disp_all = 1;
	IMGS->pause = 1;
	create_stuff(xt);
	display_all(xt);
	mlx_loop_hook(MLX_PTR, &onupdate, xt);
	mlx_hook(xt->win_ptr, 2, 0, key_hook_press, xt);
	mlx_loop(MLX_PTR);
}
