/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_code.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:08:53 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/27 12:43:02 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_CODE
# define FT_TIME_CODE

# include <time.h>
# include <stdlib.h>
# include "../libs/libft/includes/libft.h"

typedef struct	s_time_markdown
{
	char		*name;
	clock_t		timestamp;
}				t_tmd;


typedef struct	s_timestamps
{
	clock_t		start;
	t_tmd		**marks;
	clock_t		end;
}				t_tstamp;


void			ft_start_timer(t_tstamp *stopwatch);
void			ft_stop_timer(t_tstamp *stopwatch);
double			ft_time_lapsed(clock_t start, clock_t end);
void			ft_markdown(t_tstamp *stopwatch, char *name);
t_tstamp		*ft_stopwatch_init(void);
void			ft_clear_marks(t_tmd **marks);
void			ft_stopwatch_del(t_tstamp *stopwatch);

#endif