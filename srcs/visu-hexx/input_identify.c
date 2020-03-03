/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_identify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:39:26 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 23:40:06 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

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
	if (is_number(str) == 1 && strlen(str) != 0)
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
	clear_split(props);
	return (cnt != 2 ? FALSE : TRUE);
}

/*
** check_room
*/

int		is_room(char *line, t_prop *xt)
{
	char	**props;
	int		ret;

	ret = 0;
	props = ft_strsplit(line, ' ');
	if (count_elems(props) == 3 && (is_number(props[1]) && is_number(props[2])))
		ret = 1;
	clear_split(props);
	return (ret);
}
