/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:29:16 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/12 12:40:21 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(int argc, char **argv)
{
	t_prop *xt;

	xt = (t_prop *)malloc(sizeof(t_prop));
	xt->elems = 0;
	xt->n_start = 0;
	xt->n_end = 0;
	xt->n_ants = 0;
	read_input(xt);
	free(xt);
}
