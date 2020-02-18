/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:47:23 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/18 13:36:51 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

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
		move_ants(xt);
		if (xt->lines)
			update_ant_positions(xt, xt->lines->str);
		print_ant_data(xt);
		redraw(xt);
	}
	else if (keycode == 18 && IMGS->disp_all == 0)
	{
		IMGS->disp_all = 1;
		IMGS->disp_path = 0;
		redraw(xt);
	}
	else if (keycode == 19 && IMGS->disp_path == 0)
	{
		IMGS->disp_path = 1;
		IMGS->disp_all = 0;
		redraw(xt);
	}

	return (0);
}
