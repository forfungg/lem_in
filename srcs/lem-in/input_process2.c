/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:13:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/17 11:33:41 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	clear_props(props);
	return (ret);
}

/*
** prepend node
*/

void	new_node(char **props, t_prop *xt)
{
	xt->elems = (t_node *)malloc(sizeof(t_node));
	xt->elems->empty = 1;
	xt->elems->visited = 0;
	xt->elems->ngb = 0;
	xt->elems->name = ft_strdup(props[0]);
	xt->elems->x = ft_atoi(props[1]);
	xt->elems->y = ft_atoi(props[2]);
	xt->elems->next = NULL;
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

	new = malloc(sizeof(t_node));
	new->empty = 1;
	new->name = ft_strdup(props[0]);
	new->x = ft_atoi(props[1]);
	new->y = ft_atoi(props[2]);
	new->visited = 0;
	new->ngb = 0;
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
	clear_props(props);
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
	clear_props(props);
	if (node1 == 0 || node2 == 0)
	{
		ft_putstr("Nothing found, suka\n");
		exit(0);
	}
	add_neighbor(node1, node2);
	add_neighbor(node2, node1);
}
