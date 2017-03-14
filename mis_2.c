/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:18:05 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/14 17:21:27 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	w_error(char *file)
{
	char *p;

	p = ft_strdup("\0");
	p = ft_strjoinf(p, "minishell: ");
	p = ft_strjoinf(p, "command not found: ");
	p = ft_strjoinf(p, file);
	ft_putendl_fd(p, 2);
	free(p);
}
