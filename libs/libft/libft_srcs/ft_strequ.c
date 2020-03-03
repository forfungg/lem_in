/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:48:57 by jnovotny          #+#    #+#             */
/*   Updated: 2020/03/03 21:46:01 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

/*
** Lexicographical comparison between s1 and s2. If the 2
** strings are identical the function returns 1, or 0 otherwise.
*/

// int		ft_strequ(char const *s1, char const *s2)
// {
// 	if (s1 && s2)
// 		if (ft_strcmp(s1, s2) == 0)
// 			return (1);
// 	return (0);
// }

int		ft_strequ(char const *s1, char const *s2)
{
	while (s1[0] != '\0' && !(*(s1) ^ *(s2)))
	{
		s1++;
		s2++;
	}
	return (!(*(s1) ^ *(s2)));
}

// int main(int ac, char **av)
// {
// 	if (ac == 3)
// 		printf("%d\n", ft_strequ(av[1], av[2]));
// 	else if (ac == 1)
// 	{
// 		printf("True = %d\n", ft_strequ("ahoj", "ahoj"));
// 		printf("False = %d\n", ft_strequ("ahoj", "ahox"));
// 	}
// }