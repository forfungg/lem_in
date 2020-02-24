/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:30:01 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/24 15:11:28 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

static t_prop	*init_visuhex(void)
{
	t_prop	*xt;

	xt = (t_prop *)malloc(sizeof(t_prop));
	ft_bzero(xt, sizeof(xt));
	xt->elems = NULL;
	xt->all_paths = NULL;
	xt->n_start = 0;
	xt->n_end = 0;
	xt->n_ants = 0;
	xt->n_rooms = 0;
	xt->imgs = (t_img *)malloc(sizeof(t_img));
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(xt->mlx_ptr, W_W, W_H, W_NAME);
	return (xt);
}

static void		delete_lines (t_lines *lines)
{
	t_lines *temp;

	temp = lines;
	while (lines)
	{
		temp = lines->next;
		free(lines->str);
		free(lines);
		lines = temp;
	}
}

static void		delete_ants(t_ant *ants)
{
	t_ant *temp;

	if (!ants)
		return ;
	temp = ants;
	while (temp)
	{
		temp = ants->next;
		free(ants);
		ants = temp;
	}
}

static void		delete_pathss(t_paths *paths)
{
	t_paths *temp;

	temp = paths;
	while (paths)
	{
		temp = paths->next;
		free(paths);
		paths = temp;
	}
}	

static void		clear_memory(t_prop *xt)
{
	delete_list(xt->elems);
	delete_lines(xt->lines);
	delete_pathss(xt->all_paths);
	free(xt->imgs);
	free(xt);
}

int				main(int argc, char **argv)
{
	t_prop *xt;
	char *line;

	xt = init_visuhex();
	read_input(xt);
	//draw_farm(xt);
	clear_memory(xt);
	while (1)
	{
		
	}
}
