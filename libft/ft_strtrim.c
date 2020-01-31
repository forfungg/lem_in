/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:29:42 by asolopov          #+#    #+#             */
/*   Updated: 2019/10/21 15:09:41 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	strt;
	size_t			end;
	char			*str;

	if (!s)
		return (0);
	end = ft_strlen(s);
	strt = 0;
	while (s[strt] != '\0' && \
			(s[strt] == ' ' || s[strt] == '\t' || s[strt] == '\n'))
		strt++;
	while (strt < end && \
			(s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\n'))
		end--;
	return (str = ft_strsub(s, strt, (end - strt)));
}
