/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_elstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:37:45 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/16 12:38:37 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libls_elist.h"

t_elist		*ls_elstnew(void)
{
	t_elist	*new;

	if (!(new = ft_memalloc(sizeof(t_elist))))
		return (NULL);
	return (new);
}
