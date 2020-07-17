/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 02:14:49 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 17:49:19 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include <unistd.h>

static int	ls_add(char *name, t_ls *ls, int *ds)
{
	int			rc;
	t_entity	e;

	if ((rc = ls_fillentity(&e, name, NULL, ls->flags)) == ERR)
		return (ERR);
	else if (rc == END)
		return (END);
	else if (ls_elstadd(ls->elst, &e) == ERR)
		return (ERR);
	if (e.elst)
		(*ds)++;
	else
		return (OK);
	return (END);
}

int			ls_parse_argv(int ac, char*const av[], t_ls *ls, int *ds)
{
	int			opt;
	int			f;

	f = END;
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
	if (g_optind == ac && ls_add(".", ls, ds) == ERR)
		return (ERR);
	while (g_optind < ac)
	{
		if ((opt = ls_add(av[g_optind++], ls, ds)) == ERR)
			return (ERR);
		else if (opt == OK)
			f = OK;
	}
	return (f);
}
