/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stopwatch_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:58:00 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/26 20:59:27 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time_code.h"

void	ft_stopwatch_init(t_tstamp *stopwatch)
{
	stopwatch->start = 0;
	stopwatch->marks = NULL;
	stopwatch->end = 0;
}
