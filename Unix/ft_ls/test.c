#include "libft/libft.h"
#include "ft_ls.h"
#include <stdio.h>

void	ft_gettime(struct stat fstat, t_env *e)
{
	char	buff[13];
	char	*s;
	char	buf[64];
	size_t	len;

	s = ctime(&e->time);
	ft_memcpy(buff, &s[4], 12);
	buff[12] = 0;
	ft_putstr(buff);
	ft_putstr("  ");
	ft_putstr(".");
}



int		main()
{
	struct stat	fstat;
	t_env		e;
	int			i = 0;
	DIR		*dir;
	char	*str;
	struct	dirent	*sd;

	e.path = "skjbgijr";
	e.dir = opendir(e.path);
	if (!e.dir)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(e.path);
		ft_putstr(": ");
		perror(NULL);
	}
	else
	{
		printf("OPEN");
		closedir(e.dir);
		exit(1);
	}
	return (0);
}
