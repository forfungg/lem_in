/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:45:11 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 23:45:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

t_node			*find_end(t_node *list)
{
	while (list)
	{
		if (list->end)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_node			*find_start(t_node *list)
{
	while (list)
	{
		if (list->start)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_node			*find_node(t_node *head, char *name)
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
