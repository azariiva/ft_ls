#include "libls.h"
#include <dirent.h>

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
	ls_del(&ls);
	return (0);
}
