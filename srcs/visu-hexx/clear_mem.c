/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:20:28 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/02 12:28:42 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static void	destroy_images(t_prop *xt)
{
	mlx_destroy_image(MLX_PTR, IMGS->bg);
	mlx_destroy_image(MLX_PTR, IMGS->sand);
	mlx_destroy_image(MLX_PTR, IMGS->uniroom);
	mlx_destroy_image(MLX_PTR, IMGS->line);
	mlx_destroy_image(MLX_PTR, IMGS->path);
	mlx_destroy_image(MLX_PTR, IMGS->ant);
}

void		clear_memory(t_prop *xt)
{
	delete_list(xt->elems);
	delete_lines(xt->lines);
	delete_paths(xt->all_paths);
	delete_ants(xt->ants);
	free(xt->moves);
	destroy_images(xt);
	free(xt->imgs);
	mlx_destroy_window(MLX_PTR, WIN_PTR);
	free(xt);
}
