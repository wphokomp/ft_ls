#include "test.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 1)
	{
		e.dir = opendir(".");
		if (e.dir == NULL)
			printf("%d\n", 0);
		while ((e.sd = readdir(e.dir)))
			printf("%s\n", (e.sd)->d_name);
		closedir(e.dir);
	}
	return (0);
}
