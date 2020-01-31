/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:24:01 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/19 16:24:50 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*to;
	char	*from;
	size_t	cnt;

	to = (char *)dst;
	from = (char *)src;
	cnt = 0;
	if (dst == src || n == 0)
		return (dst);
	while (cnt < n)
	{
		to[cnt] = from[cnt];
		cnt++;
	}
	return (dst);
}
