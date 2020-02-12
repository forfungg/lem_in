/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:08:36 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/12 12:09:30 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Enqueue path
*/

t_paths		*append_path(t_paths *head, t_que *path)
{
	t_paths *new;
	t_paths *tmp;

	if (!(new = (t_paths *)malloc(sizeof(t_paths))))
		error_exit("Malloc at append_path()");
	new->ants = 0;
	new->im_min = 0;
	new->hold_total = 0;
	new->path = path;
	new->next = NULL;
	if (!head)
		return (new);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (head);
}

/*
** Pop first path
*/

t_que		*pop_path(t_paths **all_paths)
{
	t_paths *tmp;
	t_que	*path;

	if (!all_paths || !*all_paths)
		return (NULL);
	tmp = *all_paths;
	*all_paths = (*all_paths)->next;
	path = tmp->path;
	free(tmp);
	return (path);
}

/*
** Delete paths
*/

void	delete_paths(t_paths *all_paths)
{
	t_paths *tmp;

	while (all_paths)
	{
		tmp = all_paths;
		all_paths = all_paths->next;
		que_delete(tmp->path);
		free(tmp);
	}
}
