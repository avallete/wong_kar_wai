/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updown_leftright.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:27:14 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/28 19:18:09 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

void	mv_left(t_env *env)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		tab_mvline(env, j, 0, LEFT);
		j++;
	}
}

void	mv_right(t_env *env)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		tab_mvline(env, j, 3, RIGHT);
		j++;
	}
}

void	mv_up(t_env *env)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tab_mvcol(env, 0, i, UP);
		i++;
	}
}

void	mv_down(t_env *env)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tab_mvcol(env, 3, i, DOWN);
		i++;
	}
}
