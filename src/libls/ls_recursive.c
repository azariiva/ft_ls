/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:14:25 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 20:10:00 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include <unistd.h>

int		di(t_elist *elst, char *fs, int *ds)
{
	t_dlist	*ptr;

	ptr = elst->head;
	while (ptr)
	{
		if (S_ISDIR(((t_entity *)ptr->content)->stat.st_mode) &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".") &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".."))
			if (ls_recursive((t_entity *)ptr->content, fs, ds) == ERR)
				return (ERR);
		ptr = ptr->next;
	}
	return (OK);
}

int		re(t_elist *elst, char *fs, int *ds)
{
	t_dlist	*ptr;

	ptr = elst->tail;
	while (ptr)
	{
		if (S_ISDIR(((t_entity *)ptr->content)->stat.st_mode) &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".") &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".."))
			if (ls_recursive((t_entity *)ptr->content, fs, ds) == ERR)
				return (ERR);
		ptr = ptr->prev;
	}
	return (OK);
}

int		nasral(t_entity *e)
{
	ft_strdel(&(e->name));
	ft_strdel(&(e->path));
	ls_elstdel(&(e->elst));
	return (ERR);
}

int		kuvshin(t_entity *d, size_t *total, int *ds, char *fs)
{
	DIR				*dir;
	int				rc;
	t_entity		e;
	struct dirent	*dirent;

	if (!(dir = opendir(d->path)))
	{
		ft_printf_fd(STDERR_FILENO, PERM_DENIED, d->name) && ft_printf("\n");
		(*ds ? (*ds)-- : 0);
		return (OK);
	}
	while ((dirent = readdir(dir)))
	{
		if ((rc = ls_fillentity(&e, dirent->d_name, d->path, fs)) == ERR)
			return (ERR);
		if (rc == END)
			continue;
		if (ls_elstadd(d->elst, &e) == ERR)
			return (nasral(&e));
		(ft_strcmp(dirent->d_name, ".") && ft_strcmp(dirent->d_name, "..") &&
		e.elst && fs['R'] ? (*ds)++ : 0);
		*total += e.stat.st_blocks;
	}
	closedir(dir);
	return (OK);
}

int		ls_recursive(t_entity *d, char *fs, int *ds)
{
	size_t			total;

	total = 0;
	(!fs[0] ? ft_printf("%s:\n", d->path) : 0);
	fs[0] = 0;
	if (kuvshin(d, &total, ds, fs) == ERR)
		return (ERR);
	((d->elst->head && fs['l']) ? ft_printf("total %zu\n", total) : 0);
	(fs['t'] ? ls_elstsort(d->elst, cmp_time) : 0);
	(fs['S'] ? ls_elstsort(d->elst, cmp_fsize) : 0);
	ls_elstshow(d->elst, fs);
	(*ds ? (ft_printf("\n") && (*ds)--) : 0);
	if (fs['R'] && (fs['r'] ? re(d->elst, fs, ds) : di(d->elst, fs, ds)) == ERR)
	{
		ls_elstdel(&(d->elst));
		return (ERR);
	}
	ls_elstdel(&(d->elst));
	return (OK);
}
