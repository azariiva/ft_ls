/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:34:31 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 15:37:13 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int	cmp_time(t_dlist *a, t_dlist *b)
{
	t_entity	*ea;
	t_entity	*eb;

	ea = (t_entity *)a->content;
	eb = (t_entity *)b->content;
	if (ea->stat.st_mtime < eb->stat.st_mtime)
		return (1);
	else if (ea->stat.st_mtime == eb->stat.st_mtime)
		return (ft_strcmp(ea->name, eb->name) > 0);
	return (0);
}

int	cmp_fsize(t_dlist *a, t_dlist *b)
{
	t_entity	*ea;
	t_entity	*eb;

	ea = (t_entity *)a->content;
	eb = (t_entity *)b->content;
	if (ea->stat.st_size < eb->stat.st_size)
		return (1);
	else if (ea->stat.st_size == eb->stat.st_size)
		return (ft_strcmp(ea->name, eb->name) > 0);
	return (0);
}
