/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_marks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:23:46 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 12:26:30 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time_code.h"

void	ft_clear_marks(t_tmd **marks)
{
	int i;

	i = 0;
	while (marks[i])
	{
		free(marks[i]);
		i++;
	}
	free(marks);
}
