/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:15:51 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/27 13:26:59 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void		print_lines(t_prop *xt)
{
	t_lines *temp;

	temp = xt->lines;
	while (temp)
	{
		ft_printf("LINE: %s\n", temp->str);
		temp = temp->next;
	}
}

t_lines		*new_line(t_prop *xt, char *line)
{
	t_lines *new;

	new = (t_lines *)malloc(sizeof(t_lines));
	new->str = ft_strdup(line);
	new->next = 0;
	return (new);
}

void	append_line(t_prop *xt, char *line)
{
	t_lines *temp;

	temp = xt->lines;
	while (temp->next)
		temp = temp->next;
	temp->next = new_line(xt, line);
}

void	save_line(t_prop *xt, char *line)
{
	if (xt->lines == 0)
		xt->lines = new_line(xt, line);
	else
		append_line(xt, line);
}
