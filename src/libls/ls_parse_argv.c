/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 02:14:49 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/12 15:56:00 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include <unistd.h>

int	ls_parse_argv(int ac, char*const av[], t_ls *ls)
{
	int		opt;
	size_t	i;

	while ((opt = ft_getopt(ac, av, FLAGS)) != -1)
	{
		if (opt == '?')
		{
			ft_printf(ILLEGAL_OPT, g_optopt);
			ft_printf(USAGE, FLAGS);
			return (ERR);
		}
		else
			ls->flags[opt] = 1;
	}
	if (!(ls->fnames = ft_memalloc((ac - g_optind + 1) * sizeof(char*))))
	{
		ft_printf(ALC_ERR);
		return (ERR);
	}
	i = -1;
	while (g_optind < ac)
		ls->fnames[++i] = av[g_optind++];
	return (OK);
}
