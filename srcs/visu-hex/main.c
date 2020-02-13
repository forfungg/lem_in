/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:30:01 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/13 14:48:22 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visual.h"

void	init_window(t_prop *xt)
{
	xt->mlx_ptr = mlx_init();
	xt->win_ptr = mlx_new_window(xt->mlx_ptr, 1920, 1080, "VISU_HEXX");
	mlx_loop(xt->mlx_ptr);
}

int main(int argc, char **argv)
{
	t_prop	*xt;

	if (!(xt = (t_prop *)malloc(sizeof(t_prop))))
		ft_putchar('k');
	init_window(xt);
}