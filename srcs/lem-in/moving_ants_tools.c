/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ants_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:03:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/17 10:46:59 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (!str)
		return (ret);
	ft_safestrjoin(&ret, " ", 1);
	temp = ft_strjoin(str, ret);
	free(ret);
	return (temp);
}

void	print_output(char **out)
{
	int		cnt;
	char	*line;

	cnt = 0;
	ft_printf("\n");
	while (out[cnt])
	{
		if (out[cnt + 1] == 0)
			ft_printf("%s\n", out[cnt]);
		else
			ft_printf("%s\n", out[cnt]);
		free(out[cnt]);
		cnt++;
	}
	free(out);
}
