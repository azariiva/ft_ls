#include "libls.h"
#include <dirent.h>

int		mnepank(t_elist *elst, int order)
{
	t_dlist	*ptr;

	ptr = elst->head;
	while (ptr)
	{
		if (S_ISDIR(((t_entity *)ptr->content)->stat.st_mode) &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".."))
			if (ls_recursive((t_entity *)ptr->content, order) == ERR)
				return (ERR);
		ptr = ptr->next;
	}
	return (OK);
}

int		yapohui(t_elist *elst, int order)
{
	t_dlist	*ptr;

	ptr = elst->tail;
	while (ptr)
	{
		if (S_ISDIR(((t_entity *)ptr->content)->stat.st_mode) &&
		ft_strcmp(((t_entity *)ptr->content)->name, ".."))
			if (ls_recursive((t_entity *)ptr->content, order) == ERR)
				return (ERR);
		ptr = ptr->prev;
	}
	return (OK);
}

int			main(int ac, char*const av[])
{
	t_ls	*ls;

	if (!(ls = ls_new()))
	{
		ft_printf(ALC_ERR);
		return (0);
	}
	if (ls_parse_argv(ac, av, ls) == ERR)
	{
		ls_del(&ls);
		return (0);
	}
	ls_elstshow(ls->elst, ls->flags['r']);
	(ls->flags['r'] ? yapohui(ls->elst, ls->flags['r']) :
	mnepank(ls->elst, ls->flags['r']));
	ls_del(&ls);
	return (0);
}
