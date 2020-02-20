/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:55:54 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/20 15:58:25 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	split_rooms(t_prop *xt)
{
	printf("%d\n", xt->n_rooms);
}

void	display_rooms(t_prop *xt)
{
	t_node	*temp;
	
	temp = xt->elems;
	while (temp)
	{
		if (temp->start == 1)
			mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->start, temp->nx, temp->ny);
		else if (temp->end == 1)
			mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->end, temp->nx, temp->ny);
		else
			mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMGS->room, temp->nx, temp->ny);
		temp = temp->next;
	}
}
