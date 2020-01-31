/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:21:04 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 15:43:35 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content == 0)
	{
		node->content = 0;
		node->content_size = 0;
	}
	else
	{
		if (!(node->content = malloc(content_size)))
		{
			free(node);
			return (0);
		}
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
