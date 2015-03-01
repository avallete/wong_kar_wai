/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 21:19:11 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 20:47:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	init_tab_place(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			CASEX(x, y) = ((WINX(env) / 8) * (x + 1)) \
			+ ((WINX(env) / 8) * x + 1);
			CASEY(x, y) = ((WINY(env) / 8) * (y + 1)) \
			+ ((WINY(env) / 8) * y + 1);
			x++;
		}
		y++;
	}
}

void	init_case(t_env *env, int x, int y)
{
	free(CASESTR(x, y));
	if (CASEV(x, y) <= 4)
		CASEC(x, y) = 0;
	if (CASEV(x, y) > 4)
		CASEC(x, y) = 1;
	if (CASEV(x, y) >= 32)
		CASEC(x, y) = 2;
	if (CASEV(x, y) >= 128)
		CASEC(x, y) = 3;
	if (CASEV(x, y) >= 512)
		CASEC(x, y) = 4;
	if (CASEV(x, y) >= 1024)
		CASEC(x, y) = 5;
	CASESTR(x, y) = ft_itoa(CASEV(x, y));
}

void	modify_tab(t_env *env)
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
			init_case(env, x, y);
			x++;
		}
		y++;
	}
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
			CASEC(x, y) = 0;
			CASESTR(x, y) = ft_itoa(0);
			x++;
		}
		y++;
	}
	init_tab_place(env);
}
