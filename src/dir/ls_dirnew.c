/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dirnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 13:03:54 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 13:40:06 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_dir.h"

t_dir		*ls_dirnew(void)
{
	t_dir	*new;

	if (!(new = ft_memalloc(sizeof(t_dir))))
		return(NULL);
	if (!(new->elst = ls_elstnew()))
	{
		ls_dirdel(&new);
		return (NULL);
	}
	return (new);
}
