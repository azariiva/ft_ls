/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fillentity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:55:59 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 20:26:59 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_entity.h"

int	ls_fillentity(t_entity *e, const char *name, const char *dpath)
{
	ft_bzero(e, sizeof(t_entity));
	if (!e || !name)
		return (ERR);
	if (!(e->name = ft_strdup(name)))
		return (ERR);
	if (!(e->path = ls_addprefix(dpath, name)))
	{
		ft_strdel(&(e->name));
		return (ERR);
	}
	if (lstat(e->path, &(e->stat)) == -1)
	{
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
