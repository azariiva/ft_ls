/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_proc_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:03:46 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/12 20:36:54 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	ls_proc_files(t_ls *ls)
{
	char				*ptr;
	t_list				*entities;
	t_list				*lst;
	t_entity			entity;

	entities = NULL;
	ptr = ls->fnames - 1;
	while (++ptr)
	{
		if (lstat(ptr, &(entity.stat)) == -1)
		{
			ft_printf(NOT_FOUND, ptr);
			continue;
		}

	}
}
