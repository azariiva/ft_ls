/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:32:09 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 16:55:37 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_ENTITY_H

# define LIBLS_ENTITY_H

# include "libft.h"
# include "libls_elist.h"
# include <sys/stat.h>

typedef struct s_elist	t_elist;

typedef struct			s_entity
{
	char				*name;
	char				*path;
	struct stat			stat;
	t_elist				*elst;
}						t_entity;

void					ls_entitydel(t_entity **e);
int						ls_fillentity(t_entity *e, const char *name,
const char *dpath, const char *flags);
void					ls_entityshow(t_entity *e, size_t a[4]);

char					*ls_addprefix(const char *dname, const char *fname);
int						ls_recursive_direct(t_elist *elst, char *order,
int *ds);
int						ls_recursive_reverse(t_elist *elst, char *order,
int *ds);
int						ls_recursive(t_entity *d, char *order,
int *ds);

#endif
