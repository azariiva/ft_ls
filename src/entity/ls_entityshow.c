/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_entityshow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:03:15 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 19:11:36 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls_entity.h"
#include <grp.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <time.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>

// # include <dirent.h>
// # include <sys/stat.h>
// # include <pwd.h>
// # include <grp.h>
// # include <uuid/uuid.h>
// # include <time.h>
// # include <sys/types.h>
// # include <sys/acl.h>
// # include <sys/xattr.h>
// # include <limits.h>
// # include <sys/ioctl.h>

static char	*get_time(time_t t)
{
	char	*t_str;
	time_t	c;
	char	*c_str;

	c = time(NULL);
	c_str = ft_strdup(ctime(&c) + 20);
	t_str = ctime(&t) + 4;
	if (ft_strcmp(t_str + 16, c_str))
	{
		t_str[7] = ' ';
		ft_strcpy(t_str + 8, t_str + 16);
	}
	t_str[12] = 0;
	ft_strdel(&c_str);
	return (t_str);
}

static void	get_perm(char *p, t_entity *e)
{
	mode_t	m;

	m = e->stat.st_mode;
	p[1] = ((m & S_IRUSR) ? 'r' : '-');
	p[2] = ((m & S_IWUSR) ? 'w' : '-');
	p[3] = ((m & S_IXUSR) ? 'x' : '-');
	p[4] = ((m & S_IRGRP) ? 'r' : '-');
	p[5] = ((m & S_IWGRP) ? 'w' : '-');
	p[6] = ((m & S_IXGRP) ? 'x' : '-');
	p[7] = ((m & S_IROTH) ? 'r' : '-');
	p[8] = ((m & S_IWOTH) ? 'w' : '-');
	p[9] = ((m & S_IXOTH) ? 'x' : '-');
	p[10] = ((listxattr(e->path, NULL, 0, XATTR_NOFOLLOW) > 0) ? '@' : ' ');
	p[11] = 0;
}

static void	get_ftype(mode_t m, char *p)
{
	if (S_ISFIFO(m))
		p[0] = 'p';
	else if (S_ISCHR(m))
		p[0] = 'c';
	else if (S_ISDIR(m))
		p[0] = 'd';
	else if (S_ISBLK(m))
		p[0] = 'b';
	else if (S_ISREG(m))
		p[0] = '-';
	else if (S_ISLNK(m))
		p[0] = 'l';
	else if (S_ISSOCK(m))
		p[0] = 's';
	else
		p[0] = '?';
}

static void	print_lnk(t_entity *e)
{
	char	buf[PATH_MAX + 1];

	if (!S_ISLNK(e->stat.st_mode))
	{
		ft_printf("\n");
		return ;
	}
	readlink(e->path, buf, PATH_MAX);
	ft_printf(" -> %s\n", buf);
}

void		ls_entityshow(t_entity *e, size_t a[4], char *flags)
{
	char		p[12];

	get_ftype(e->stat.st_mode, p);
	get_perm(p, e);
	if (flags['l'])
	{
		ft_printf("%s %*zu %*s  %*s  %*zu %s %s", p, a[0], e->stat.st_nlink,
		a[2], getpwuid(e->stat.st_uid)->pw_name, a[1],
		getgrgid(e->stat.st_gid)->gr_name, a[3], e->stat.st_size,
		get_time(e->stat.st_mtime), e->name);
		print_lnk(e);
	}
	else
		ft_printf("%s\n", e->name);
}
