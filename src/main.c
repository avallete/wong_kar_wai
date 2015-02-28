/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:45:26 by avallete          #+#    #+#             */
/*   Updated: 2015/02/28 01:36:35 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	key_hook(t_env *env, int c)
{
	if (c == K_ECHAP)
		env->infos.echap = 1;
}

void	play_it(t_env *env)
{
	signal(SIGINT, SIG_IGN);
	while (1 && (!(env->infos.echap)))
	{
		expose_term(env);
		grep_window_value(env), expose_term(env);
		key_hook(env, getch());
	}
	if (env->infos.echap)
		endwin();
}

void	init_tab(t_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			CASEV(x, y) = 0;
			CASEX(x, y) = ((x + 1) * (WINX(env) / 8));
			printf("%d\n", CASEX(x, y));
			CASEY(x, y) = ((y + 1) * (WINY(env) / 8));
			CASEC(x, y) = 0;
			mvprintw(CASEY(x, y), CASEX(x, y), "0");
			refresh();
			x++;
		}
		refresh();
		sleep(1);
		y++;
	}
}

int	main(void)
{
	t_env	env;
	enum	WIN_VALUE;

	env.def = WIN_VALUE;
	env.infos.echap = 0;
	if (!((env.def) % 2))
	{
		new_window();
		clear();
		grep_window_value(&env);
		init_tab(&env);
		play_it(&env);
	}
	else
		ft_printf("Error bad WIN_VALUE, not 2 pow");
	return (0);
}
