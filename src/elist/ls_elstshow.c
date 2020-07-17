/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_elstshow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:08:34 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 17:21:51 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_elist.h"
#include <grp.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <time.h>
#include <sys/stat.h>

static size_t	len(size_t n)
{
	size_t	l;

	if (n == 0)
		return (1);
	l = 0;
	while (n)
	{
		l++;
		n /= 10;
	}
	return (l);
}

static void		show_direct(t_dlist *ptr, size_t max[4], char *flags)
{
	max[0] = len(max[0]);
	max[3] = len(max[3]);
	while (ptr)
	{
		if (!flags['d'] && S_ISDIR(((t_entity *)ptr->content)->stat.st_mode))
		{
			ptr = ptr->next;
			continue;
		}
		ls_entityshow((t_entity *)ptr->content, max, flags);
		ptr = ptr->next;
	}
}

static void		show_reverse(t_dlist *ptr, size_t max[4], char *flags)
{
	max[0] = len(max[0]);
	max[3] = len(max[3]);
	while (ptr)
	{
		if (!flags['d'] && S_ISDIR(((t_entity *)ptr->content)->stat.st_mode))
		{
			ptr = ptr->prev;
			continue;
		}
		ls_entityshow((t_entity *)ptr->content, max, flags);
		ptr = ptr->prev;
	}
}

void			ls_elstshow(t_elist *alst, char *flags)
{
	size_t		max[4];
	size_t		t;
	struct stat	stat;
	t_dlist		*ptr;
	ft_bzero(max, sizeof(max));
	if (!alst || !alst->head)
		return ;
	ptr = alst->head;
	while (ptr)
	{
		stat = ((t_entity *)ptr->content)->stat;
		if (!flags['d'] && S_ISDIR(stat.st_mode))
		{
			ptr = ptr->next;
			continue;
		}
		if ((size_t)stat.st_nlink > max[0])
			max[0] = stat.st_nlink;
		if ((size_t)stat.st_size > max[3])
			max[3] = stat.st_size;
		if ((t = ft_strlen(getgrgid(stat.st_gid)->gr_name)) > max[1])
			max[1] = t;
		if ((t = ft_strlen(getpwuid(stat.st_uid)->pw_name)) > max[2])
			max[2] = t;
		ptr = ptr->next;
	}
	(flags['r'] ? show_reverse(alst->tail, max, flags) :
	show_direct(alst->head, max, flags));
}
