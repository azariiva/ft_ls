/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:41:46 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 20:00:58 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include <dirent.h>

static int	mnepank(t_elist *elst, char *flags, int *ds)
{
	t_dlist	*ptr;
	char	d;

	d = flags['d'];
	flags['d'] = 1;
	ptr = elst->head;
	while (ptr)
	{
		if (S_ISDIR(((t_entity *)ptr->content)->stat.st_mode) &&
		ft_strcmp(((t_entity *)ptr->content)->name, "..") && !d)
			if (ls_recursive((t_entity *)ptr->content, flags, ds) == ERR)
				return (ERR);
		ptr = ptr->next;
	}
	return (OK);
}

static int	yapohui(t_elist *elst, char *flags, int *ds)
{
	t_dlist	*ptr;
	char	d;

	d = flags['d'];
	flags['d'] = 1;
	ptr = elst->tail;
	while (ptr)
	{
		if (S_ISDIR(((t_entity *)ptr->content)->stat.st_mode) &&
		ft_strcmp(((t_entity *)ptr->content)->name, "..") && !d)
			if (ls_recursive((t_entity *)ptr->content, flags, ds) == ERR)
				return (ERR);
		ptr = ptr->prev;
	}
	return (OK);
}

static void	billy(t_ls *ls, int f, int ds)
{
	if (ls->flags['f'])
	{
		ls->flags['t'] = 0;
		ls->flags['S'] = 0;
		ls->flags['r'] = 0;
		ls->flags['a'] = 1;
	}
	(ls->flags['t'] ? ls_elstsort(ls->elst, cmp_time) : 0);
	(ls->flags['S'] ? ls_elstsort(ls->elst, cmp_fsize) : 0);
	ls_elstshow(ls->elst, ls->flags);
	if (ds && f && !ls->flags['d'])
		ft_printf("\n");
	if (ds == 1 && !f)
		ls->flags[0] = 1;
}

int			main(int ac, char*const av[])
{
	t_ls	*ls;
	int		ds;
	int		f;

	if (!(ls = ls_new()))
	{
		ft_printf(ALC_ERR);
		return (0);
	}
	if ((f = ls_parse_argv(ac, av, ls, &ds)) == ERR)
	{
		ls_del(&ls);
		return (0);
	}
	billy(ls, f, ds);
	if (ds)
		ds--;
	(ls->flags['r'] ? yapohui(ls->elst, ls->flags, &ds) :
	mnepank(ls->elst, ls->flags, &ds));
	ls_del(&ls);
	return (0);
}
