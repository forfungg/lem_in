/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:52:59 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/26 19:01:12 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libs/libft/includes/libft.h"
# include <errno.h>

# define LEM_BUF 50000000
# define NGB_BUF 1000
# define TRUE 1
# define FALSE 0
# define NAME xt->elems->name
# define CAPACITY 1
# define FF_ALL 1
# define DEBUG xt->flags.debug
# define FILE xt->flags.fd
# define START xt->elems
# define END xt->end_node
# define ANTS xt->f_ants
# define I xt->in_point

/*
** Node Struct
*/

typedef struct		s_node
{
	char			*name;
	struct s_node	**ngb;
	struct s_node	*next;
	int				*cap;
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
	int				dbg_a;
	int				im_min;
	struct s_paths	*next;
}					t_paths;

/*
** Flags Struct
*/

typedef struct		s_lem_flags
{
	int				fd;
	int				debug;
}					t_lflg;

/*
** LEM_IN Struct
*/

typedef struct		s_prop
{
	t_node		*elems;
	t_node		*end_node;
	t_paths		*all_paths;
	char		*input;
	char		*pathways;
	size_t		in_point;
	t_lflg		flags;
	int			r_start;
	int			r_end;
	int			f_start;
	int			f_end;
	int			f_ants;
	int			n_start;
	int			n_end;
	int			n_ants;
	int			ant_cnt;
	int			pot_flow;
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
void				attach_room(t_prop *xt, char *name, int x, int y);
void				save_room(char *line, t_prop *xt);
void				save_link(char *line, t_prop *xt);
void				save_commands(char *str, t_prop *xt);
void				save_ants(char *str, t_prop *xt);
int					get_coord(char *str);
void				is_valid_room(t_prop *xt, char *name, int x, int y);
void				load_input(t_prop *xt, int fd);
char				*lem_getnextline(t_prop *xt);
void				process_input(t_prop *xt);

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
void				reset_visits(t_node *list);
void				capacitize_ngbs(t_node *list);
t_node				*add_default_room(t_node *head, t_node *node);

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

t_que				*bfs(t_node *start, t_node *end);
t_paths				*append_path(t_paths *head, t_que *path);
t_que				*pop_path(t_paths **all_paths);
void				delete_paths(t_paths *all_paths);

/*
** Ford-Fulkerson max flow algorithm
*/

int					ford_fulkerson(t_prop *xt);
void				get_flow_paths(t_node *start, t_node *end,\
						t_paths **all_paths);
int					len_solution(t_paths *paths, int ants);
void				new_solution(t_paths **storage, t_paths **new);
int					first_square(t_paths *paths, int ants);

/*
**	Print Functions NEEDS TO CHANGE TO FT_PRINTF!!!
*/

void				print_list(t_node *head);
void				print_edges(t_node *head);
void				print_colony(t_prop *xt);
void				print_paths(t_paths *paths);
void				print_queue(t_que *queue);
void				print_graph(t_node *graph);
void				print_debug(t_prop *xt);

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
t_paths				*shortest_path(t_paths *paths);

/*
** Bonus Stuff
*/

void				open_graph_file(t_prop *xt, char *filename);
void				close_graph_file(t_prop *xt);
void				show_usage(void);
void				show_product_info(void);
#endif
