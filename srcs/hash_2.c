/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:06:49 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/23 16:06:50 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		total_element(t_env env)
{
	int		x;
	int		total;
	t_hash	*save;

	total = 0;
	x = 0;
	while (x < env.table_size)
	{
		save = env.table[x];
		while (env.table[x])
		{
			total++;
			env.table[x] = env.table[x]->next;
		}
		env.table[x] = save;
		x++;
	}
	return (total);
}

char	**tabletostr(t_env env)
{
	int		element;
	char	**envstr;
	int		x;
	t_hash	*save;
	int		xstr;

	xstr = 0;
	x = 0;
	element = total_element(env);
	envstr = (char **)malloc(sizeof(char *) * (element + 1));
	envstr[element] = 0;
	while (x < env.table_size)
	{
		save = env.table[x];
		while (env.table[x])
		{
			envstr[xstr] = ft_strjoin(env.table[x]->index, "=");
			envstr[xstr] = ft_strjoinf(envstr[xstr], env.table[x]->data);
			xstr++;
			env.table[x] = env.table[x]->next;
		}
		env.table[x] = save;
		x++;
	}
	return (envstr);
}
