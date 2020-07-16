/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entitydel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:44:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 15:21:22 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_entity.h"

void		ls_entitydel(t_entity **e)
{
	if (!e || !*e)
		return ;
	if ((*e)->dir)
		ls_dirdel(&((*e)->dir));
	if ((*e)->name)
		ft_strdel(&((*e)->name));
	ft_memdel((void **)e);
}
