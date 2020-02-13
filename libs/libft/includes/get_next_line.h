/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:55:17 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/27 12:33:24 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/file.h>
# include <sys/types.h>
# include "libft.h"

# define BUFF_SIZE 1
# define MAX_FD 1024

int	get_next_line(const int fd, char **line);

#endif
