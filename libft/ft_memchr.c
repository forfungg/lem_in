/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:07:28 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/19 16:24:31 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	cnt;

	str = (char *)s;
	cnt = 0;
	while (cnt < n)
	{
		if (str[cnt] == c)
			return (str + cnt);
		cnt++;
	}
	return (0);
}
