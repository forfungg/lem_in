/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_receive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:47:05 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/21 18:51:16 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

int		split_line(char *line)
{
	int cnt;
	int ret;

	cnt = 0;
	ret = 0;
	while (line[cnt] != '\0')
	{
		if (line[cnt] == 'L')
			ret += 1;
		cnt += 1;
	}
	return (ret);
}

char	*receive_name(char *line, int cnt)
{
	char	**array;
	char	**section;
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	array = ft_strsplit(line, ' ');
	tmp = ft_strjoin(ft_strdup("L"), ft_itoa(cnt));
	while (!strstr(array[i], tmp))
		i++;
	section = ft_strsplit(array[i], '-');
	ret = section[1];
	free(tmp);
	return (ret);
}

void	new_node_to_path(t_prop *xt, t_node *node, char *name)
{
	t_node *tmp;

	tmp = node;
	while (tmp->path)
		tmp = tmp->path;
	tmp->path = find_node(xt->elems, name);
}

t_paths	*new_path_to_list(t_prop *xt, t_lines *line, int cnt)
{
	t_paths	*new;
	char	*name;

	name = receive_name(line->str, cnt);
	new = (t_paths *)malloc(sizeof(t_paths));
	new->node = find_node(xt->elems, name);
	line = line->next;
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

void	print_linesa(t_lines *lines)
{
	while (lines)
	{
		printf("%s\n", lines->str);
		lines = lines->next;
	}
}

void	print_pathss(t_paths *path)
{
	t_node *tmp;

	while (path)
	{
		tmp = path->node;
		while (tmp)
		{
			ft_printf("%s - ", tmp->name);
			tmp = tmp->path;
		}
		ft_printf("\n\n");
		path = path->next;
	}
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
	print_pathss(xt->all_paths);
}
