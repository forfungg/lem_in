/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:36:29 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/02 11:08:26 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int		split_line(char *line)
{
	int cnt;
	int ret;

	cnt = 0;
	ret = 0;
	while (line[cnt] != '\0')
	{
		if (line[cnt] == 'L')
			ret += 1;
		cnt += 1;
	}
	return (ret);
}

char	*get_ant_str(int cnt)
{
	char *out;
	char *l;
	char *num;

	l = ft_strdup("L");
	num = ft_itoa(cnt);
	out = ft_strjoin(l, num);
	free(l);
	free(num);
	return (out);
}

char	*receive_name(char *line, int cnt)
{
	char	**array;
	char	**section;
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	array = ft_strsplit(line, ' ');
	tmp = get_ant_str(cnt);
	while (array[i] && !strstr(array[i], tmp))
		i++;
	if (!array[i])
		error_exit("Ant problmes");
	section = ft_strsplit(array[i], '-');
	if (!section[1])
		error_exit("No section found");
	ret = ft_strdup(section[1]);
	clear_split(array);
	clear_split(section);
	free(tmp);
	return (ret);
}
