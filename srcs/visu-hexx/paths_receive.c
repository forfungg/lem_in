/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_receive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:47:05 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/29 22:42:34 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

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

char	*get_ant_str(int cnt)
{
	char *out;
	char *l;
	char *num;

	l = ft_strdup("L");
	num = ft_itoa(cnt);
	out = ft_strjoin(l, num);
	free(l);
	free(num);
	return (out);
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
	tmp = get_ant_str(cnt);
	while (array[i] && !strstr(array[i], tmp))
		i++;
	section = ft_strsplit(array[i], '-');
	ret = ft_strdup(section[1]);
	clear_split(array);
	clear_split(section);
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
	free(name);
	while (line)
	{
		name = receive_name(line->str, cnt);
		new_node_to_path(xt, new->node, name);
		if (ft_strequ(name, find_end(xt->elems)->name))
			break ;
		free(name);
		line = line->next;
	}
	free(name);
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
