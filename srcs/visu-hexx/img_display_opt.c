/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:28:16 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 23:28:25 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void	display_all(t_prop *xt)
{
	display_background(xt);
	display_lines(xt);
	display_uniroom(xt);
	display_ants(xt);
	display_stats(xt);
}

void	display_paths(t_prop *xt)
{
	display_background(xt);
	display_uniroom(xt);
	display_path(xt);
	display_ants(xt);
	display_stats(xt);
}

void	display_black(t_prop *xt)
{
	display_path(xt);
	display_ants(xt);
	display_stats(xt);
}
