/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:14:11 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/14 17:16:01 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

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

	coef = (W_W - IMGS->roomsize - 20) / xt->max_x;
	ret = 10 + coord * coef;
	return (ret);
}

int		get_cor_y(int coord, t_prop *xt)
{
	int		ret;
	double	coef;
	int		allowed_len;

	allowed_len = (W_H - (W_H / 6)) - IMGS->roomsize - 20;
	coef = allowed_len / (xt->max_y);
	ret = 10 + (W_H / 6) + (coord * coef);
	return (ret);
}

void	display_rooms(t_prop *xt)
{
	t_node	*temp;

	temp = xt->elems;
	while (temp)
	{
		temp->nx = get_cor_x(temp->x, xt);
		temp->ny = get_cor_y(temp->y, xt);
		if (IMGS->disp_names == 1)
			mlx_string_put(MLX_PTR, WIN_PTR, temp->nx - 15, temp->ny - 20, 0xff00ff, temp->name);
		mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->room, temp->nx, temp->ny);
		temp = temp->next;
	}
}

void	redraw(t_prop *xt)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	display_background(xt);
	display_rooms(xt);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->line, 0, 0);
}

void	draw_farm(t_prop *xt)
{
	IMGS->disp_names = 0;
	get_minmax_xy(xt);
	create_background(xt);
	create_sand(xt);
	create_room(xt);
	display_background(xt);
	display_rooms(xt);
	create_lines(xt);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->line, 0, 0);
	mlx_hook(xt->win_ptr, 2, 0, key_hook_press, xt);
	mlx_loop(MLX_PTR);
}
