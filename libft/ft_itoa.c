/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:01:43 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 14:30:55 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int			len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int			len;
	long int	x;
	char		*array;

	x = n;
	len = get_len(x);
	if (!(array = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	array[len--] = '\0';
	if (x == 0)
		array[len--] = 48;
	if (x < 0)
	{
		array[0] = '-';
		x *= -1;
	}
	while (x > 0)
	{
		array[len--] = 48 + x % 10;
		x = x / 10;
	}
	return (array);
}
