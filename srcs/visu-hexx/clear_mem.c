/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:25:33 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/02 12:18:12 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void			delete_node(t_node *node)
{
	int i;

	i = 0;
	if (!node)
		return ;
	if (node->ngb != NULL)
	{
		while (node->ngb[i])
			node->ngb[i++] = NULL;
		free(node->ngb);
		i = 0;
	}
	if (node->cap)
		free(node->cap);
	free(node->name);
	free(node);
}

void			delete_list(t_node *lst)
{
	t_node *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		delete_node(tmp);
	}
}

static void		delete_lines(t_lines *lines)
{
	t_lines *temp;

	temp = lines;
	while (lines)
	{
		temp = lines->next;
		free(lines->str);
		free(lines);
		lines = temp;
	}
}

static void		delete_paths(t_paths *paths)
{
	t_paths *temp;

	temp = paths;
	while (paths)
	{
		temp = paths->next;
		free(paths);
		paths = temp;
	}
}

static void		delete_ants(t_ant *ants)
{
	t_ant *temp;

	if (!ants)
		return ;
	temp = ants;
	while (temp)
	{
		temp = ants->next;
		free(ants);
		ants = temp;
	}
}

static void		destroy_images(t_prop *xt)
{
	mlx_destroy_image(MLX_PTR, IMGS->bg);
	mlx_destroy_image(MLX_PTR, IMGS->sand);
	mlx_destroy_image(MLX_PTR, IMGS->uniroom);
	mlx_destroy_image(MLX_PTR, IMGS->line);
	mlx_destroy_image(MLX_PTR, IMGS->path);
	mlx_destroy_image(MLX_PTR, IMGS->ant);
}

void			clear_memory(t_prop *xt)
{
	delete_list(xt->elems);
	delete_lines(xt->lines);
	delete_paths(xt->all_paths);
	delete_ants(xt->ants);
	destroy_images(xt);
	free(xt->imgs);
	free(xt->moves);
	mlx_destroy_window(MLX_PTR, WIN_PTR);
	free(xt);
}
