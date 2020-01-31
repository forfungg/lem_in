/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:13:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/31 16:44:16 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_elems(char **array)
{
	int cnt;

	cnt = 0;
	while (array[cnt] != 0)
		cnt++;
	printf("COUNT ELEMS COUNT:%d\n", cnt);
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

// void	init_node(t_prop *xt)
// {
	
// }

int		is_link(char *line, t_prop *xt)
{
	int		cnt;
	char	**props;

	props = ft_strsplit(line, '-');
	if (count_elems(props) != 2)
		return (0);
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

void	save_room(char *line, t_prop *xt)
{
	
}

void	read_input(t_prop *xt)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (is_room(line, xt) == 1)
		{
			ft_putstr("ROOM!\n");
		}
		else
			ft_putstr("NOT ROOM!\n");
		// else if (is_link(line, xt) == 1)
		// 	save link(line, xt);
		// else
		// free(line);
	}
}
