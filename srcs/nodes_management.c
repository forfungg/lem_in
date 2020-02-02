/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny < jnovotny@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:39:15 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/02 10:55:02 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Create node
*/

t_node	*create_node(char *name, int x, int y)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(t_node));
	node->name = ft_strdup(name);
	node->x = x;
	node->y = y;
	node->ngb = NULL;
	return (node);
}

/*
** Deletes node
*/

void	delete_node(t_node *node)
{
	int i;

	i = 0;
	if (!node)
		return ;
	if (node->ngb != NULL)
	{
		while (node->ngb[i])
			node->ngb[i++] = NULL;
		free(node->ngb);
	}
	free(node->name);
	free(node);
}

/*
** Deletes the whole list
*/

void	delete_list(t_node *lst)
{
	t_node *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		delete_node(tmp);
	}
}

/*
** Creates node at the begining of given list and returns a pointer to it
*/

t_node	*create_front(t_node *head, char *name, int x, int y)
{
	t_node *node;

	node = create_node(name, x, y);
	return (add_front(head, node));
}

/*
** Creates a node at the back of given list and returns pointer to the head
*/

t_node	*create_back(t_node *head, char *name, int x, int y)
{
	t_node *node;

	node = create_node(name, x, y);
	return (add_back(head, node));
}

/*
** Adds node to the front of the list and returs a pointer to it
*/

t_node	*add_front(t_node *head, t_node *node)
{
	if (!node)
		return (head);
	else
	{
		node->next = head;
		return (node);
	}
}

/*
** Adds the node at the back of the list and returns a pointer to head
*/

t_node	*add_back(t_node *head, t_node *node)
{
	t_node *tmp;

	if (!head)
		return (node);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (head);
}

/*
**	Returns pointer to a node with corresponding name, otherwise NULL
*/

t_node	*find_node(t_node *head, char *name)
{
	t_node *tmp;

	tmp = head;
	while (tmp)
	{
		if (ft_strequ(name, tmp->name))
			break ;
		else
			tmp = tmp->next;
	}
	return (tmp);
}

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
		return (FALSE);
	node->ngb[0] = neighbor;
	node->ngb[1] = NULL;
	return (TRUE);
}

static int		append_neighbor(t_node *node, t_node *neighbor)
{
	t_node	**tmp;
	int		i;

	tmp = (t_node **)malloc(sizeof(t_node *) *\
		(count_neighbors(node->ngb) + 2));
	if (!tmp)
		return (FALSE);
	i = 0;
	while (node->ngb[i])
	{
		tmp[i] = node->ngb[i];
		i++;
	}
	tmp[i] = neighbor;
	tmp[i + 1] = NULL;
	free(node->ngb);
	node->ngb = (t_node **)malloc(sizeof(t_node *) *\
		(count_neighbors(tmp) + 1));
	if (!node->ngb)
		return (FALSE);
	i = 0;
	while (tmp[i])
	{
		node->ngb[i] = tmp[i];
		i++;
	}
	node->ngb[i] = NULL;
	free(tmp);
	return (TRUE);
}

int		add_neighbor(t_node *node, t_node *neighbor)
{
	if (!node || !neighbor)
		return (FALSE);
	if (node->ngb == NULL)
	{
		if (!create_neighbor(node, neighbor))
			return (FALSE);
	}
	else
	{
		if (!append_neighbor(node, neighbor))
			return (FALSE);
	}
	return (TRUE);
}

/*
** Counts amount of neighbors of the given node
*/

int				count_neighbors(t_node **neighbors)
{
	int		count;

	count = 0;
	while (neighbors[count])
		count++;
	return (count);
}
