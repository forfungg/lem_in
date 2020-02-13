/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:14:40 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/13 16:47:51 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	fill_image(int *img_data, int img_w, int img_h, int color)
{
	int count_h;
	int count_w;

	count_h = -1;
	while (++count_h < img_h)
	{
		count_w = -1;
		while (++count_w < img_w)
			img_data[count_h * img_w + count_w] = color;
	}
}
