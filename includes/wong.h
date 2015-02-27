/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:04:06 by avallete          #+#    #+#             */
/*   Updated: 2015/02/28 00:47:27 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_H
# define WONG_H
# include <libft.h>
# include <get_next_line.h>
# include <ft_printf.h>
# include <time.h>
# include <signal.h>
# include <curses.h>
# define WINX(x) (x->win.win_x)
# define WINY(x) (x->win.win_y)
# define K_ECHAP 27

typedef enum		e_const
{
	WIN_VALUE = 2048
}					t_const;

typedef	struct		s_win
{
	unsigned int	win_x;
	unsigned int 	win_y;
}					t_win;

typedef	struct		s_inf
{
	int				echap;
	int				redraw;
}					t_inf;

typedef	struct		s_env
{
	t_const			def;
	t_win			win;
	t_inf			infos;
}					t_env;

/*
** WINDOW
*/
void	grep_window_value(t_env *env);
void	new_window(void);
void	expose_term(t_env *env);


/*
** DRAW_TAB
*/
void	draw_tab(t_env *env);
void	draw_cross(unsigned int x, unsigned int y,\
		unsigned maxx, unsigned maxy);

#endif
