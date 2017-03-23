/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:08:16 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/23 16:09:06 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	noflag(int argc, char **argv)
{
	argc++;
	argv += 1;
}

int		main(int argc, char **argv, char **en)
{
	t_env env;

	env.env = en;
	noflag(argc, argv);
	env.table = create_hashtable(en, &env.table_size);
	prompt(env);
	hash_free(env.table, env.table_size);
	return (0);
}
