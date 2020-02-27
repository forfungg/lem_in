/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:05:06 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 13:26:05 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

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
