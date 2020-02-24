/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_management4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:39:15 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/24 11:23:56 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Function add_neighbor()
** Adds a neigbor node the the given node.
** Returns True upon success, or False otherwise
**		create_neighbor() - mallocs memory and attaches neighbor
**		append_neighbor() - crates tmp array of all neighbors
**							and appends the new one to it. Then
**							resizes the nodes neigbor array and
**							copies all neigbors to it from tmp.
**							Frees tmp and returns True upon success.
*/

static int		create_neighbor(t_node *node, t_node *neighbor)
{
	node->ngb = (t_node **)malloc(sizeof(t_node *) * 2);
	if (!node->ngb)
		error_exit("malloc at create_neighbor");
	node->ngb[0] = neighbor;
	node->ngb[1] = NULL;
	return (TRUE);
}

static int		copy_pasta(t_node **src, t_node **dest)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = NULL;
	return (i);
}

static int		append_neighbor(t_node *node, t_node *neighbor)
{
	t_node	**tmp;
	int		i;

	tmp = (t_node **)malloc(sizeof(t_node *) *\
		(count_neighbors(node->ngb) + 2));
	if (!tmp)
		error_exit("tmp malloc at append_neighbor");
	i = copy_pasta(node->ngb, tmp);
	tmp[i] = neighbor;
	tmp[i + 1] = NULL;
	free(node->ngb);
	node->ngb = (t_node **)malloc(sizeof(t_node *) *\
		(count_neighbors(tmp) + 1));
	if (!node->ngb)
		error_exit("node->ngb malloc at append_neighbor");
	i = copy_pasta(tmp, node->ngb);
	free(tmp);
	return (TRUE);
}

static int		already_exists(t_node *node, char *new)
{
	int		i;

	i = 0;
	if (ft_strequ(node->name, new))
		return (TRUE);
	while (node->ngb[i])
	{
		if (ft_strequ(node->ngb[i]->name, new))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int				add_neighbor(t_node *node, t_node *neighbor)
{
	if (!node || !neighbor)
		return (FALSE);
	// ft_printf("Creating neighbor %s to %s - ", node->name, neighbor->name);
	if (node->ngb == NULL)
	{
		create_neighbor(node, neighbor);
		// ft_printf("First Neighbor\n");
	}
	else
	{
		if (already_exists(node, neighbor->name))
		{
			// ft_printf("Already exists\n");
			return (TRUE);
		}
		if (!append_neighbor(node, neighbor))
		{
			// ft_printf("Failed to Append!\n");
			return (FALSE);
		}
	}
	// ft_printf("Done!\n");
	return (TRUE);
}
