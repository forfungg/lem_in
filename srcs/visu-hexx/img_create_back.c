/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:08:30 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/27 13:26:28 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"
#include <math.h>

void		create_background(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	IMGS->bg = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->bgdat = (int *)mlx_get_data_addr(IMGS->bg, &bpp, &size, &endian);
	fill_rectangle(IMGS->bgdat, W_W, W_H, 0x99ccff);
}

void	create_sand(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	IMGS->sand = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->sanddat = (int *)mlx_get_data_addr(IMGS->sand, &bpp, &size, &endian);
	fill_rectangle_pattern(IMGS->sanddat, W_W, W_H, 0xffcc99, 0xcc9966);
}
