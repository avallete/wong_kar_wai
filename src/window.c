/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:37:51 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 22:29:22 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	format_win(t_env *env)
{
	while ((WINY(env)) % 4)
		WINY(env)--;
	while ((WINY(env)) % 2)
		WINY(env)--;
}

void	grep_window_value(t_env *env)
{
	getmaxyx(stdscr, env->win.win_y, env->win.win_x);
	env->win.win_y--;
	env->win.win_x--;
	format_win(env);
	if (WINX(env) < 25 || WINY(env) < 14)
	{
		clear();
		ft_putsterr("\nWindow size too small\n");
		refresh();
		while (WINX(env) < 25 || WINY(env) < 14)
		{
			wgetch(stdscr);
			ft_putsterr("\nWindow size too small\n");
			getmaxyx(stdscr, env->win.win_y, env->win.win_x);
			format_win(env);
			refresh();
		}
		WINX(env)--;
		WINY(env)--;
	}
}

void	add_numbers(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			attron(COLOR_PAIR(CASEC(x, y)));
			if (CASEV(x, y) != 0)
				mvprintw(CASEY(x, y), CASEX(x, y), CASESTR(x, y));
			attroff(COLOR_PAIR(CASEC(x, y)));
			x++;
		}
		y++;
	}
}

void	expose_term(t_env *env)
{
	clear();
	init_tab_place(env);
	draw_tab(env);
	add_numbers(env);
	refresh();
}

void	new_window(void)
{
	initscr();
	noecho();
	curs_set(FALSE);
}
