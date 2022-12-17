
#include "cub3d.h"

int	ft_check_argv(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error : Invalid argument\n", 2);
		return (1);
	}
	if (ft_strlen(argv[1]) == 0)
		return (ft_putstr_fd("Error : Invalid argument\n", 2), 1);
	return (0);
}

int	ft_check_coordinates(char **tab)
{
	// int	i;
	// int	j;

	// i = 0;
	// while (tab[i])
	// {
	// 	j = 0;
	// 	while (tab[i][j])
	// 	{
				// dprintf(2, "POPOO\n");
			if (!(tab[0][0] == 'N' && tab[0][1] == 'O'))
				return (ft_putstr_fd("Error : coordinates values are wrong\n", 2), 1);
			if (!(tab[1][0] == 'S' && tab[1][1] == 'O'))
				return (ft_putstr_fd("Error : coordinates values are wrong\n", 2), 1);
			if (!(tab[2][0] == 'W' && tab[2][1] == 'E'))
				return (ft_putstr_fd("Error : coordinates values are wrong\n", 2), 1);
			if (!(tab[3][0] == 'E' && tab[3][1] == 'A'))
				return (ft_putstr_fd("Error : coordinates values are wrong\n", 2), 1);
	// 		j++;
	// 	}
	// 	i++;
	// }
	return (0);
}

int	ft_map_coor_tab(char **map, t_data *x)
{
	//char	**tab_coor;
	char	*join;
	int		y;
	int		o;

	(void)x;
	y = 0;
	o = 0;
	//tab_coor = malloc(sizeof(char *) * 6 + 1);
	join = NULL;
	while (map[o] && o <= 5)
	{
		join = ft_strjoin(join, map[o]);
		y++;
		dprintf(2, "coord ==> %s\n", map[o]);
		o++;
	}
	//tab_coor = ft_split(join, '\n', x);
	//if (ft_check_coordinates(tab_coor) == 1)
	//	return (1);
	return (0);
}

void	ft_map_space_change(char **map, t_data *x)
{
	int len;
	int f;
	int o;

	len = 0;
	o = 6;
	(void)x;
	while (map[o])
	{
		f = 0;
		len = ft_strlen(map[o]);
		while (map[o][f])
		{
			if (map[o][f] == ' ')
			{
				map[o][f] = 'A';
				f++;
			}
			// if (map[o][f] == 'A')
			// 	dprintf(2, "+++ : ESPACE\n");
			// else
			// 	dprintf(2, "+++ : %c\n", map[o][f]);
			else if ((f + 1 == len) && len < x->len)
			{
				// f++;
				while (len < x->len - 1)
				{
					map[o][f] = 'B';
					f++;
					// if (map[o][f] == 'A')
					// 	dprintf(2, "+++ : ESPACE FIN\n");
					len++;
				}
			}
			else
				f++;
		}
		dprintf(2, "join ==> %s\n", map[o]);
		o++;
	}
}
