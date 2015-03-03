/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:50:55 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/01 18:22:14 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int		check_ln(t_env *env)
{
	int	y;
	int	x;

	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 4)
		{
			if (CASEV(x, y) == 0 || CASEV(x + 1, y) == CASEV(x, y))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int		check_col(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 4)
		{
			if (CASEV(x, y) == CASEV(x, y + 1))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	game_over(t_env *env)
{
	if ((check_ln(env) == 0 && check_col(env) == 0) && is_fill(env))
	{
		clear();
		mvprintw(WINY(env) / 2, WINX(env) / 2, "YOU LOOSE !!!");
		refresh(), ft_sleep(5);
		modify_tab(env);
		expose_term(env);
		ft_sleep(20);
		env->infos.loose = 1;
		ft_menu(env);
	}
}

int		win_or_not(t_env *env)
{
	int		i;
	int		j;
	t_const	win_val;

	win_val = WIN_VALUE;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (CASEV(i, j) == win_val && env->infos.win == 0)
			{
				clear(), mvprintw(WINY(env) / 2, WINX(env) / 2, "YOU WIN !!!");
				refresh(), ft_sleep(5);
				env->infos.win = 1;
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
