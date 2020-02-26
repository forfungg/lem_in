/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:06:33 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/24 16:58:52 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Reads the whole input string
*/

void	load_input(t_prop *xt, int fd)
{
	char	*buf;
	char	*tmp;
	int		ret;

	buf = (char *)malloc(LEM_BUF + 1);
	while (0 < (ret = read(fd, buf, LEM_BUF)))
	{
		buf[ret] = '\0';
		if (xt->input == NULL)
			xt->input = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(xt->input, buf);
			free(xt->input);
			xt->input = ft_strdup(tmp);
			free(tmp);
		}
	}
	free(buf);
	xt->in_point = 0;
}

/*
** Get next line from the input string
*/

char	*lem_getnextline(t_prop *xt)
{
	char	*ret;
	size_t	i;

	if (xt->input == NULL || xt->input[xt->in_point] == '\0')
		return (NULL);
	i = xt->in_point;
	while (xt->input[i] != '\n' && xt->input[i] != '\0')
		i++;
	ret = ft_strsub(xt->input, xt->in_point, i - xt->in_point);
	if (xt->input[i] != '\0')
		xt->in_point = i + 1;
	else
		xt->in_point = i;
	return (ret);
}
