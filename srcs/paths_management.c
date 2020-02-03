/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:02:11 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/03 11:22:00 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Initializes all paths array
*/

t_que	**all_paths_init(void)
{
	t_que **ret;

	ret = (t_que **)malloc(sizeof(t_que *) * 2);
	if (!ret)
		error_exit("Malloc failure @all_paths_init");
	ret[1] = NULL;
	return (ret);
}
