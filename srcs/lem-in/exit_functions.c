/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:05:06 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/13 15:16:40 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Exits the program with an error message
** Clear mememory?
*/

void	error_exit(char *msg)
{
	perror("Error: ");
	ft_printf("{RED}{B}ERROR:{EOC} %s\n", msg);
	exit(-1);
}
