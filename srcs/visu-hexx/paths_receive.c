/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_receive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:47:05 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/02 11:19:15 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void	new_node_to_path(t_prop *xt, t_node *node, char *name)
{
	t_node *tmp;

	tmp = node;
	while (tmp->path)
		tmp = tmp->path;
	tmp->path = find_node(xt->elems, name);
	free(name);
}

t_paths	*new_path_to_list(t_prop *xt, t_lines *line, int cnt)
{
	t_paths	*new;
	char	*name;

	name = receive_name(line->str, cnt);
	new = (t_paths *)malloc(sizeof(t_paths));
	if (!(new->node = find_node(xt->elems, name)))
		error_exit("Node not found on path!");
	line = line->next;
	free(name);
	while (line)
	{
		name = receive_name(line->str, cnt);
		new_node_to_path(xt, new->node, name);
		if (ft_strequ(name, find_end(xt->elems)->name))
			break ;
		line = line->next;
	}
	new->next = 0;
	return (new);
}

void	append_path_to_list(t_prop *xt, t_lines *line, int cnt)
{
	t_paths *temp;

	temp = xt->all_paths;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = new_path_to_list(xt, line, cnt);
}

void	create_path_list(t_prop *xt, t_lines *lines)
{
	int		cnt;
	int		len;
	t_paths	*ret;

	cnt = 1;
	len = split_line(lines->str);
	xt->all_paths = new_path_to_list(xt, lines, cnt);
	while (++cnt <= len)
		append_path_to_list(xt, lines, cnt);
}
