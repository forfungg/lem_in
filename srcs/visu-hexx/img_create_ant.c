/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create_ant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:10:18 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/01 00:28:25 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static void	create_head(int *img_data, int size, int color)
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

static void	create_body(int *img_data, int size, int color)
{
	int ct_h;
	int ct_w;

	ct_h = 0;
	while (ct_h < size)
	{
		ct_w = 0;
		while (ct_w < size)
		{
			if (ct_w <= size / 2)
			{
				if (ct_h >= size / 2 && ct_h <= size - (size / 4))
					img_data[ct_h * size + ct_w] = color;
			}
			if (ct_h >= size - (size / 4) && ct_h < size - (size / 8))
			{
				if (ct_w == size / 4 - 1 || ct_w == size / 2 - 1 || ct_w == 0)
					img_data[ct_h * size + ct_w] = color;
				if (ct_w == size / 4 - 2 || ct_w == size / 2 - 2 || ct_w == 1)
					img_data[ct_h * size + ct_w] = color;
			}
			ct_w += 1;
		}
		ct_h += 1;
	}
}

static void	create_antena(int *img_data, int size, int color)
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

void		create_ant(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;
	int		ant_size;

	ant_size = IMGS->roomsize - IMGS->roomsize / 5;
	if (ant_size >= 25)
	{
		IMGS->ant = mlx_new_image(MLX_PTR, ant_size, ant_size);
		IMGS->adat = (int *)mlx_get_data_addr(IMGS->ant, &bpp, &size, &endian);
		fill_rctngl(IMGS->adat, ant_size, ant_size, 0xff000000);
		create_head(IMGS->adat, ant_size, 0x660000);
		create_antena(IMGS->adat, ant_size, 0x660000);
		create_body(IMGS->adat, ant_size, 0x660000);
	}
	else
	{
		IMGS->ant = mlx_new_image(MLX_PTR, ant_size * 2, ant_size * 2);
		IMGS->adat = (int *)mlx_get_data_addr(IMGS->ant, &bpp, &size, &endian);
		fill_rctngl(IMGS->adat, ant_size * 2, ant_size * 2, 0xff0000);
	}
}
