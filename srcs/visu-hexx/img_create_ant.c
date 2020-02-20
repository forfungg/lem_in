/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:10:18 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/17 17:40:40 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	create_head(int *img_data, int size, int color)
{
	int cnt_h;
	int cnt_w;

	cnt_h = 0;
	while (cnt_h < size)
	{
		cnt_w = 0;
		while (cnt_w < size)
		{
			if (cnt_w >= size / 2 && cnt_w <= size - (size / 6))
			{
				if (cnt_h >= size / 6 && cnt_h <= size / 2)
				{
					if (cnt_h >= size / 4 && cnt_h <= size / 3)
						img_data[cnt_h * size + cnt_w] = 0x000000;
					else
						img_data[cnt_h * size + cnt_w] = color;
				}
			}
			cnt_w += 1;
		}
		cnt_h += 1;
	}
}

void	create_body(int *img_data, int size, int color)
{
	int cnt_h;
	int cnt_w;

	cnt_h = 0;
	while (cnt_h < size)
	{
		cnt_w = 0;
		while (cnt_w < size)
		{
			if (cnt_w <= size / 2)
			{
				if (cnt_h >= size / 2 && cnt_h <= size - (size / 4))
					img_data[cnt_h * size + cnt_w] = color;
			}
			if (cnt_h >= size - (size / 4) && cnt_h < size - (size / 8))
			{
				if (cnt_w == size / 4 - 1 || cnt_w == size / 2 - 1 || cnt_w == 0)
					img_data[cnt_h * size + cnt_w] = color;
				if (cnt_w == size / 4  - 2 || cnt_w == size / 2 - 2 || cnt_w == 1)
					img_data[cnt_h * size + cnt_w] = color;
			}
			cnt_w += 1;
		}
		cnt_h += 1;
	}
}

void	create_antena(int *img_data, int size, int color)
{
	int cnt_h;
	int	cnt_wl;
	int cnt_wr;

	cnt_wl = size / 2 + size / 6;
	cnt_wr = size / 2 + size / 6;
	cnt_h = size / 5;
	while (cnt_h != 0)
	{
		img_data[cnt_h * size + cnt_wl] = color;
		img_data[cnt_h * size + cnt_wr] = color;
		cnt_wl -= 1;
		cnt_wr += 1;
		cnt_h -= 1;
	}
}

void	create_ant(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	int		ant_size;

	ant_size = IMGS->roomsize - IMGS->roomsize / 5;
	if (ant_size >= 25)
	{
		IMGS->ant = mlx_new_image(MLX_PTR, ant_size, ant_size);
		IMGS->antdat = (int *)mlx_get_data_addr(IMGS->ant, &bpp, &size, &endian);
		fill_rectangle(IMGS->antdat, ant_size, ant_size, 0xff000000);
		create_head(IMGS->antdat, ant_size, 0x660000);
		create_antena(IMGS->antdat, ant_size, 0x660000);
		create_body(IMGS->antdat, ant_size, 0x660000);
	}
	else
	{
		IMGS->ant = mlx_new_image(MLX_PTR, ant_size * 2, ant_size * 2);
		IMGS->antdat = (int *)mlx_get_data_addr(IMGS->ant, &bpp, &size, &endian);
		fill_rectangle(IMGS->antdat, ant_size * 2, ant_size * 2, 0xff0000);
	}
}
