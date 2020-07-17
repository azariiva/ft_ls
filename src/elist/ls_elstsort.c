/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_elstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:54:54 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 15:17:13 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_elist.h"

void		ls_elstsort(t_elist *alst, int (*cmp)(t_dlist *, t_dlist *))
{
	t_dlist	*ptr;

	ft_dlstsort(&(alst->head), cmp);
	ptr = alst->head;
	while (ptr->next)
		ptr = ptr->next;
	alst->tail = ptr;
}
