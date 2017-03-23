/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:03:36 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/23 17:03:38 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoinf(char *one, char *two)
{
	char *t;

	t = one;
	one = ft_strjoin(one, two);
	if (t)
		free(t);
	return (one);
}

void	*w_malloc(size_t size)
{
	void	*m;

	if ((m = malloc(size)) == 0)
	{
		exit(1);
	}
	return (m);
}

void	hash_free(t_hash **table, int size)
{
	int		x;
	t_hash	*tmp;

	x = 0;
	if (table == 0)
		return ;
	while (x < size)
	{
		while (table[x])
		{
			if (table[x]->data)
				free(table[x]->data);
			if (table[x]->index)
				free(table[x]->index);
			tmp = table[x];
			table[x] = table[x]->next;
			free(tmp);
		}
		free(table[x]);
		table[x] = 0;
		x++;
	}
	free(table);
}

void	w_exit(int no, t_env env)
{
	hash_free(env.table, env.table_size);
	exit(no);
}
