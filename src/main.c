#include "libls.h"
#include <dirent.h>

int	main(int ac, char*const av[])
{
	t_ls	*ls;
	size_t	i;

	if (!(ls = ft_memalloc(sizeof(t_ls))))
	{
		ft_printf(ALC_ERR);
		return (0);
	}
	if (ls_parse_argv(ac, av, ls) == ERR)
		return (0);
	i = -1;
	while (ls->fnames[++i])
		ft_printf("filename: %s\n", ls->fnames[i]);
	ls_del(&ls);
	return (0);
}
