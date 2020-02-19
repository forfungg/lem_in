/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:58:05 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/19 12:17:37 by asolopov         ###   ########.fr       */
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
	new->error = 0;
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

int		is_around(int num, int val)
{
	if (num < val)
	{
		if (num >= val * 0.98)
			return (1);
	}
	if (num > val)
	{
		if (num <= val * 1.02)
			return (1);
	}
	return (0);
}

int		is_antfinished(t_prop *xt)
{
	t_ant *temp;
	t_node *end;

	end = find_end(xt->elems);
	temp = xt->ants;
	while (temp)
	{
		if (temp->nextpos)
		{
			if (is_around(temp->x, temp->nextpos->nx))
			{
				if (is_around(temp->y, temp->nextpos->ny))
				{
					if (temp->curpos != end)
						return (1);
				}
			}
		}

		temp = temp->next;
	}
	return (0);
}

void	get_ant_steps(t_prop *xt)
{
	t_ant *temp;

	temp = xt->ants;
	while (temp)
	{
		if (temp->nextpos)
		{
			temp->stpx = (temp->nextpos->nx - temp->curpos->nx) / FRAMES;
			temp->stpy = (temp->nextpos->ny - temp->curpos->ny) / FRAMES;
		}
		temp = temp->next;
	}
}

static int	ft_abs(int x)
{
	return (x > 0 ? x : -x);
}

void	ant_algo(t_ant *ant)
{
	int	dx;
	int dy;

	dx = ft_abs(ant->nextpos->nx - ant->curpos->nx);
	dy = ft_abs(ant->nextpos->ny - ant->curpos->ny);
	if (dx > dy)
	{
		if (ant->error >= 0)
		{
			ant->error = ant->error - ant->stpy * (dy - dx);
			ant->y += ant->stpy;
		}
		else
			ant->error = ant->error + ant->stpy * dy;
		ant->x += ant->stpx;
	}
	else
	{
		if (ant->error >= 0)
		{
			ant->x += ant->stpx;
			ant->error = ant->error - ant->stpx * (dx - dy);
		}
		else
			ant->error = ant->error + ant->stpx * dx;
		ant->y += ant->stpy;
	}
}

void	ant_drawing_algo(t_prop *xt)
{
	t_ant *temp;

	temp = xt->ants;
	if (is_antfinished(xt) == 1)
	{
		move_ants(xt);
		if (xt->lines)
			update_ant_positions(xt, xt->lines->str);
	}
	else
	{
		get_ant_steps(xt);
		while (temp)
		{
			if (temp->nextpos)
			{
				ant_algo(temp);
			}
			temp = temp->next;
		}
	}
}
