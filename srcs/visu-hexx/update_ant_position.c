/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ant_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:08:00 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/25 12:56:52 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	free_line(t_prop *xt)
{
	t_lines *temp;

	if (xt->lines->next)
		temp = xt->lines->next;
	else
		temp = 0;
	free(xt->lines->str);
	free(xt->lines);
	xt->lines = temp;
}

void	update_positions(t_prop *xt, char *set)
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

void	update_ant_positions(t_prop *xt, char *line)
{
	int		cnt;
	char	**array;

	if (line)
	{
		array = ft_strsplit(line, ' ');
		while (array[cnt] != 0)
		{
			update_positions(xt, array[cnt]);
			cnt += 1;
		}
		clear_split(array);
		free_line(xt);
	}
}
