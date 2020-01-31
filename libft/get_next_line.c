/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:24:09 by asolopov          #+#    #+#             */
/*   Updated: 2019/11/11 14:30:31 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(char **overflow, char **line)
{
	size_t	len;
	char	*temp;

	len = 0;
	while ((*overflow)[len] != '\n' && (*overflow)[len] != '\0')
		len++;
	if ((*overflow)[len] == '\n')
	{
		if (!(*line = ft_strsub((*overflow), 0, len)))
			return (-1);
		if (!(temp = ft_strdup(&((*overflow)[len + 1]))))
			return (-1);
		free(*overflow);
		*overflow = temp;
		if ((*overflow)[0] == 0)
			ft_strdel(overflow);
	}
	else
	{
		if (!(*line = ft_strdup(*overflow)))
			return (-1);
		ft_strdel(overflow);
	}
	return (1);
}

static int	get_output(char **overflow, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (*overflow) == 0)
		return (0);
	else
		return (get_line(&(*overflow), line));
}

static int	join(char **overflow, char *buf, int fd)
{
	char	*temp;

	if (!(temp = ft_strjoin(overflow[fd], buf)))
		return (-1);
	free(overflow[fd]);
	overflow[fd] = temp;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*overflow[FD_SIZE];
	char		*buf;
	int			ret;

	if (!(buf = (char *)malloc((BUFF_SIZE + 1) * sizeof(char))))
		return (-1);
	if (fd < 0 || line == 0 || fd > FD_SIZE)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (overflow[fd] == 0)
			overflow[fd] = ft_strdup(buf);
		else
		{
			if (join(overflow, buf, fd) != 1)
				return (-1);
		}
		if (ft_strchr(overflow[fd], '\n'))
			break ;
	}
	free(buf);
	return (get_output(&overflow[fd], line, ret));
}
