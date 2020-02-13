/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:30:39 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/13 17:06:22 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void		create_background(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	xt->imgs->bg = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->bgdat = (int *)mlx_get_data_addr(IMGS->bg, &bpp, &size, &endian);
	fill_rectangle(IMGS->bgdat, W_W, W_H, 0x99ccff);
}

void	create_sand(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	xt->imgs->sand = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->sanddat = (int *)mlx_get_data_addr(IMGS->sand, &bpp, &size, &endian);
	fill_rectangle(IMGS->sanddat, W_W, W_H, 0xffcc99);
}
