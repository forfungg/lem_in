/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:38:47 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 23:39:13 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

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
		error_exit("Incorrect links");
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
