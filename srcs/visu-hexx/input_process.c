/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:37:00 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/03 14:09:15 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

/*
** prepend node
*/

void	new_node(char **props, t_prop *xt)
{
	xt->elems = create_node(props[0], get_coord(props[1]), get_coord(props[2]));
	if (xt->f_start == 1)
	{
		xt->elems->start = 1;
		xt->f_start = 0;
	}
	if (xt->f_end == 1)
	{
		xt->elems->start = 1;
		xt->f_end = 0;
	}
	xt->elems->ngb = NULL;
}

void	prepend_node(char **props, t_prop *xt)
{
	t_node *new;

	new = create_node(props[0], get_coord(props[1]), get_coord(props[2]));
	if (xt->f_start == 1)
	{
		new->start = 1;
		xt->f_start = 0;
	}
	if (xt->f_end == 1)
	{
		new->end = 1;
		xt->f_end = 0;
	}
	new->next = xt->elems;
	xt->elems = new;
}

/*
** saves new room/ call prepend
*/

void	read_input(t_prop *xt)
{
	char	*line;

	xt->all_paths = NULL;
	while (get_next_line(xt->fd, &line) > 0)
	{
		if (line[0] == '#' || line[0] == 'L')
			save_commands(line, xt);
		else if (is_ants(line) == 1)
			save_ants(line, xt);
		else if (is_room(line) == 1)
			save_room(line, xt);
		else if (is_link(line) == 1)
			save_link(line, xt);
		free(line);
	}
	check_input(xt);
	xt->cpy = xt->lines;
	capacitize_ngbs(xt->elems);
	create_path_list(xt, xt->lines);
}

/*
** Checks if given string containes valid coordinate, and returns it as int.
*/

int		get_coord(char *str)
{
	long	nb;

	nb = ft_latoi(str);
	if (nb > INT_MAX || nb < 0)
		error_exit("Coordinates out of int range");
	return ((int)nb);
}
