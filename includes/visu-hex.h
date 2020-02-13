/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu-hex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:42:47 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/13 16:49:09 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
#define VISUAL_H

#define IMGS			xt->imgs
# define IMG_PTR		xt->img_ptr
# define MLX_PTR		xt->mlx_ptr
# define IMG_DAT		xt->img_data
# define WIN_PTR		xt->win_ptr
# define TRUE 1
# define FALSE 0
# define W_W 1920
# define W_H 1080
# define W_NAME "VISU-HEXX"

# include <mlx.h>
# include "../libs/libft/includes/libft.h"

typedef struct		s_img
{
	void			*bg;
	int				*bgdat;
	
	void			*frame;
	int				*framedat;
	
	void			*room;
	int				*roomdat;

	void			*ant;
	int				*antdat;

	void			*name;
	int				*namedat;
}					t_img;

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	int				start;
	int				end;
	struct s_node	**ngb;
	struct s_node	*next;
	int				empty;
	int				visited;

}					t_node;

typedef struct	s_prop
{
	int				f_ants;
	int				f_start;
	int				f_end;
	int				n_ants;
	int				n_start;
	int				n_end;

	t_node			*elems;
	t_img			*imgs;

	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_data;
}				t_prop;

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

void				error_exit(char *msg);

/*
** Input functions
*/

void				read_input(t_prop *xt);

/*
** Images Create
*/

void				fill_image(int *img_data, int img_w, int img_h, int color);
void				create_background(t_prop *xt);

/*
** Images Draw
*/

void				draw_farm(t_prop *xt);

/*
** Controls
*/

int					key_hook_press(int keycode, t_prop *xt);

#endif