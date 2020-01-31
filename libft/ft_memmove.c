/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:08:40 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 11:42:34 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *pd;
	unsigned char *ps;

	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	if (ps < pd && ps + len > pd)
		while (len--)
			pd[len] = ps[len];
	else
		pd = ft_memcpy(dst, src, len);
	return (pd);
}
