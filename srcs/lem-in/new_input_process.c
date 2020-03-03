/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_input_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:45:12 by jnovotny          #+#    #+#             */
/*   Updated: 2020/03/03 14:24:16 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			process_room(t_prop *xt, char *p, int i)
{
	char *name;
	char *x;
	char *y;

	name = p;
	p[i] = '\0';
	i++;
	x = p + i;
	while (ft_isdigit(p[i]))
		i++;
	if (p[i] != ' ')
		error_exit("Invalid X-coordinate");
	p[i] = '\0';
	i++;
	y = p + i;
	while (ft_isdigit(p[i]))
		i++;
	if (p[i] != '\n' && p[i] != '\0')
		error_exit("Invalid Y-coordinate");
	if (p[i] == '\0')
		i--;
	else
		p[i] = '\0';
	is_valid_room(xt, name, get_coord(x), get_coord(y));
	return (i + 1);
}

static void	add_link(t_node *node1, t_node *node2)
{
	if (node1 == NULL || node2 == NULL)
		error_exit("Wrong Input");
	if (!add_neighbor(node1, node2) || !add_neighbor(node2, node1))
		error_exit("Failed to create a link");
}

int			process_link(t_prop *xt, char *p, int i)
{
	t_node	*node1;
	t_node	*node2;
	int		tmp;
	int		end;

	end = 0;
	if (xt->pathways == NULL)
		xt->pathways = p;
	p[i] = '\0';
	node1 = find_node(xt->elems, p);
	p[i] = '-';
	i++;
	tmp = i;
	while (p[i] != '\n' && p[i] != '\0')
		i++;
	if (p[i] == '\0')
		end = 1;
	else
		p[i] = '\0';
	node2 = find_node(xt->elems, p + tmp);
	add_link(node1, node2);
	if (!end)
		p[i] = '\n';
	return (end ? i : i + 1);
}

int			process_ant(t_prop *xt, char *p, int i)
{
	xt->f_ants = ft_latoi(p);
	if (xt->f_ants > INT_MAX)
		error_exit("Amount of ants is beyond integer range");
	xt->n_ants += 1;
	if (p[i] == '\0')
		return (i);
	else
	{
		p[i] = '\0';
		return (i + 1);
	}
}

/*
** Needs To Deal with Other comments and commands!
*/

int			process_comment(t_prop *xt, char *p)
{
	int		i;
	int		end;

	i = 0;
	end = 0;
	while (p[i] != '\n' && p[i] != '\0')
		i++;
	if (p[i] == '\0')
		end = 1;
	else
		p[i] = '\0';
	if (ft_strequ(p, "##start") == 1)
	{
		xt->f_start = 1;
		xt->n_start += 1;
	}
	else if (ft_strequ(p, "##end") == 1)
	{
		xt->f_end = 1;
		xt->n_end += 1;
	}
	if (!end)
		p[i++] = '\n';
	return (i);
}
