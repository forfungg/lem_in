/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:39:42 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 14:41:35 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t			x;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	x = 0;
	if (!s1 || !s2)
		return (0);
	while (c1[x] != '\0' || c2[x] != '\0')
	{
		if (c1[x] != c2[x])
			return (0);
		x++;
	}
	return (1);
}
