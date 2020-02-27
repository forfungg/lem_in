/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:47:23 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/27 13:25:59 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int	key_hook_press(int keycode, t_prop *xt)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 123 && IMGS->disp_names == 1) // left
	{
		IMGS->disp_names = 0;
		redraw(xt);
	}
	else if (keycode == 123 && IMGS->disp_names == 0)
	{
		IMGS->disp_names = 1;
		redraw(xt);
	}
	else if (keycode == 124)
	{
		recalc_ant_movement(xt);
		redraw(xt);
	}
	else if (keycode == 18 && IMGS->disp_all == 0)
	{
		IMGS->disp_all = 1;
		IMGS->disp_path = 0;
		IMGS->disp_80s = 0;
		redraw(xt);
	}
	else if (keycode == 19 && IMGS->disp_path == 0)
	{
		IMGS->disp_path = 1;
		IMGS->disp_all = 0;
		IMGS->disp_80s = 0;
		redraw(xt);
	}
	else if (keycode == 20 && IMGS->disp_80s == 0)
	{
		IMGS->disp_80s = 1;
		IMGS->disp_path = 0;
		IMGS->disp_all = 0;
		redraw(xt);
	}
	else if (keycode == 49 && IMGS->pause == 0)
		IMGS->pause = 1;
	else if (keycode == 49 && IMGS->pause == 1)
		IMGS->pause = 0;
	return (0);
}
