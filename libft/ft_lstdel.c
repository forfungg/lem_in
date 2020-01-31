/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:45:38 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 16:51:29 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (*alst && del)
	{
		while (*alst)
		{
			temp = *alst;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = temp->next;
		}
	}
}
