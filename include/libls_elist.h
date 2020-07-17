/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls_elist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:29:08 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/17 13:44:08 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_ELIST_H

# define LIBLS_ELIST_H

# include "libft.h"
# include "libls_entity.h"

typedef struct s_entity	t_entity;

typedef struct			s_elist
{
	t_dlist		*head;
	t_dlist		*tail;
}						t_elist;

t_elist					*ls_elstnew(void);
void					ls_elstdel(t_elist **alst);
int						ls_elstadd(t_elist *alst, t_entity *e);
void					ls_elstiter_f(t_elist *alst, void (*f)(t_entity *e));
void					ls_elstiter_b(t_elist *alst, void (*f)(t_entity *e));
/*
** a[4] = {hlalgn, galgn, ualgn, szalgn};
** max[4] = {maxhl, maxgrp, maxusr, maxsz};
*/
void					ls_elstshow(t_elist *alst, char *flags);

#endif
