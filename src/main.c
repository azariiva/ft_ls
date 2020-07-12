#include "libls.h"
#include <dirent.h>

static size_t	count_dd_buf_size(DIR *dir)
{
	size_t	ctr;

	ctr = -1;
	while (dir->__dd_buf[++ctr])
		;
	return (ctr);
}

int	main(int ac, char*const av[])
{
	t_ls	*ls;
	if (!(ls = ft_memalloc(sizeof(t_ls))))
	{
		ft_printf(ALC_ERR);
		return (0);
	}
	if (ls_parse_argv(ac, av, ls) == ERR)
		return (0);
	ls_procfiles(ls);
	ls_del(&ls);

	DIR	*dir;

	if (!(dir = opendir("Makefile")))
	{
		return (0);
	}

	ft_printf("%zu\n", count_dd_buf_size(dir));
	closedir(dir);
	return (0);
}
