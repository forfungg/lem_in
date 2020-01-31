/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:11:32 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 17:50:32 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*head;
	t_list	*curr;

	if (!lst || !f)
		return (0);
	elem = f(lst);
	if (!(curr = ft_lstnew(elem->content, elem->content_size)))
		return (0);
	lst = lst->next;
	head = curr;
	while (lst)
	{
		elem = f(lst);
		if (!(curr->next = ft_lstnew(elem->content, elem->content_size)))
			return (0);
		curr = curr->next;
		lst = lst->next;
	}
	return (head);
}
