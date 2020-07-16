/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_elstshow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:08:34 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 21:36:16 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_elist.h"
# include <grp.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <time.h>
# include <sys/stat.h>

static void		get_ftype(mode_t m, char *p)
{
	if (S_ISFIFO(m))
		p[0] = 'p'; // именованный канал
	else if (S_ISCHR(m))
		p[0] = 'c'; // символьный файл устройства
	else if (S_ISDIR(m))
		p[0] = 'd'; // каталог
	else if (S_ISBLK(m))
		p[0] = 'b'; // блочный файл устройства
	else if (S_ISREG(m))
		p[0] = '-'; // обычный файл
	else if (S_ISLNK(m))
		p[0] = 'l'; // символьная ссылка
	else if (S_ISSOCK(m))
		p[0] = 's'; // сокет
	else
		p[0] = '?'; // какая-то дичь)
}

static void		get_perm(mode_t st_mode, char *p)
{
	p[1] = ((st_mode & S_IRUSR) ? 'r' : '-');
	p[2] = ((st_mode & S_IWUSR) ? 'w' : '-');
	p[3] = ((st_mode & S_IXUSR) ? 'x' : '-');
	p[4] = ((st_mode & S_IRGRP) ? 'r' : '-');
	p[5] = ((st_mode & S_IWGRP) ? 'w' : '-');
	p[6] = ((st_mode & S_IXGRP) ? 'x' : '-');
	p[7] = ((st_mode & S_IROTH) ? 'r' : '-');
	p[8] = ((st_mode & S_IWOTH) ? 'w' : '-');
	p[9] = ((st_mode & S_IXOTH) ? 'x' : '-');
	p[10] = 0;
}

static char		*get_time(struct stat stat)
{
	char	*t;
	time_t	cur;
	char	*cs;

	cur = time(NULL);
	cs = ft_strdup(ctime(&cur));
	t = ctime(&(stat.st_mtime)) + 4;
	if (ft_strcmp(t + 16, cs + 20))
	{
		t[7] = ' ';
		ft_strcpy(t + 8, t + 16);
	}
	ft_strdel(&cs);
	t[12] = 0;
	return (t);
}

static void		show_direct(t_dlist *ptr, size_t hlalgn, size_t szalgn,
size_t galgn, size_t ualgn)
{
	char		p[11];
	char		*gr_name;
	char		*u_name;
	char		*name;
	struct stat	stat;

	while (ptr)
	{
		stat = ((t_entity *)ptr->content)->stat;
		name = ((t_entity *)ptr->content)->name;
		gr_name = getgrgid(stat.st_gid)->gr_name;
		u_name = getpwuid(stat.st_uid)->pw_name;
		get_ftype(stat.st_mode, p);
		get_perm(stat.st_mode, p);
		ft_printf("%s %*zu %*s %*s  %*zu %s %s\n", p, hlalgn, stat.st_nlink,
		ualgn, u_name, galgn, gr_name, szalgn, stat.st_size, get_time(stat),
		name);
		ptr = ptr->next;
	}
}

static void		show_reverse(t_dlist *ptr, size_t hlalgn, size_t szalgn,
size_t galgn, size_t ualgn)
{
	char		p[11];
	char		*gr_name;
	char		*u_name;
	char		*name;
	struct stat	stat;

	while (ptr)
	{
		stat = ((t_entity *)ptr->content)->stat;
		name = ((t_entity *)ptr->content)->name;
		gr_name = getgrgid(stat.st_gid)->gr_name;
		u_name = getpwuid(stat.st_uid)->pw_name;
		get_ftype(stat.st_mode, p);
		get_perm(stat.st_mode, p);
		ft_printf("%s %*zu %*s %*s %*zu %s %s\n", p, hlalgn, stat.st_nlink,
		galgn, gr_name, ualgn, u_name, szalgn, stat.st_size, get_time(stat),
		name);
		ptr = ptr->prev;
	}
}

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

void			ls_elstshow(t_elist *alst, char *flags)
{
	size_t		maxhl;
	size_t		maxsz;
	size_t		maxusr;
	size_t		maxgrp;
	size_t		t;
	struct stat	stat;
	t_dlist		*ptr;

	maxgrp = 0;
	maxusr = 0;
	maxsz = 0;
	maxhl = 0;
	if (!alst || !alst->head)
		return ;
	ptr = alst->head;
	while (ptr)
	{
		stat = ((t_entity *)ptr->content)->stat;
		if ((size_t)stat.st_nlink > maxhl)
			maxhl = ((t_entity *)ptr->content)->stat.st_nlink;
		if ((size_t)stat.st_size > maxsz)
			maxsz = ((t_entity *)ptr->content)->stat.st_size;
		if ((t = ft_strlen(getgrgid(stat.st_gid)->gr_name)) > maxgrp)
			maxgrp = t;
		if ((t = ft_strlen(getpwuid(stat.st_uid)->pw_name)) > maxusr)
			maxusr = t;
		ptr = ptr->next;
	}
	(flags['r'] ?
	show_reverse(alst->tail, len(maxhl), len(maxsz), maxgrp, maxusr) :
	show_direct(alst->head, len(maxhl), len(maxsz), maxgrp, maxusr));
	ft_printf("\n");
}
