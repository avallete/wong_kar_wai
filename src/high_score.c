/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:01:30 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/01 19:09:37 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int		read_hscore(t_env *env)
{
	int		fd;
	int		ret;

	ft_bzero(env->infos.buf, 64);
	if ((fd = open("score.txt", O_RDONLY)) == -1)
		return (-1);
	if ((ret = read(fd, env->infos.buf, 63)) == -1)
		return (-1);
	env->infos.buf[ret] = '\0';
	close(fd);
	return (1);
}

int		replace_hscore(int score, t_env *env)
{
	int		fd;
	int		old_score;
	char	*score_to_write;

	read_hscore(env);
	old_score = ft_atoi(env->infos.buf);
	if (score >= old_score)
	{
		if ((fd = open("score.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
			return (-1);
		score_to_write = ft_itoa(score);
		ft_putstr_fd(score_to_write, fd);
		free(score_to_write);
		close(fd);
	}
	return (1);
}

int		count_score(t_env *env)
{
	int	x;
	int	y;
	int	score;

	y = 0;
	score = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			score += CASEV(x, y);
			x++;
		}
		y++;
	}
	return (score);
}

void	high_score(t_env *env)
{
	int	score;

	score = count_score(env);
	replace_hscore(score, env);
}
