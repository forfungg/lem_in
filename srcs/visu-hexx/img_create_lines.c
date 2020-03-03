/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:30:39 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/01 00:31:14 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static int	get_line_color(int max, int min)
{
	int r;
	int g;
	int b;

	r = rand() % (max + 1 - min) + min;
	g = rand() % (max + 1 - min) + min;
	b = rand() % (max + 1 - min) + min;
	return ((r << 16) | (g << 8) | (b));
}

static void	create_connections_lines(t_prop *xt)
{
	t_node	*temp;
	int		cnt;

	temp = xt->elems;
	xt->color = 0x000000;
	while (temp)
	{
		if (temp->ngb)
		{
			cnt = 0;
			while (temp->ngb[cnt] != 0)
			{
				cnct_nodes(IMGS->linedat, xt, temp, temp->ngb[cnt]);
				cnt += 1;
			}
		}
		temp = temp->next;
	}
}

void		create_lines(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	IMGS->line = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->linedat = (int *)mlx_get_data_addr(IMGS->line, &bpp, &size, &endian);
	fill_rctngl(IMGS->linedat, W_W, W_H, 0xff000000);
	create_connections_lines(xt);
}

static void	create_connections_paths(t_prop *xt)
{
	t_paths *path;
	t_node	*tmp;
	t_node	*start;

	path = xt->all_paths;
	while (path)
	{
		tmp = path->node;
		xt->color = get_line_color(255, 25);
		cnct_nodes(IMGS->pathdat, xt, find_start(xt->elems), tmp);
		while (tmp->path)
		{
			cnct_nodes(IMGS->pathdat, xt, tmp, tmp->path);
			tmp = tmp->path;
		}
		path = path->next;
	}
}

void		create_path(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	IMGS->path = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->pathdat = (int *)mlx_get_data_addr(IMGS->path, &bpp, &size, &endian);
	fill_rctngl(IMGS->pathdat, W_W, W_H, 0xff000000);
	create_connections_paths(xt);
}
