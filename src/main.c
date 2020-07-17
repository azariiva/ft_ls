/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:41:46 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 15:46:21 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include <dirent.h>

int		mnepank(t_elist *elst, char *flags)
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
			if (ls_recursive((t_entity *)ptr->content, flags) == ERR)
				return (ERR);
		ptr = ptr->next;
	}
	return (OK);
}

int		yapohui(t_elist *elst, char *flags)
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
			if (ls_recursive((t_entity *)ptr->content, flags) == ERR)
				return (ERR);
		ptr = ptr->prev;
	}
	return (OK);
}

// int			ls_show_direct(t_dlist *head)
// {
// 	mode_t	st_mode;
// 	t_dlist	*ptr;

// 	ptr = head;
// 	while (ptr)
// 	{
// 		st_mode = ((t_entity *)head->content)->stat.st_mode;
// 		if (!S_ISDIR(st_mode))
// 			ls_entityshow((t_entity *)head->content);
// 		ptr = ptr->next;
// 	}

// }

// int			ls_show_reverse(t_dlist *tail)
// {

// }

int			main(int ac, char*const av[])
{
	t_ls	*ls;

	if (!(ls = ls_new()))
	{
		ft_printf(ALC_ERR);
		return (0);
	}
	if (ls_parse_argv(ac, av, ls) == ERR)
	{
		ls_del(&ls);
		return (0);
	}
	ls_elstshow(ls->elst, ls->flags);
	(ls->flags['r'] ? yapohui(ls->elst, ls->flags) :
	mnepank(ls->elst, ls->flags));
	ls_del(&ls);
	return (0);
}
