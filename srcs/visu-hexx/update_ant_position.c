/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ant_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:08:00 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/03 14:12:06 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static void	next_line(t_prop *xt)
{
	if (xt->cpy->next)
		xt->cpy = xt->cpy->next;
	else
		xt->cpy = 0;
}

static void	update_positions(t_prop *xt, char *set)
{
	char	**section;
	t_ant	*temp;
	t_node	*end;

	end = find_end(xt->elems);
	temp = xt->ants;
	section = ft_strsplit(set, '-');
	while (temp)
	{
		if (temp->curpos != end)
		{
			if (temp->cnt == ft_atoi(&section[0][1]))
			{
				temp->nextpos = find_node(xt->elems, section[1]);
			}
		}
		temp = temp->next;
	}
	clear_split(section);
}

void		update_ant_positions(t_prop *xt, char *line)
{
	int		cnt;
	char	**array;

	cnt = 0;
	if (line)
	{
		array = ft_strsplit(line, ' ');
		while (array[cnt] != 0)
		{
			update_positions(xt, array[cnt]);
			cnt += 1;
		}
		clear_split(array);
		next_line(xt);
	}
}
