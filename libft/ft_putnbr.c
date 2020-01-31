/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:09:51 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/16 11:06:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long int l;

	l = nb;
	if (l < 0)
	{
		ft_putchar('-');
		l = -l;
	}
	if (l > 9)
	{
		ft_putnbr(l / 10);
		ft_putnbr(l % 10);
	}
	else
		ft_putchar(l + '0');
}
