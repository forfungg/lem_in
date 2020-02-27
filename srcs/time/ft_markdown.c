/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markdown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:30:03 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 12:52:41 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time_code.h"

static t_tmd	*ft_new_markdown(char *name, clock_t timestamp)
{
	t_tmd	*new;

	new = (t_tmd *)malloc(sizeof(t_tmd));
	if (!new)
		return (NULL);
	new->name = name;
	new->timestamp = timestamp;
	return (new);
}

static int		count_mds(t_tmd **marks)
{
	int i;

	i = 0;
	if (!marks)
		return (i);
	while (marks[i])
		i++;
	return (i);
}

static t_tmd	**add_size_marks(t_tmd **marks, int *slot)
{
	t_tmd	**tmp;
	int		i;

	tmp = (t_tmd **)malloc(sizeof(t_tmd *) * (count_mds(marks) + 2));
	if (!tmp)
		return (marks);
	i = 0;
	while (marks && marks[i])
	{
		tmp[i] = marks[i];
		i++;
	}
	tmp[i] = NULL;
	tmp[i + 1] = NULL;
	*slot = i;
	free(marks);
	return (tmp);
}

void			ft_markdown(t_tstamp *stopwatch, char *name)
{
	int		i;
	clock_t	now;

	i = 0;
	now = clock();
	stopwatch->marks = add_size_marks(stopwatch->marks, &i);
	stopwatch->marks[i] = ft_new_markdown(name, now);
}
