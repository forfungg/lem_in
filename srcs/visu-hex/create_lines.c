/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:30:39 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/17 17:14:28 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"
#include <math.h>

void	create_connections_lines(t_prop *xt)
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
				connect_nodes(IMGS->linedat, xt, temp, temp->ngb[cnt]);
				cnt += 1;
			}
		}
		temp = temp->next;
	}
}

void	create_lines(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	IMGS->line = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->linedat = (int *)mlx_get_data_addr(IMGS->line, &bpp, &size, &endian);
	fill_rectangle(IMGS->linedat, W_W, W_H, 0xff000000);
	create_connections_lines(xt);
}

void	create_connections_paths(t_prop *xt)
{
	t_paths	*temp;

	temp = xt->all_paths;
	while (temp)
	{
		xt->color = rand() % (16777215 + 162478 - 0) + 0;
		while (temp->path->next)
		{
			connect_nodes(IMGS->pathdat, xt, temp->path->node, temp->path->next->node);
			temp->path = temp->path->next;
		}
		temp = temp->next;
	}
}

void	create_path(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	IMGS->path = mlx_new_image(MLX_PTR, W_W, W_H);
	IMGS->pathdat = (int *)mlx_get_data_addr(IMGS->path, &bpp, &size, &endian);
	fill_rectangle(IMGS->pathdat, W_W, W_H, 0xff000000);
	create_connections_paths(xt);
}
