/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:14:11 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/15 10:06:46 by solopov          ###   ########.fr       */
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
		mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->room, temp->nx, temp->ny);
		temp = temp->next;
	}
}

void	display_lines(t_prop *xt)
{
	t_node *temp;
	int		shift;

	shift = IMGS->roomsize / 2;
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->line, shift, shift);
	temp = xt->elems;
	while (temp)
	{
		if (IMGS->disp_names == 1)
			mlx_string_put(MLX_PTR, WIN_PTR, temp->nx - 15, temp->ny - 20, 0xff00ff, temp->name);
		temp = temp->next;
	}
}

void	display_all(t_prop *xt)
{
	create_lines(xt);
	display_background(xt);
	display_rooms(xt);
	display_lines(xt);
}

void	display_paths(t_prop *xt)
{
	
}

void	display_unique(t_prop *xt)
{
	
}

void	redraw(t_prop *xt)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	if (IMGS->disp_all == 1)
		display_all(xt);
	if (IMGS->disp_path == 1)
		display_paths(xt);
	if (IMGS->disp_unique == 1)
		display_unique(xt);
}

void	draw_farm(t_prop *xt)
{
	IMGS->disp_names = 0;
	IMGS->disp_path = 0;
	IMGS->disp_unique = 0;
	IMGS->disp_all = 1;
	get_minmax_xy(xt);
	create_background(xt);
	create_sand(xt);
	create_room(xt);
	display_all(xt);
	mlx_hook(xt->win_ptr, 2, 0, key_hook_press, xt);
	mlx_loop(MLX_PTR);
}
