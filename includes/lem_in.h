/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:52:59 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/17 16:37:28 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libs/libft/includes/libft.h"
# include <errno.h>

# define TRUE 1
# define FALSE 0
# define NAME xt->elems->name

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
	int				shift;
}					t_node;

/*
** Queue struct
*/

typedef struct		s_queue
{
	t_node			*node;
	int				curr_ant;
	int				shift;
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
** BFS pathing
*/

typedef struct		s_paths
{
	t_que			*path;
	int				ants;
	int				im_min;
	struct s_paths	*next;
}					t_paths;

/*
** LEM_IN Struct
*/

typedef struct		s_prop
{
	t_node		*elems;
	t_paths		*all_paths;
	int			r_start;
	int			r_end;
	int			f_start;
	int			f_end;
	int			f_ants;

	int			n_start;
	int			n_end;
	int			n_ants;
	int			ant_cnt;
}					t_prop;

/*
** Input Processing
*/

void				check_flags(int argc, char **argv, t_prop *xt);
void				read_input(t_prop *xt);
void				check_input(t_prop *xt);
void				clear_props(char **props);
int					count_elems(char **array);
int					is_number(char *str);
int					is_ants(char *str, t_prop *xt);
int					is_link(char *line, t_prop *xt);
int					is_room(char *line, t_prop *xt);
void				new_node(char **props, t_prop *xt);
void				prepend_node(char **props, t_prop *xt);
void				save_room(char *line, t_prop *xt);
void				save_link(char *line, t_prop *xt);
void				save_commands(char *str, t_prop *xt);
void				save_ants(char *str, t_prop *xt);
int					get_coord(char *str);

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
t_que				*que_copy(t_que *node);
void				que_delete(t_que *head);
t_node				*que_getlast(t_que *head);
t_paths				*path_parsing(t_paths *all_paths);
/*
** Breath First Search for paths
*/

void				bfs(t_node *start, t_node *end, t_paths **all_paths,\
						int ants);
t_paths				*append_path(t_paths *head, t_que *path);
t_que				*pop_path(t_paths **all_paths);
void				delete_paths(t_paths *all_paths);

/*
**	Print Functions NEEDS TO CHANGE TO FT_PRINTF!!!
*/

void				print_list(t_node *head);
void				print_edges(t_node *head);
void				print_colony(t_prop *xt);
void				print_paths(t_paths *paths);
void				print_queue(t_que *queue);

/*
**	Program functionality support tools
*/

void				error_exit(char *msg);

/*
**	Moving ants
*/

void				assign_ants(t_prop *xt);
void				move_ants(t_prop *xt, t_paths *paths);
int					get_t_len(t_paths *paths);
int					get_n_strings(t_paths *paths);
void				ft_safestrjoin(char **str, char *add, int pos);
char				*str_append(char *str, int nb, char *name);
void				print_output(char **out);
#endif
