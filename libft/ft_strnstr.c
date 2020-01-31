/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:19:00 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 12:56:33 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t x;
	size_t y;
	size_t ylen;

	x = 0;
	y = 0;
	ylen = ft_strlen(needle);
	if (*needle)
	{
		while (haystack[x] && x < len)
		{
			while (needle[y] == haystack[x + y] && (x + y < len))
			{
				if (y == ylen - 1)
					return ((char*)&haystack[x]);
				y++;
			}
			y = 0;
			x++;
		}
		return (0);
	}
	else
		return ((char*)haystack);
}
