/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mem_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:25:33 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/02 12:29:43 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void	delete_node(t_node *node)
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

void	delete_list(t_node *lst)
{
	t_node *tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		delete_node(tmp);
	}
}

void	delete_lines(t_lines *lines)
{
	t_lines *temp;

	if (!lines)
		return ;
	temp = lines;
	while (lines)
	{
		temp = lines->next;
		free(lines->str);
		free(lines);
		lines = temp;
	}
}

void	delete_paths(t_paths *paths)
{
	t_paths *temp;

	if (!paths)
		return ;
	temp = paths;
	while (paths)
	{
		temp = paths->next;
		free(paths);
		paths = temp;
	}
}

void	delete_ants(t_ant *ants)
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
