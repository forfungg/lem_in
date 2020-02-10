/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:13:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/10 13:47:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_elems(char **array)
{
	int cnt;

	cnt = 0;
	while (array[cnt] != 0)
		cnt++;
	return (cnt);
}

int		is_number(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		if (!ft_isdigit(str[cnt]))
			return (0);
		cnt++;
	}
	return (1);
}

int		is_link(char *line, t_prop *xt)
{
	int		cnt;
	char	**props;

	props = ft_strsplit(line, '-');
	if (count_elems(props) != 2)
		return (0);
	return (1);
}

int		is_room(char *line, t_prop *xt)
{
	char	**props;

	props = ft_strsplit(line, ' ');
	if (count_elems(props) != 3)
		return (0);
	if (is_number(props[1]) && is_number(props[2]))
		return (1);
	else
		return (0);
}

void	prepend_node(char **props, t_prop *xt)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->name = props[0];
	new->x = ft_atoi(props[1]);
	new->y = ft_atoi(props[2]);
	new->next = xt->elems;
	xt->elems = new;
}

void	save_room(char *line, t_prop *xt)
{
	char **props;

	props = ft_strsplit(line, ' ');
	if (xt->elems == 0)
	{
		ft_putstr("saving first\n");
		xt->elems = (t_node *)malloc(sizeof(t_node));
		xt->elems->name = props[0];
		xt->elems->x = ft_atoi(props[1]);
		xt->elems->y = ft_atoi(props[2]);
	}
	else
	{
		ft_putstr("saving next\n");
		prepend_node(props, xt);
	}
}

void	save_link(char *line, t_prop *xt)
{
	char **props;

	props = ft_strsplit(line, '-');
	while (xt->elems != 0)
	{

	}
}

void	read_input(t_prop *xt)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (is_room(line, xt) == 1)
			save_room(line, xt);
		else if (is_link(line, xt) == 1)
			save_link(line, xt);
		else
		{
			f_putstr("It's something else11!1\n");
			exit(0);
		}
	}
}
