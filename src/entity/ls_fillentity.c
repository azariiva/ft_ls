/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fillentity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:55:59 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 17:52:56 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_entity.h"

int	ls_fillentity(t_entity *e, const char *name, const char *dpath,
const char *flags)
{
	ft_bzero(e, sizeof(t_entity));
	if (!e || !name)
		return (ERR);
	if (!flags['a'] && (name[0] == '.' && dpath))
		return (END);
	if (!(e->name = ft_strdup(name)))
		return (ERR);
	if (!(e->path = ls_addprefix(dpath, name)))
	{
		ft_strdel(&(e->name));
		return (ERR);
	}
	if (lstat(e->path, &(e->stat)) == -1)
	{
		ft_printf(NOT_FOUND, e->path);
		ft_strdel(&(e->name));
		ft_strdel(&(e->path));
		return (END);
	}
	if (S_ISDIR(e->stat.st_mode) && !(e->elst = ls_elstnew()))
	{
		ft_strdel(&(e->name));
		return (ERR);
	}
	return (OK);
}
