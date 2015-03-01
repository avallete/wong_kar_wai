/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:33:34 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 18:12:14 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	ft_usleep(long unsigned int time)
{
	long unsigned int i;

	i = 0;
	while (i < time)
		i++;
}

void	ft_sleep(long unsigned int time)
{
	long unsigned int i;

	i = 0;
	while (i < (time * 150000000))
		i++;
}
