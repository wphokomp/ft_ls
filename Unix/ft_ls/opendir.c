#include "ft_ls.h"

/*void	ft_sort_l(char **list, int ch)
{
	char	*tmp;
	int		i;

	i = -1;
	while (++i < (ft_strlen_point(list) - 1))
		if (list[i][ch] > list[i + 1][ch])
		{
			tmp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = tmp;
			i = -1;
		}
}

void	ft_sort_a(char **list)
{
	int		i;
	int		l_est;
	int		k = 0;

	i = 0;
	l_est = ft_strlen(list[i]);
	while (++i < ft_strlen_point(list) - 1)
		if (ft_strlen(list[i]) > ft_strlen(list[i + 1]))
		{
			l_est = ft_strlen(list[i]);
			k = i;
		}
	while (--l_est >= 0)
	{
		//printf("\t\t\tSort");
		ft_sort_l(list, i);
	}
}
*/
void	print(char **list)
{
	int		i;

	i = -1;
	while (list[++i])
	{
		ft_putnbr(i + 1);
		ft_putstr(". ");
		ft_putstr(ft_strjoin(list[i], "\n"));
	}
}

void	ft_sort2d(char **list)
{
	int		i;
	int		l;
	char	*tmp;

	i = 0;
	l = ft_strlen_point(list) - 1;
	while (i < l)
	{
		if (ft_strcmp(list[i], list[i + 1]) > 0)
		{
			tmp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int		main()
{
	char	**list = ft_strsplit("sddgg sfdnng adfsfb fdfbgbg nhgasd gnsdfda angis anghas", ' ');
	
	print(list);
	ft_sort2d(list);
	ft_putstr("\nSORT ELEMENT 0\n");
	print(list);
	return (0);
}
