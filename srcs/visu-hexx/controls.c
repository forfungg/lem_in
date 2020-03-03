/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:47:23 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/03 13:32:07 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static void	speed_mode(int keycode, t_prop *xt)
{
	if (keycode == 83)
		xt->spdmod = 1;
	if (keycode == 84)
		xt->spdmod = 3;
	if (keycode == 85)
		xt->spdmod = 6;
	if (keycode == 126)
		xt->spdmod += 0.1;
	if (keycode == 125 && xt->spdmod > 0.1)
		xt->spdmod -= 0.1;
	redraw(xt);
}

static void	mode_selector(int keycode, t_prop *xt)
{
	if (keycode == 18 && IMGS->disp_all == 0)
	{
		IMGS->disp_all = 1;
		IMGS->disp_path = 0;
		IMGS->disp_black = 0;
	}
	else if (keycode == 19 && IMGS->disp_path == 0)
	{
		IMGS->disp_path = 1;
		IMGS->disp_all = 0;
		IMGS->disp_black = 0;
	}
	else if (keycode == 20 && IMGS->disp_black == 0)
	{
		IMGS->disp_black = 1;
		IMGS->disp_path = 0;
		IMGS->disp_all = 0;
	}
	redraw(xt);
}

static void	room_ant_information(int keycode, t_prop *xt)
{
	if (keycode == 45 && IMGS->disp_names == 1)
		IMGS->disp_names = 0;
	else if (keycode == 45 && IMGS->disp_names == 0)
		IMGS->disp_names = 1;
	redraw(xt);
}

static void	play_pause_replay(int keycode, t_prop *xt)
{
	if (keycode == 15)
	{
		xt->cpy = xt->lines;
		create_ant_list(xt);
		redraw(xt);
	}
	if (keycode == 49 && IMGS->pause == 0)
		IMGS->pause = 1;
	else if (keycode == 49 && IMGS->pause == 1)
		IMGS->pause = 0;
}

int			key_hook_press(int keycode, t_prop *xt)
{
	if (keycode == 53)
	{
		clear_memory(xt);
		exit(1);
	}
	else if (keycode == 124)
	{
		recalc_ant_movement(xt);
		redraw(xt);
	}
	play_pause_replay(keycode, xt);
	room_ant_information(keycode, xt);
	mode_selector(keycode, xt);
	speed_mode(keycode, xt);
	return (0);
}
