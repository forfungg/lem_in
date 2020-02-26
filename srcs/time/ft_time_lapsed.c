/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_lapsed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:14:50 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/26 20:17:11 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time_code.h"

double		ft_time_lapsed(clock_t start, clock_t end)
{
	return ((double)(end - start) / CLOCKS_PER_SEC);
}
