/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:02:41 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/01 14:38:33 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int		two_or_four(void)
{
	if (rand() % 9 == 0)
		return (4);
	else
		return (2);
}

int		is_fill(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (CASEV(x, y) == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	give_random(t_env *env, int j, int i)
{
	CASEV(j, i) = two_or_four();
	env->infos.dep = 0;
	env->infos.join = 0;
	return ;
}

void	add_nb(t_env *env)
{
	int	i;
	int	j;
	int	chance;

	srand(time(NULL));
	chance = 4;
	if ((is_fill(env)))
		return ;
	while (1)
	{
		j = 0;
		while (j < 4)
		{
			i = 0;
			while (i < 4)
			{
				if (CASEV(j, i) == 0 && rand() % chance == 0)
					return (give_random(env, j, i));
				i++;
			}
			j++;
		}
		chance--;
	}
}
