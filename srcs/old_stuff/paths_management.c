/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:02:11 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/10 14:07:16 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Initializes all paths array
*/

t_que	**all_paths_init(t_que *new)
{
	t_que **ret;

	ret = (t_que **)malloc(sizeof(t_que *) * 2);
	if (!ret)
		error_exit("Malloc failure @all_paths_init");
	ret[0] = new;
	ret[1] = NULL;
	return (ret);
}

/*
** Adds given path to the array of all_paths
*/

static int		copy_paste(t_que **src, t_que **dest)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

static int		resize_patharray(t_que **all)
{
	int		c;
	int		i;
	t_que	**tmp;

	c = 0;
	while (all[c])
		c++;
	tmp = (t_que **)malloc(sizeof(t_que *) * (c + 1));
	if (!tmp)
		error_exit(" Tmp malloc failure @resize_patharray");
	i = copy_paste(all, tmp);
	tmp[i] = NULL;
	free(all);
	all = (t_que **)malloc(sizeof(t_que *) * (c + 2));
	if (!tmp)
		error_exit("All malloc failure @resize_patharray");
	i = copy_paste(tmp, all);
	return (i);
}

void	append_path(t_que **all, t_que *new)
{
	int i;

	if (!all)
		all = all_paths_init(new);
	i = resize_patharray(all);
	all[i] = new;
	all[i + 1] = NULL;
}

/*
** Pops the first path from the list of all_paths
*/

t_que	*pop_path(t_que **all)
