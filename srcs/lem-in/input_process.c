/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:13:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/17 11:24:56 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clear_props(char **props)
{
	int i;

	i = 0;
	while (props[i])
	{
		free(props[i]);
		i++;
	}
	free(props);
}

int		count_elems(char **array)
{
	int cnt;

	cnt = 0;
	while (array[cnt] != 0)
		cnt++;
	return (cnt);
}

int		is_number(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		if (!ft_isdigit(str[cnt]))
			return (0);
		cnt++;
	}
	return (1);
}

int		is_ants(char *str, t_prop *xt)
{
	if (is_number(str) == 1)
		return (1);
	return (0);
}

/*
** check_link
*/

int		is_link(char *line, t_prop *xt)
{
	int		cnt;
	char	**props;

	props = ft_strsplit(line, '-');
	cnt = count_elems(props);
	clear_props(props);
	return (cnt != 2 ? FALSE : TRUE);
}
