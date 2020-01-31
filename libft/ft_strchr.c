/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:27:06 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/19 16:25:25 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int len;
	int x;

	len = ft_strlen(s);
	x = 0;
	while (x <= len)
	{
		if (c == s[x])
			return ((char*)&s[x]);
		x++;
	}
	return (0);
}
