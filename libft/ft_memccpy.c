/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:56:33 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 13:56:33 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, \
					const void *restrict src, int c, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			cnt;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	cnt = 0;
	while (cnt < n)
	{
		to[cnt] = from[cnt];
		if (to[cnt] == (unsigned char)c)
			return ((void*)to + cnt + 1);
		cnt++;
	}
	return (0);
}
