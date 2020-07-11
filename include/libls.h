/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:10:03 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/12 02:22:57 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H

# define LIBLS_H

# include "libft.h"

# define FLAGS_SIZE 128
# define FLAGS "lRart"
# define USAGE "usage: ls [-%s] [file ...]"
# define ILLEGAL_OPT "ls: illegal option -- %c"

typedef struct	s_ls
{
	int			flags[FLAGS_SIZE];
	char*const	*fnames;
}				t_ls;

int		ls_parse_argv(int ac, char*const av[]);

# endif
