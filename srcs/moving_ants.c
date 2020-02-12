/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:03:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/12 17:18:49 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_n_strings(t_paths *paths)
{
	int		max;
	t_paths	*head;

	max = get_t_len(paths);
	head = paths;
	while (paths->next)
	{
		if (get_t_len(paths->next) > max)
		{
			head = paths->next;
			max = get_t_len(head);
		}
		paths = paths->next;
	}
	return (max + 1);
}

char	*str_append(char *str, int nb, char *name)
{
	char	*new;
	char	*index;
	char	*tmp;

	new = ft_strnew(1);
	new[0] = 'L';
	index = ft_itoa(nb);
	tmp = ft_strjoin(new, index);
	free(new);
	new = ft_strjoin(tmp, "-");
	free(tmp);
	tmp = ft_strjoin(new, name);
	free(new);
	new = ft_strjoin(tmp, " ");
	free(tmp);
	if (!str)
	{
		// *str = new;
		return (new);
	}
	tmp = ft_strjoin(str, new);
	free(new);
	return (tmp);
}

void	move_ants(t_prop *xt, t_paths *paths)
{
	char	**out;
	int		cnt;
	int		len;
	t_que	*tmp;
	t_paths	*head;
	char	*new;

	if (!paths)
		return ;
	len = get_n_strings(paths);
	out = (char **)malloc(len * sizeof(char *));
	cnt = 0;
	while (cnt < len)
	{
		out[cnt] = NULL;
		cnt++;
	}
	head = paths;
	while (xt->ant_cnt <= xt->f_ants)
	{
		if (paths->ants)
		{
			cnt = 0;
			tmp = paths->path->next;
			while (tmp)
			{
				new = str_append(out[cnt], xt->ant_cnt, tmp->node->name);
				free(out[cnt]);
				out[cnt] = ft_strdup(new);
				free(new);
				cnt++;
				tmp = tmp->next;
			}
			xt->ant_cnt += 1;
			paths->ants--;
		}
		paths = paths->next;
		if (!paths)
			paths = head;
	}
	cnt = 0;
	ft_printf("Results:\n");
	while (cnt < len)
	{
		ft_printf("%s\n\n", out[cnt]);
		cnt++;
	}
}
