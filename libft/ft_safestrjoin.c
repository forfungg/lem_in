/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safestrjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:49:27 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 13:28:39 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Safely joins two strings together.
** -
** If (pos == 0) STR+ADD
** if (pos == 1) ADD+STR
*/

#include "libft.h"

void	ft_safestrjoin(char **str, char *add, int pos)
{
	char	*temp;

	if (pos == 0)
		temp = ft_strjoin(*str, add);
	else
		temp = ft_strjoin(add, *str);
	ft_strdel(str);
	*str = temp;
}
