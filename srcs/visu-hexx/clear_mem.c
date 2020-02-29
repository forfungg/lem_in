/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:25:33 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 23:44:35 by asolopov         ###   ########.fr       */
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
		free(node->cap);
		i = 0;
	}
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

static void		delete_ants(t_ant *ants)
{
	t_ant *temp;

	if (!ants)
		return ;
	temp = ants;
	while (temp)
	{
		temp = ants->next;
		free(ants->curpos);
		free(ants->nextpos);
		free(ants);
		ants = temp;
	}
}

void			clear_memory(t_prop *xt)
{
	delete_list(xt->elems);
	delete_lines(xt->lines);
	mlx_destroy_window(MLX_PTR, WIN_PTR);
	free(xt->imgs);
	free(xt->moves);
	free(xt->ants);
	free(MLX_PTR);
	free(xt);
}
