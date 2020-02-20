/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:39:15 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/20 18:56:14 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

/*
** Create node
*/

t_node	*create_node(char *name, int x, int y)
{
	t_node	*node;

	node = (t_node *)ft_memalloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->name = ft_strdup(name);
	node->x = x;
	node->y = y;
	node->ngb = NULL;
	node->cap = NULL;
	node->path = 0;
	node->empty = 1;
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
		i = 0;
		free(node->cap);
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
	if (node->ngb == NULL)
		create_neighbor(node, neighbor);
	else
	{
		if (already_exists(node, neighbor->name))
			return (TRUE);
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

/*
** Returns the starting node of the graph
*/

t_node	*find_start(t_node *list)
{
	while (list)
	{
		if (list->start)
			return (list);
		list = list->next;
	}
	return (NULL);
}

/*
** Returns the ending node of the graph
*/

t_node	*find_end(t_node *list)
{
	while (list)
	{
		if (list->end)
			return (list);
		list = list->next;
	}
	return (NULL);
}

/*
** Resets "visited" value of all nodes in the list
*/

void			reset_visits(t_node *list)
{
	while (list)
	{
		list->visited = FALSE;
		list = list->next;
	}
}

/*
** Create capacities for edges
*/

void			capacitize_ngbs(t_node *list)
{
	int i;
	int	cnt;

	while (list)
	{
		if (list->ngb)
		{
			cnt = count_neighbors(list->ngb);
			list->cap = (int *)ft_memalloc(sizeof(int) * cnt);
			if (!(list->cap))
				error_exit("Malloc at capacitize_ngbs");
			i = 0;
			while (i < cnt)
				list->cap[i++] = CAPACITY;
		}
		list = list->next;
	}
}
