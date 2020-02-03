/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:05:06 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/03 11:17:18 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Exits the program with an error message
** Clear mememory?
*/

void	error_exit(char *msg)
{
	ft_printf("{RED}{B}ERROR:{EOC} %s\n", msg);
	exit(-1);
}
