/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_elstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:47:47 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 20:24:39 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_elist.h"

int		ls_elstadd(t_elist *alst, t_entity *e)
{
	t_dlist	*new;

	if (!alst || !e || !(new = ft_dlstnew(e, sizeof(t_entity))))
		return (ERR);
	if (!alst->head)
	{
		alst->head = new;
		alst->tail = new;
	}
	else if (alst->tail == alst->head)
	{
		alst->head->next = new;
		new->prev = alst->head;
		alst->tail = new;
	}
	else
	{
		new->prev = alst->tail;
		alst->tail->next = new;
		alst->tail = new;
	}
	return (OK);
}
