/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:14:11 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/13 17:05:40 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	draw_farm(t_prop *xt)
{
	create_background(xt);
	create_sand(xt);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->bg, 0, 0);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->sand, 0, W_H / 5);
	mlx_hook(xt->win_ptr, 2, 0, key_hook_press, xt);
	mlx_loop(MLX_PTR);
}
