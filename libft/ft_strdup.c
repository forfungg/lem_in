/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:14:53 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/22 11:21:52 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		x;
	int		len;
	char	*dest;

	x = 0;
	len = ft_strlen(src);
	if (!(dest = (char *)malloc(sizeof(*dest) * (len + 1))))
		return (0);
	while (x <= len)
	{
		dest[x] = src[x];
		x++;
	}
	return (dest);
}
