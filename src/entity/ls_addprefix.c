/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_addprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 00:41:25 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 13:40:40 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

char	*ls_addprefix(const char *dname, const char *fname)
{
	char	*new;
	char	dnl;

	if (!dname)
		return ((new = ft_strdup(fname)) ? new : NULL);
	dnl = ft_strlen(dname);
	if (!(new = ft_strnew(dnl + ft_strlen(fname) + 1)))
		return (NULL);
	ft_strcat(new, dname);
	new[(unsigned)dnl] = '/';
	ft_strcat(new, fname);
	return (new);
}
