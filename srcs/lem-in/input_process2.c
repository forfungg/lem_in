/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:13:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/24 11:33:45 by jnovotny         ###   ########.fr       */
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
** Adds node to the list. If the node is starting point of given graph,
** then it'll be attached to the front, if it's end, then it'll be appended
** otherwise it'll be attached in 2nd position if available.
*/

void	attach_room(char **props, t_prop *xt)
{
	t_node *new;

	new = create_node(props[0], get_coord(props[1]), get_coord(props[2]));
	if (xt->f_start == 1)
	{
		xt->elems = add_front(xt->elems, new);
		new->start = 1;
		xt->f_start = 0;
	}
	else if (xt->f_end == 1)
	{
		xt->elems = add_back(xt->elems, new);
		new->end = 1;
		xt->end_node = new;
		xt->f_end = 0;
	}
	else
		xt->elems = add_default_room(xt->elems, new);
}

/*
** saves new room/ call prepend
*/

void	save_room(char *line, t_prop *xt)
{
	char **props;

	props = ft_strsplit(line, ' ');
	is_valid_room(xt->elems, props[0], get_coord(props[1]),\
		get_coord(props[2]));
	attach_room(props, xt);
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
	if (node1 == NULL || node2 == NULL)
		error_exit("Wrong Input");
	if (!add_neighbor(node1, node2) || !add_neighbor(node2, node1))
	{
		ft_printf("Failed to create link:\n%s - %s\n", node1->name, node2->name);
		error_exit("");
	}
}
