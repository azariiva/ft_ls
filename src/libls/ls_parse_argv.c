/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 02:14:49 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/12 02:39:22 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int	ls_parse_argv(int ac, char*const av[], t_ls *ls)
{
	int	opt;

	while ((opt = ft_getopt(ac, av, FLAGS)))
	{
		if (opt == '?')
			return (ERR);
		else
			ls->flags[opt] = 1;
	}
}
