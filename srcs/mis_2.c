/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:18:05 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/16 18:48:29 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	w_error(char *file, char *fcmd)
{
	char *p;

	if (fcmd)
		free(fcmd);
	p = ft_strdup("\0");
	p = ft_strjoinf(p, "minishell: ");
	p = ft_strjoinf(p, "command not found: ");
	p = ft_strjoinf(p, file);
	free(file);
	ft_putendl_fd(p, 2);
	free(p);
}
void	trim_split(char **av)
{
	int		x;
	
	x = 0;
	while (av != 0)
	{
		x++;
	}	
}
