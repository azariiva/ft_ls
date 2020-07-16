/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:32:09 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 16:03:24 by blinnea          ###   ########.fr       */
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
	struct stat			stat;
	t_elist				*elst;
}						t_entity;

void					ls_entitydel(t_entity **e);
int						ls_fillentity(t_entity *e, const char *name);

#endif
