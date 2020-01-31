/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:29:16 by jnovotny          #+#    #+#             */
/*   Updated: 2020/01/31 16:16:18 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int argc, char **argv)
{
	t_prop *xt;

	xt = (t_prop *)malloc(sizeof(t_prop));
	read_input(xt);
}
