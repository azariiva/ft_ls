/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_elstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:38:50 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 15:18:34 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_elist.h"

static void	del(void *content, size_t size)
{
	if (size && content)
		ls_entitydel((t_entity **)&content);
}

void		ls_elstdel(t_elist **alst)
{
	if (!alst || !*alst)
		return ;
	ft_dlstdel(&((*alst)->head), del);
	(*alst)->tail = NULL;
	ft_memdel((void **)alst);
	*alst = NULL;
}
