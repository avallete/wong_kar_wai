/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:12:02 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 18:18:49 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	key_hook(t_env *env, int c)
{
	env->infos.dep = 0;
	env->infos.join = 0;
	if (c == K_ECHAP)
		env->infos.echap = 1;
	if (c == 410)
		grep_window_value(env);
	if ((c == KEY_UP || c == KEY_DOWN) && (!(env->infos.loose)))
	{
		c == KEY_UP ? mv_up(env) : mv_down(env);
		env->infos.dep || env->infos.join ? add_nb(env) : 0;
		modify_tab(env);
	}
	if ((c == KEY_LEFT || c == KEY_RIGHT) && (!(env->infos.loose)))
	{
		c == KEY_LEFT ? mv_left(env) : mv_right(env);
		env->infos.dep == 1 || env->infos.join ? add_nb(env) : 0;
		modify_tab(env);
	}
	ft_usleep(29000000);
}
