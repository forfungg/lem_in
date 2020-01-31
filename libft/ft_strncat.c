/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:51:56 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 12:07:29 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t x;
	size_t y;

	y = 0;
	x = ft_strlen(s1);
	while (s2[y] != '\0' && y < n)
	{
		s1[x] = s2[y];
		x++;
		y++;
	}
	s1[x] = '\0';
	return (s1);
}
