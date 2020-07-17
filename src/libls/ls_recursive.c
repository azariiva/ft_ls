/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:14:25 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 17:29:14 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ls_recursive_direct(t_elist *elst, char *flags, int *ds)
{
	t_dlist	*ptr;

	ptr = elst->head;
	while (ptr)
	{
		if (S_ISDIR(((t_entity *)ptr->content)->stat.st_mode) &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".") &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".."))
			if (ls_recursive((t_entity *)ptr->content, flags, ds) == ERR)
				return (ERR);
		ptr = ptr->next;
	}
	return (OK);
}

int		ls_recursive_reverse(t_elist *elst, char *flags, int *ds)
{
	t_dlist	*ptr;

	ptr = elst->tail;
	while (ptr)
	{
		if (S_ISDIR(((t_entity *)ptr->content)->stat.st_mode) &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".") &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".."))
			if (ls_recursive((t_entity *)ptr->content, flags, ds) == ERR)
				return (ERR);
		ptr = ptr->prev;
	}
	return (OK);
}

int		ls_recursive(t_entity *d, char *flags, int *ds)
{
	DIR				*dir;
	struct dirent	*dirent;
	t_entity		e;
	size_t			total;
	int				rc;

	total = 0;
	dir = opendir(d->path);
	while ((dirent = readdir(dir)))
	{
		if ((rc = ls_fillentity(&e, dirent->d_name, d->path, flags)) == ERR)
			return (ERR);
		if (rc == OK)
		{
			if (ls_elstadd(d->elst, &e) == ERR)
			{
				ft_strdel(&(e.name));
				ft_strdel(&(e.path));
				ls_elstdel(&(e.elst));
				return (ERR);
			}
			if (e.elst && flags['R'])
				(*ds)++;
			total += e.stat.st_blocks;
		}
	}
	if (!flags[0])
		ft_printf("%s:\n", d->path);
	if (flags['l'])
		ft_printf("total: %zu\n", total);
	closedir(dir);
	(flags['t'] ? ls_elstsort(d->elst, cmp_time) : 0);
	(flags['S'] ? ls_elstsort(d->elst, cmp_fsize) : 0);
	ls_elstshow(d->elst, flags);
	if (*ds)
		ft_printf("\n");
	if (*ds)
		(*ds)--;
	if (flags['R'] && (flags['r'] ? ls_recursive_reverse(d->elst, flags, ds) :
	ls_recursive_direct(d->elst, flags, ds)) == ERR)
	{
		ls_elstdel(&(d->elst));
		return (ERR);
	}
	ls_elstdel(&(d->elst));
	return (OK);
}
