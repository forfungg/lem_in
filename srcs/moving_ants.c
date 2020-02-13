/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:03:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/13 13:00:10 by asolopov         ###   ########.fr       */
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
	return (max - 1);
}

void	ft_safestrjoin(char **str, char *add, int pos)
{
	char	*temp;

	if (pos == 0)
		temp = ft_strjoin(*str, add);
	else
		temp = ft_strjoin(add, *str);
	ft_strdel(str);
	*str = temp;
}

char	*str_append(char *str, int nb, char *name)
{
	char	*ret;
	char	*temp;
	char	*num;

	ret = ft_strnew(1);
	ret[0] = 'L';
	num = ft_itoa(nb);
	ft_safestrjoin(&ret, num, 0);
	free(num);
	ft_safestrjoin(&ret, "-", 0);
	ft_safestrjoin(&ret, name, 0);
	ft_safestrjoin(&ret, " ", 0);
	if (!str)
		return (ret);
	temp = ft_strjoin(str, ret);
	free(ret);
	return (temp);
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
				new = str_append(out[cnt + tmp->shift], xt->ant_cnt, tmp->node->name);
				free(out[cnt + tmp->shift]);
				out[cnt + tmp->shift] = ft_strdup(new);
				free(new);
				tmp->shift += 1;
				tmp = tmp->next;
				cnt++;
			}
			xt->ant_cnt += 1;
			paths->ants--;
		}
		paths = paths->next;
		if (!paths)
		{
			paths = head;
		}
	}
	cnt = 0;
	while (out[cnt])
	{
		if (out[cnt + 1] == 0)
			ft_printf("%s\n", out[cnt]);
		else
			ft_printf("%s\n\n", out[cnt]);
		free(out[cnt]);
		cnt++;
	}
	free(out);
}
