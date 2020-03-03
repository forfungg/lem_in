/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:14:11 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/03 13:33:21 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static void	create_stuff(t_prop *xt)
{
	get_minmax_xy(xt);
	create_background(xt);
	create_sand(xt);
	create_uniroom(xt);
	create_lines(xt);
	create_path(xt);
	create_ant(xt);
	create_ant_list(xt);
}

void		redraw(t_prop *xt)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	if (IMGS->disp_all == 1)
		display_all(xt);
	if (IMGS->disp_path == 1)
		display_paths(xt);
	if (IMGS->disp_black == 1)
		display_black(xt);
}

int			onupdate(t_prop *xt)
{
	if (IMGS->pause == 0)
	{
		recalc_ant_movement(xt);
		redraw(xt);
	}
	return (0);
}

int			exit_hook(t_prop *xt)
{
	clear_memory(xt);
	exit(1);
}

void		draw_farm(t_prop *xt)
{
	IMGS->disp_names = 0;
	IMGS->disp_path = 0;
	IMGS->disp_black = 0;
	IMGS->disp_all = 1;
	IMGS->pause = 1;
	create_stuff(xt);
	display_all(xt);
	mlx_loop_hook(MLX_PTR, &onupdate, xt);
	mlx_hook(xt->win_ptr, 2, 0, key_hook_press, xt);
	mlx_hook(xt->win_ptr, 17, 0, exit_hook, xt);
	mlx_loop(MLX_PTR);
}
