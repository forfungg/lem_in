/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:18:08 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/23 16:19:25 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t sizeorig, size_t sizenew)
{
	void *new;

	if (!ptr && sizenew)
	{
		if (!(new = ft_memalloc(sizenew)))
			return (0);
	}
	else if (ptr && !sizenew)
	{
		if (!(new = ft_memalloc(1)))
			return (0);
		ft_memdel(&ptr);
	}
	else if (ptr && sizenew)
	{
		if (!(new = ft_memalloc(sizenew)))
			return (0);
		ft_memmove(new, ptr, sizeorig);
		ft_memdel(&ptr);
	}
	else
		return (0);
	return (new);
}
