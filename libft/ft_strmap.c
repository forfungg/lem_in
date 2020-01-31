/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:27:54 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 15:05:43 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	len;
	unsigned int	x;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	x = 0;
	while (x < len)
	{
		str[x] = f(s[x]);
		x++;
	}
	str[x] = '\0';
	return (str);
}
