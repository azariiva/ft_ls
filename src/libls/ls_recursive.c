/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:14:25 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 21:30:38 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ls_recursive_direct(t_elist *elst, char *flags)
{
	t_dlist	*ptr;

	ptr = elst->head;
	while (ptr)
	{
		if (S_ISDIR(((t_entity *)ptr->content)->stat.st_mode) &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".") &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".."))
			if (ls_recursive((t_entity *)ptr->content, flags) == ERR)
				return (ERR);
		ptr = ptr->next;
	}
	return (OK);
}

int		ls_recursive_reverse(t_elist *elst, char *flags)
{
	t_dlist	*ptr;

	ptr = elst->tail;
	while (ptr)
	{
		if (S_ISDIR(((t_entity *)ptr->content)->stat.st_mode) &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".") &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".."))
			if (ls_recursive((t_entity *)ptr->content, flags) == ERR)
				return (ERR);
		ptr = ptr->prev;
	}
	return (OK);
}

int		ls_recursive(t_entity *d, char *flags)
{
	DIR				*dir;
	struct dirent	*dirent;
	t_entity		e;
	size_t			total;

	total = 0;
	dir = opendir(d->path);
	while ((dirent = readdir(dir)))
	{
		if (ls_fillentity(&e, dirent->d_name, d->path, flags) == ERR)
			return (ERR);
		if (ls_elstadd(d->elst, &e) == ERR)
		{
			ft_strdel(&(e.name));
			ft_strdel(&(e.path));
			ls_elstdel(&(e.elst));
			return (ERR);
		}
		total += e.stat.st_blocks;
	}
	ft_printf("%s:\n", d->path);
	ft_printf("total: %zu\n", total);
	closedir(dir);
	ls_elstshow(d->elst, flags);
	if ((flags['r'] ? ls_recursive_reverse(d->elst, flags) :
	ls_recursive_direct(d->elst, flags)) == ERR)
	{
		ls_elstdel(&(d->elst));
		return (ERR);
	}
	ls_elstdel(&(d->elst));
	return (OK);
}
