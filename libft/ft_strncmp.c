/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:30:39 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 13:00:39 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				x;
	unsigned char		*c1;
	unsigned char		*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	x = 0;
	while ((c1[x] != '\0' || c2[x] != '\0') && x < n)
	{
		if (c1[x] != c2[x])
			return (c1[x] - c2[x]);
		x++;
	}
	return (0);
}
