/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:03:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/12 15:31:31 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_n_strings(t_paths *paths)
{
	int		max;
	t_paths	*head;

	max = get_t_len(paths);
	head = paths;
	while (paths->next)
	{
		if (get_t_len(paths->next) > max)
		{
			head = paths->next;
			max = get_t_len(head);
		}
		paths = paths->next;
	}
	return (max + 1);
}

void	str_append(char *str, int nb, char *name)
{
	
}

void	move_ants(t_prop *xt, t_paths *paths)
{
	char	**out;
	int		cnt;
	int		len;
	t_que	*tmp;
	t_paths	*head;

	print_paths2(paths);
	if (!paths)
		return ;
	len = get_n_strings(paths);
	out = malloc(len * sizeof(char *));
	head = paths;
	if (xt->ant_cnt <= xt->f_ants)
	{
		if (paths->ants)
		{
			cnt = 0;
			tmp = paths->path->next;
			if (tmp)
			{
				str_append(out[cnt], xt->ant_cnt, tmp->node->name);
				cnt++;
				tmp = tmp->next;
			}
			xt->ant_cnt += 1;
			paths->ants--;
		}
		paths = paths->next;
		if (!paths)
			paths = head;
	}
}
