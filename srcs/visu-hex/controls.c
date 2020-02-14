/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:47:23 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/14 14:46:58 by solopov          ###   ########.fr       */
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
	return (0);
}
