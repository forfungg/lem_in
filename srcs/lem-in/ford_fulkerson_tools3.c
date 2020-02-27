/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson_tools3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:19:18 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 13:19:45 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Replaces current set of solution paths with new one
*/

static t_paths	*copy_paths(t_paths *paths)
{
	t_paths *new;

	new = NULL;
	while (paths)
	{
		new = append_path(new, que_copy(paths->path));
		paths = paths->next;
	}
	return (new);
}

void			new_solution(t_paths **storage, t_paths **new)
{
	if (!storage)
		*storage = copy_paths(*new);
	else
	{
		delete_paths(*storage);
		*storage = copy_paths(*new);
	}
}
