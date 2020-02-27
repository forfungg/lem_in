/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stopwatch_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:41:32 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 12:42:48 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time_code.h"

void	ft_stopwatch_del(t_tstamp *stopwatch)
{
	ft_clear_marks(stopwatch->marks);
	free(stopwatch);
}
