/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:58:05 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/18 13:36:57 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	print_ant_data(t_prop *xt)
{
	t_ant *temp;

	temp = xt->ants;
	while (temp)
	{
		ft_printf("ANT %d:\n", temp->cnt);
		ft_printf("x:%d\n", temp->x);
		ft_printf("y:%d\n", temp->y);
		ft_printf("curpos:%s\n", temp->curpos->name);
		if (temp->nextpos)
			ft_printf("nextpos: %s\n", temp->nextpos->name);
		temp = temp->next;
	}
}

t_ant	*new_ant_node(t_node *start, int nb)
{
	t_ant *new;

	new = (t_ant *)malloc(sizeof(t_ant));
	new->cnt = nb;
	new->curpos = start;
	new->nextpos = 0;
	new->x = start->nx;
	new->y = start->ny;
	new->next = 0;
	new->nextpos = 0;
	return (new);
}

void	append_ant_node(t_prop *xt, t_node *start, int nb)
{
	t_ant *temp;

	temp = xt->ants;
	while (temp->next)
		temp = temp->next;
	temp->next = new_ant_node(start, nb);
}

void	create_ant_list(t_prop *xt)
{
	t_node *start;
	int cnt;

	cnt = 1;
	start = find_start(xt->elems);
	xt->ants = new_ant_node(start, cnt);
	while (++cnt <= xt->f_ants)
		append_ant_node(xt, start, cnt);
	update_ant_positions(xt, xt->lines->str);
}

void	move_ants(t_prop *xt)
{
	t_ant	*temp;
	t_node	*end;

	end = find_end(xt->elems);
	temp = xt->ants;
	while (temp)
	{
		if (temp->nextpos && temp->curpos != end)
		{
			temp->curpos = temp->nextpos;
			temp->x = temp->nextpos->nx;
			temp->y = temp->nextpos->ny;
		}
		temp = temp->next;
	}
}

void	free_line(t_prop *xt)
{
	t_lines *temp;

	if (xt->lines->next)
		temp = xt->lines->next;
	else
		temp = 0;
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
				temp->nextpos = find_node(xt->elems, section[1]);
		}
		temp = temp->next;
	}
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
		free_line(xt);
	}
}
