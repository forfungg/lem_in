/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:52:59 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/10 13:47:10 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

/*
** Node Struct
*/

typedef struct	s_node
{
	char			*name;
	struct s_node	**ngb;
	struct s_node	*next;
	int				x;
	int				y;
	int				start;
	int				end;
	int				empty;
	int				visited;
	int				lvl;
}				t_node;

/*
** Node Struct
*/

typedef struct	s_readdata
{
	char		*name;
	int			x;
	int			y;
	char		*ngb;
}				t_readdata;

/*
** LEM_IN Struct
*/

typedef struct	s_prop
{
	t_node		*elems;
	t_node		*path;
	int			r_start;
	int			r_end;
}				t_prop;

/*
** Input Processing
*/

void	check_flags(int argc, char **argv, t_prop *xt);
void	read_input(t_prop *xt);

#endif