/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:06:33 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 17:19:05 by jnovotny         ###   ########.fr       */
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
		xt->input_length += (size_t)ret;
	}
	free(buf);
}
