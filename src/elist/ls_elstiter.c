/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_elstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:51:48 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 14:51:18 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_elist.h"

void		ls_elstiter_f(t_elist *alst, void (*f)(t_entity *e))
{
	t_dlist	*ptr;

	ptr = alst->head;
	while (ptr)
	{
		f((t_entity *)ptr->content);
		ptr = ptr->next;
	}
}

void		ls_elstiter_b(t_elist *alst, void (*f)(t_entity *e))
{
	t_dlist	*ptr;

	ptr = alst->tail;
	while (ptr)
	{
		f((t_entity *)ptr->content);
		ptr = ptr->prev;
	}
}
