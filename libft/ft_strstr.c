/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:07:41 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/19 16:26:26 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int x;
	int y;
	int len;

	x = 0;
	y = 0;
	len = ft_strlen(needle);
	if (*needle)
	{
		while (haystack[x])
		{
			while (needle[y] == haystack[x + y])
			{
				if (y == len - 1)
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
