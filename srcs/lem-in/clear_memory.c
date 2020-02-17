/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:02:47 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/17 11:03:07 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Delete paths
*/

void		delete_paths(t_paths *all_paths)
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
