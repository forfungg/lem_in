/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_input_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:45:12 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/24 19:21:27 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		process_room(t_prop *xt, char *p, int i)
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
	{
		ft_printf("Debug: room = %s, x = %s, char = '%c'\n", name, x, p[i]);
		error_exit("Invalid X-coordinate");
	}
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
	// ft_printf("Room '%s' Done\n", name);
	return (i + 1);
}

static void	add_link(t_prop *xt, t_node *node1, t_node *node2)
{
	if (node1 == NULL || node2 == NULL)
		error_exit("Wrong Input");
	if (!add_neighbor(node1, node2) || !add_neighbor(node2, node1))
	{
		ft_printf("Failed to create link:\n%s - %s\n", node1->name, node2->name);
		error_exit("");
	}
}

int		process_link(t_prop *xt, char *p, int i)
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
	add_link(xt, node1, node2);
	// ft_printf("Added Link %s -> %s\n", node1->name, node2->name);
	if (!end)
	{
		p[i] = '\n';
		i++;
	}
	return (i);
}

int		process_ant(t_prop *xt, char *p, int i)
{
	xt->f_ants = ft_latoi(p);
	if (xt->f_ants > INT_MAX)
		error_exit("Amount of ants is beyond integer range");
	// nft_pritf("Saved Ants = %d\n", xt->f_ants);
	xt->n_ants += 1;
	if (p[i] == '\0')
		return (i);
	else
	{
		p[i] = '\0';
		return (i + 1);
	}
}

int		process_comment(t_prop *xt, char *p)
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

static int	process_info(t_prop *xt, char *p, int i)
{
	int		digit;
	int		ret;

	digit = 1;
	while (p[i] != ' ' && p[i] != '\n' && p[i] != '-')
	{
		digit = ft_isdigit(p[i]) && digit ? 1 : 0;
		i++;
	}
	if (p[i] == ' ')
		ret = process_room(xt, p, i);
	else if (p[i] == '-')
		ret = process_link(xt, p, i);
	else if (p[i] == '\n' && digit)
		ret = process_ant(xt, p, i);
	else
		error_exit("Wrong Input");
	return (ret);
}

void	process_input(t_prop *xt)
{
	char	*p;

	p = xt->input;
	while (p[0] != '\0')
	{
		if (p[0] == '#' || p[0] == 'L')
			p += process_comment(xt, p);
		else
			p += process_info(xt, p, 0);
	}
}
