/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:37:00 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/27 13:26:52 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int		count_elems(char **array)
{
	int cnt;

	cnt = 0;
	while (array[cnt] != 0)
		cnt++;
	return (cnt);
}

int		is_number(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		if (!ft_isdigit(str[cnt]))
			return (0);
		cnt++;
	}
	return (1);
}

int		is_ants(char *str, t_prop *xt)
{
	if (is_number(str) == 1 && strlen(str) != 0)
		return (1);
	return (0);
}

/*
** check_link
*/

int		is_link(char *line, t_prop *xt)
{
	int		cnt;
	char	**props;

	props = ft_strsplit(line, '-');
	cnt = count_elems(props);
	clear_split(props);
	return (cnt != 2 ? FALSE : TRUE);
}

/*
** check_room
*/

int		is_room(char *line, t_prop *xt)
{
	char	**props;
	int		ret;

	ret = 0;
	props = ft_strsplit(line, ' ');
	if (count_elems(props) == 3 && (is_number(props[1]) && is_number(props[2])))
		ret = 1;
	clear_split(props);
	return (ret);
}

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

void	save_room(char *line, t_prop *xt)
{
	char **props;

	props = ft_strsplit(line, ' ');
	if (xt->elems == 0)
		new_node(props, xt);
	else
		prepend_node(props, xt);
	xt->n_rooms += 1;
	clear_split(props);
}

/*
** saves link: kudos Jiri
*/

void	save_link(char *line, t_prop *xt)
{
	char	**props;
	t_node	*node1;
	t_node	*node2;

	props = ft_strsplit(line, '-');
	node1 = find_node(xt->elems, props[0]);
	node2 = find_node(xt->elems, props[1]);
	clear_split(props);
	if (node1 == 0 || node2 == 0)
	{
		ft_putstr("Nothing found, suka\n");
		exit(0);
	}
	add_neighbor(xt, node1, node2);
	add_neighbor(xt, node2, node1);
}

/*
** turns start/end flags and keeps count of occurences
*/

void	save_commands(char *str, t_prop *xt)
{
	if (ft_strequ(str, "##start") == 1)
	{
		xt->f_start = 1;
		xt->n_start += 1;
	}
	else if (ft_strequ(str, "##end") == 1)
	{
		xt->f_end = 1;
		xt->n_end += 1;
	}
	else if (str[0] == 'L')
		save_line(xt, str);
}

void	save_ants(char *str, t_prop *xt)
{
	xt->f_ants = ft_atoi(str);
	xt->n_ants += 1;
}

void	read_input(t_prop *xt)
{
	char	*line;
	int		maxflow;

	xt->all_paths = NULL;
	while (get_next_line(xt->fd, &line) > 0)
	{
		if (line[0] == '#' || line[0] == 'L')
			save_commands(line, xt);
		else if (is_ants(line, xt) == 1)
			save_ants(line, xt);
		else if (is_room(line, xt) == 1)
			save_room(line, xt);
		else if (is_link(line, xt) == 1)
			save_link(line, xt);
		free(line);
	}
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