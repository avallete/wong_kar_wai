/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:37:51 by avallete          #+#    #+#             */
/*   Updated: 2015/02/28 00:56:51 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	grep_window_value(t_env *env)
{
	getmaxyx(stdscr, env->win.win_y, env->win.win_x);
	env->win.win_y--;
	env->win.win_x--;
	if (WINX(env) < 12 || WINY(env) < 12)
	{
		clear();
		refresh();
		endwin();
		ft_putsterr("\nWindow size too small\n");
		env->infos.echap = 1;
	}
}

void	expose_term(t_env *env)
{
	clear();
	draw_tab(env);
	refresh();
}

void	new_window(void)
{
	initscr();
	noecho();
	curs_set(FALSE);
}
