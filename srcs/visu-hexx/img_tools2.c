/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:27:09 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/01 00:31:39 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int	get_rand(int one, int two)
{
	int ret;

	ret = rand() % (one + 1 - two) + two;
	return (ret);
}

int	get_cor_x(int coord, t_prop *xt)
{
	int		ret;
	double	coef;

	coef = (W_W - IMGS->roomsize - 20) / (double)xt->max_x;
	ret = 10 + coord * coef;
	return (ret);
}

int	get_cor_y(int coord, t_prop *xt)
{
	int		ret;
	double	coef;
	int		allowed_len;

	allowed_len = (W_H - (W_H / 6)) - IMGS->roomsize - 20;
	coef = allowed_len / (double)xt->max_y;
	ret = 10 + (W_H / 6) + (coord * coef);
	return (ret);
}
