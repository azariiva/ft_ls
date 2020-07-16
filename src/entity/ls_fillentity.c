/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_fillentity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:55:59 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 15:24:11 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_entity.h"

int	ls_fillentity(t_entity *e, const char *name)
{
	ft_bzero(e, sizeof(t_entity));
	if (!e || !name)
		return (ERR);
	if (lstat(name, &(e->stat)) == -1)
		return (END);
	if (!(e->name = ft_strdup(name)))
		return (ERR);
	if (S_ISDIR(e->stat.st_mode) && !(e->dir = ls_dirnew()))
	{
		ft_strdel(&(e->name));
		return (ERR);
	}
	return (OK);
}
