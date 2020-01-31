/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:33:03 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/19 16:25:25 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int x;
	int y;

	x = ft_strlen(s1);
	y = 0;
	while (s2[y] != '\0')
	{
		s1[x + y] = s2[y];
		y++;
	}
	s1[x + y] = '\0';
	return (s1);
}
