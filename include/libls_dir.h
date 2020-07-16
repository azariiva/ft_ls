/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls_dir.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:32:06 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 15:25:19 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_DIR_H

# define LIBLS_DIR_H

# include "libft.h"
# include "libls_elist.h"

typedef struct s_elist	t_elist;

typedef struct			s_dir
{
	struct s_elist		*elst;
}						t_dir;

t_dir					*ls_dirnew(void);
void					ls_dirdel(t_dir **dir);

#endif
