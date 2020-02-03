/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:52:59 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/03 11:10:21 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

# define TRUE 1
# define FALSE 0

/*
** Node Struct
*/

typedef struct		s_node
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
}					t_node;

/*
** Queue struct
*/

typedef struct		s_queue
{
	t_node			*node;
	struct s_queue	*next;
}					t_que;

/*
** Node Struct
*/

typedef struct		s_readdata
{
	char			*name;
	int				x;
	int				y;
	char			*ngb;
}					t_readdata;

/*
** LEM_IN Struct
*/

typedef struct		s_prop
{
	t_node			*path;
	t_node			*start;
	t_node			*end;
}					t_prop;

/*
** Input Processing
*/

void				check_flags(int argc, char **argv, t_prop *xt);
void				read_input(t_prop *xt);

/*
** Nodes Management
*/

t_node				*create_node(char *name, int x, int y);
void				delete_node(t_node *node);
void				delete_list(t_node *lst);
t_node				*create_front(t_node *head, char *name, int x, int y);
t_node				*create_back(t_node *head, char *name, int x, int y);
t_node				*add_front(t_node *head, t_node *node);
t_node				*add_back(t_node *head, t_node *node);
t_node				*find_node(t_node *head, char *name);
int					add_neighbor(t_node *node, t_node *neighbor);
int					count_neighbors(t_node **neighbors);
t_node				*find_start(t_node *list);
t_node				*find_end(t_node *list);

/*
** Queue Management
*/

t_que				*enqueue(t_que *head, t_node *node);
t_node				*que_getnext(t_que **queue);

/*
** Breath First Search for paths
*/

void				bfs(t_node *start, t_node *end);

/*
**	Print Functions NEEDS TO CHANGE TO FT_PRINTF!!!
*/

void				print_list(t_node *head);
void				print_queue(t_que *queue);

#endif
