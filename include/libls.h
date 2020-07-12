/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:10:03 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/12 15:43:01 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H

# define LIBLS_H

# include "libft.h"
# include "limits.h"

# define FLAGS "lRart"
# define USAGE "usage: ft_ls [-%s] [file ...]\n"
# define ILLEGAL_OPT "ft_ls: illegal option -- %c\n"
# define ALC_ERR "ft_ls: allocation error\n"

typedef struct	s_ls
{
	int			flags[CHAR_MAX];
	const char	**fnames;
}				t_ls;

int		ls_parse_argv(int ac, char*const av[], t_ls *ls);
void	ls_del(t_ls **ls);

# endif
