/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:10:03 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 17:46:07 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H

# define LIBLS_H

# include "libls_entity.h"
# include "libls_elist.h"
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <limits.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <time.h>

# define FLAGS "lRartdS"
# define USAGE "usage: ft_ls [-%s] [file ...]\n"
# define ILLEGAL_OPT "ft_ls: illegal option -- %c\n"
# define ALC_ERR "ft_ls: allocation error\n"

typedef struct	s_ls
{
	char		flags[CHAR_MAX];
	t_elist		*elst;
}				t_ls;

void			ls_del(t_ls **ls);
t_ls			*ls_new(void);
int				ls_parse_argv(int ac, char*const av[], t_ls *ls, int *ds  );

char			*ls_addprefix(const char *dname, const char *fname);
void			ls_showinfo(t_entity *e);

int				cmp_fsize(t_dlist *a, t_dlist *b);
int				cmp_time(t_dlist *a, t_dlist *b);

#endif
