/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:20:09 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 19:12:29 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	init_inf(t_env *env)
{
	env->infos.dep = 0;
	env->infos.join = 0;
}

void	play_it(t_env *env)
{
	signal(SIGINT, SIG_IGN);
	keypad(stdscr, TRUE);
	env->infos.loose = 0;
	while (((!(env->infos.echap))))
	{
		expose_term(env);
		grep_window_value(env), expose_term(env);
		init_inf(env);
		key_hook(env, wgetch(stdscr));
		game_over(env);
		win_or_not(env);
	}
	if (env->infos.echap)
		clear(), refresh(), endwin();
}

void	print_highscore(t_env *env)
{
	if (read_hscore(env) != -1)
	{
		mvprintw((WINY(env) / 4), (WINX(env) / 2) - 1, "High Score : ");
		mvprintw((WINY(env) / 4), (WINX(env) / 2) + 13, env->infos.buf);
	}
}
