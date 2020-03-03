/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_input_process2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:45:12 by jnovotny          #+#    #+#             */
/*   Updated: 2020/03/03 14:23:46 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	order_check(t_prop *xt, char *p, int i)
{
	if (xt->pathways)
		error_exit("Room definition after link definition");
	else if (xt->n_ants == 0)
		error_exit("Definiton of ants is missing");
	return (process_room(xt, p, i));
}

static int	process_info(t_prop *xt, char *p, int i)
{
	int		digit;
	int		ret;

	ret = 0;
	digit = 1;
	while (p[i] != ' ' && p[i] != '\n' && p[i] != '-')
	{
		digit = ft_isdigit(p[i]) && digit ? 1 : 0;
		i++;
	}
	if (p[i] == ' ')
		ret = order_check(xt, p, i);
	else if (p[i] == '-')
		ret = process_link(xt, p, i);
	else if (p[i] == '\n' && digit)
		ret = process_ant(xt, p, i);
	else
		error_exit("Wrong Input");
	return (ret);
}

void		process_input(t_prop *xt)
{
	char			*p;
	unsigned long	i;

	p = xt->input;
	i = 1;
	while (p[0] != '\0')
	{
		if (p[0] == 'L')
			error_exit("Input line starts with 'L'");
		else if (p[0] == '#')
			p += process_comment(xt, p);
		else
			p += process_info(xt, p, 0);
		if (TFLAG && i % 100 == 1)
			print_time_stats(xt, i);
		i++;
	}
	xt->input_lines = i;
}
