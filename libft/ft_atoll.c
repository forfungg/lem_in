/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:27:29 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 14:43:05 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoll(const char *str)
{
	unsigned int	ndx;
	long long		result;
	int				sign;

	ndx = 0;
	result = 0;
	sign = 1;
	while (str[ndx] == 32 || str[ndx] == 10 || str[ndx] == 9 || \
			str[ndx] == 12 || str[ndx] == 13 || str[ndx] == 11)
		ndx++;
	if (str[ndx] == 43 || str[ndx] == 45)
		if (str[ndx++] == 45)
			sign = -1;
	while (str[ndx])
	{
		if (str[ndx] >= 48 && str[ndx] <= 57)
			result = result * 10 + (str[ndx] - 48);
		else
			return (result * sign);
		ndx++;
	}
	return (result * sign);
}
