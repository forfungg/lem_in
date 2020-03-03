/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson_tools2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:19:47 by jnovotny          #+#    #+#             */
/*   Updated: 2020/03/03 14:16:49 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Optimized redistribution of ants, to check the final solution length
*/

static void	extremes_path_len(t_paths *paths, int *min, int *max, int *cnt)
{
	int		current;
	int		i;

	*min = get_t_len(paths);
	*max = *min;
	i = 0;
	if (paths)
	{
		paths = paths->next;
		i++;
	}
	while (paths)
	{
		current = get_t_len(paths);
		if (current < *min)
			*min = current;
		else if (current > *max)
			*max = current;
		paths = paths->next;
		i++;
	}
	*cnt = i;
}

static int	second_square(t_paths *paths, int cnt, int ants)
{
	int d;

	d = ants / cnt;
	while (paths)
	{
		paths->ants += d;
		ants -= d;
		paths = paths->next;
	}
	return (ants);
}

int			first_square(t_paths *paths, int ants)
{
	int		min;
	int		max;
	int		cnt;
	t_paths	*tmp;

	min = INT_MAX;
	max = INT_MIN;
	extremes_path_len(paths, &min, &max, &cnt);
	if (cnt == 0 || ((max - min) * (cnt - 1) > ants))
		return (ants);
	tmp = paths;
	while (tmp)
	{
		tmp->ants = max - get_t_len(tmp);
		ants -= tmp->ants;
		tmp = tmp->next;
	}
	return (ants / cnt ? second_square(paths, cnt, ants) : ants);
}
