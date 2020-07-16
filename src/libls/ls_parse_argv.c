/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 02:14:49 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 20:35:47 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include <unistd.h>

static int	ls_add(char *name, t_ls *ls)
{
	int			rc;
	t_entity	e;

	if ((rc = ls_fillentity(&e, name, NULL)) == ERR)
		return (ERR);
	else if (rc == END)
		ft_printf(NOT_FOUND, name);
	else if (ls_elstadd(ls->elst, &e) == ERR)
		return (ERR);
	return (OK);
}

int			ls_parse_argv(int ac, char*const av[], t_ls *ls)
{
	int			opt;

	while ((opt = ft_getopt(ac, av, FLAGS)) != -1)
	{
		if (opt == '?')
		{
			ft_printf(ILLEGAL_OPT, g_optopt);
			ft_printf(USAGE, FLAGS);
			return (ERR);
		}
		ls->flags[opt] = 1;
	}
	if (g_optind == ac && ls_add(".", ls) == ERR)
		return (ERR);
	while (g_optind < ac)
		if (ls_add(av[g_optind++], ls) == ERR)
			return (ERR);
	return (OK);
}
