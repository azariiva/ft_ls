/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:03:51 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 14:02:21 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

t_ls	*ls_new(void)
{
	t_ls	*ls;

	if (!(ls = ft_memalloc(sizeof(t_ls))))
		return (NULL);
	else if (!(ls->elst = ft_memalloc(sizeof(t_elist))))
	{
		ft_memdel((void **)&ls);
		return (NULL);
	}
	return (ls);
}
