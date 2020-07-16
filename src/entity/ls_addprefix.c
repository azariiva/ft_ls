/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_addprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 00:41:25 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 20:35:16 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

char	*ls_addprefix(const char *dname, const char *fname)
{
	char	*new;
	char	dnl;

	/*
	** Fix me later
	*/
	if (!dname)
	{
		if (!(new = ft_strdup(fname)))
			return (NULL);
		return (new);
	}
	dnl = ft_strlen(dname);
	if (!(new = ft_strnew(dnl + ft_strlen(fname) + 1)))
		return (NULL);
	ft_strcat(new, dname);
	new[(unsigned)dnl] = '/';
	ft_strcat(new, fname);
	return (new);
}
