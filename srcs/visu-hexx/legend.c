/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:28:17 by solopov           #+#    #+#             */
/*   Updated: 2020/02/25 12:36:26 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	display_stats(t_prop *xt)
{
	char	*rooms;
	char	*temp;

	char	*ants;

	char	*links;
	int		n_links;
	int		cnt;
	t_node	*tempnode;

	char	*paths;
	int		n_paths;
	t_paths	*temppath;

	rooms = ft_strdup("Total number of rooms: ");
	temp = ft_strjoin(rooms, ft_itoa(xt->n_rooms));
	mlx_string_put(MLX_PTR, WIN_PTR, 10, 10, 0xffffff, temp);
	free(temp);
	free(rooms);

	ants = ft_strdup("Total number of ants: ");
	temp = ft_strjoin(ants, ft_itoa(xt->f_ants));
	mlx_string_put(MLX_PTR, WIN_PTR, 10, 25, 0xffffff, temp);
	free(temp);
	free(ants);

	cnt = 0;
	n_links = 0;
	tempnode = xt->elems;
	while (tempnode)
	{
		cnt = 0;
		while (tempnode->ngb[cnt])
		{
			n_links += 1;
			cnt += 1;
		}
		tempnode = tempnode->next;
	}
	links = ft_strdup("Total number of links: ");
	temp = ft_strjoin(links, ft_itoa(n_links / 2));
	mlx_string_put(MLX_PTR, WIN_PTR, 10, 40, 0xffffff, temp);
	free(temp);
	free(links);

	n_paths = 0;
	temppath = xt->all_paths;
	while (temppath)
	{
		n_paths += 1;
		temppath = temppath->next;
	}
	paths = ft_strdup("Total number of paths: ");
	temp = ft_strjoin(paths, ft_itoa(n_paths));
	mlx_string_put(MLX_PTR, WIN_PTR, 10, 55, 0xffffff, temp);
	free(temp);
	free(paths);
}
