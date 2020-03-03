/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_hex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:42:47 by asolopov          #+#    #+#             */
/*   Updated: 2020/03/03 14:09:17 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_HEX_H
# define VISU_HEX_H

# define IMGS xt->imgs
# define IMG_PTR xt->img_ptr
# define MLX_PTR xt->mlx_ptr
# define IMG_DAT xt->img_data
# define WIN_PTR xt->win_ptr
# define TRUE 1
# define FALSE 0
# define CAPACITY 1
# define FF_ALL 1
# define W_W 1920
# define W_H 1080
# define FRAMES 120
# define W_NAME "VISU-HEXX"
# define PRT ft_printf

# include <mlx.h>
# include <errno.h>
# include <math.h>
# include "../libs/libft/includes/libft.h"

typedef struct		s_img
{
	void			*bg;
	int				*bgdat;

	void			*sand;
	int				*sanddat;

	void			*uniroom;
	int				roomsize;
	int				*udat;

	void			*line;
	int				*linedat;

	void			*path;
	int				*pathdat;

	void			*ant;
	int				*adat;

	int				disp_names;
	int				disp_all;
	int				disp_path;
	int				disp_black;
	int				pause;
}					t_img;

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	int				nx;
	int				ny;
	int				start;
	int				end;
	struct s_node	**ngb;
	struct s_node	*next;
	struct s_node	*path;
	int				*cap;
	int				empty;
	int				visited;
}					t_node;

typedef struct		s_paths
{
	t_node			*node;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_lines
{
	char			*str;
	struct s_lines	*next;
}					t_lines;

typedef struct		s_ant
{
	int				cnt;
	double			x;
	double			y;
	int				dx;
	int				dy;
	double			stpx;
	double			stpy;
	t_node			*curpos;
	t_node			*nextpos;
	int				error;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_prop
{
	int				f_ants;
	int				f_start;
	int				f_end;
	int				n_ants;
	int				n_start;
	int				n_end;
	int				n_rooms;
	int				n_links;
	t_paths			*all_paths;
	t_lines			*lines;
	t_lines			*cpy;
	t_ant			*ants;
	char			**moves;

	t_node			*elems;
	t_img			*imgs;

	void			*mlx_ptr;
	void			*win_ptr;

	int				max_y;
	int				min_y;
	int				max_x;
	int				min_x;
	int				x_coef;
	int				y_coef;

	int				dx;
	int				dy;
	int				stpx;
	int				stpy;
	int				color;
	int				fd;
	double			spdmod;
}					t_prop;

typedef struct		s_pcur
{
	int				x;
	int				y;
}					t_pcur;

/*
** Reading Flags
*/

void				open_file(t_prop *xt, char *argv);
void				close_file(t_prop *xt);
void				show_product_info(void);
void				show_usage(void);
void				print_logo(void);

/*
** Input Processing
*/

void				read_input(t_prop *xt);
int					get_coord(char *str);
void				new_node(char **props, t_prop *xt);
void				prepend_node(char **props, t_prop *xt);
int					is_room(char *line);
int					is_link(char *line);
int					is_ants(char *str);
int					is_number(char *str);
int					count_elems(char **array);
void				check_input(t_prop *xt);
void				save_ants(char *str, t_prop *xt);
void				save_commands(char *str, t_prop *xt);
void				save_link(char *line, t_prop *xt);
void				save_room(char *line, t_prop *xt);
void				save_line(t_prop *xt, char *line);

/*
** Node	Management
*/

t_node				*create_node(char *name, int x, int y);
int					create_neighbor(t_node *node, t_node *neighbor);
int					copy_pasta(t_node **src, t_node **dest);
int					append_neighbor(t_node *node, t_node *neighbor);
int					already_exists(t_node *node, char *new);
int					add_neighbor(t_prop *xt, t_node *node, t_node *neighbor);
int					count_neighbors(t_node **neighbors);
void				capacitize_ngbs(t_node *list);
t_node				*find_end(t_node *list);
t_node				*find_start(t_node *list);
t_node				*find_node(t_node *head, char *name);

/*
** Path Management
*/

void				new_node_to_path(t_prop *xt, t_node *node, char *name);
t_paths				*new_path_to_list(t_prop *xt, t_lines *line, int cnt);
void				append_path_to_list(t_prop *xt, t_lines *line, int cnt);
void				create_path_list(t_prop *xt, t_lines *lines);
int					split_line(char *line);
char				*get_ant_str(int cnt);
char				*receive_name(char *line, int cnt);

/*
** Ant List Management
*/

void				create_ant_list(t_prop *xt);

/*
** Create Images
*/

void				create_ant(t_prop *xt);
void				create_background(t_prop *xt);
void				create_sand(t_prop *xt);
void				create_path(t_prop *xt);
void				create_lines(t_prop *xt);
double				get_size(int x, int y, int nb);
void				create_uniroom(t_prop *xt);
void				get_minmax_xy(t_prop *xt);
void				fill_frame(int *img_data, int img_w, int img_h, int color);
void				fill_rctngl_pattern(int *img_data, int img_w, int img_h);
void				fill_rctngl(int *img_data, int img_w, int img_h, int color);
int					get_cor_x(int coord, t_prop *xt);
int					get_cor_y(int coord, t_prop *xt);
int					get_rand(int one, int two);
void				cnct_nodes(int *img, t_prop *xt, t_node *beg, t_node *end);

/*
** Image Drawing
*/

void				draw_farm(t_prop *xt);
void				redraw(t_prop *xt);
void				display_all(t_prop *xt);
void				display_paths(t_prop *xt);
void				display_black(t_prop *xt);
void				display_background(t_prop *xt);
void				display_lines(t_prop *xt);
void				display_path(t_prop *xt);
void				display_ants(t_prop *xt);
void				display_uniroom(t_prop *xt);
void				display_stats(t_prop *xt);
void				display_controls_add(t_prop *xt);

/*
** Moving ants
*/

void				move_ants(t_prop *xt);
void				draw_ant_algo(t_prop *xt, t_ant *ant);
void				recalc_ant_movement(t_prop *xt);
void				update_ant_positions(t_prop *xt, char *line);


/*
** Memory & Program Exit
*/

void				delete_node(t_node *node);
void				delete_list(t_node *lst);
void				delete_ants(t_ant *ants);
void				delete_paths(t_paths *paths);
void				delete_lines(t_lines *lines);
void				clear_memory(t_prop *xt);
void				error_exit(char *msg);
void				clear_split(char **props);

/*
** Controls
*/

int					key_hook_press(int keycode, t_prop *xt);

#endif
