
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

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

void ft_vouvou(char c, t_data *x)
{
	char *str;
	char *tmp;
	int i = 0;
	//int j = 0;

	(void)x;
	str = malloc(sizeof(char) * 4);
	//if (tmp[j] )
	while (str[i])
	{
		if (c >= 48 && c <= 57)
		{
			str[i] = c;
		}
		i++;
	}
	tmp = str;
	dprintf(2, "+++ : %s\n", str);
}

int	ft_sizeofnumber(char **map, int o, int f)
{
	int	count;

	count = 0;
	while (map[o][f] >= 48 && map[o][f] <= 57 )
	{
		count++;
		f++;
	}
	return (count);
}

int	ft_check_coordinates(char **map, t_data *x)
{
	int f;
	int o;
	char *str;
	int i = 0;
	int j = 0;

	o = 4;
	(void)x;
	int count = 0;
	x->rgb[0] = 0;
	x->rgb[1] = 0;
	x->rgb[2] = 0;
	while (map[o] && o < 6)
	{
		f = 0;
		count = 0;
		i = 0;
		j = 0;
		while ((!(map[o][f] >= 48 && map[o][f] <= 57 )))
			f++;
		count = ft_sizeofnumber(map, o , f);
		f = 0;
		i = 0;
		str = malloc(sizeof(char) * (count + 1));
		ft_bzero(str, sizeof(str));
		while ((!((map[o][f] >= 48 && map[o][f] <= 57 ))))
			f++;
		while ((map[o][f] >= 48 && map[o][f] <= 57) || map[o][f] == ',')
		{
			str[i] = map[o][f];
			i++;
			f++;
			if (i == count)
			{
				str[i] = '\0';
				x->rgb[j] = ft_atoi(str);
				j++;
				f++;
				i = 0;
				count = ft_sizeofnumber(map, o , f);
				free(str);
				str = malloc(sizeof(char) * (count + 1));
			}
		}
		free(str);
		o++;
	}
	// if (!(tab[0][0] == 'N' && tab[0][1] == 'O'))
	// 	return (ft_putstr_fd("Error : coordinates values are wrong\n", 2), 1);
	// if (!(tab[1][0] == 'S' && tab[1][1] == 'O'))
	// 	return (ft_putstr_fd("Error : coordinates values are wrong\n", 2), 1);
	// if (!(tab[2][0] == 'W' && tab[2][1] == 'E'))
	// 	return (ft_putstr_fd("Error : coordinates values are wrong\n", 2), 1);
	// if (!(tab[3][0] == 'E' && tab[3][1] == 'A'))
	// 	return (ft_putstr_fd("Error : coordinates values are wrong\n", 2), 1);
	// if (!(tab[4][0] == 'F' && tab[4][1] == 'E'))
	// 	return (ft_putstr_fd("Error : RGB values are wrong\n", 2), 1);
	// if (!(tab[5][0] == 'C' && tab[5][1] == 'A'))
	// 	return (ft_putstr_fd("Error : RGB values are wrong\n", 2), 1);
	return (0);
}

int		ft_fill_path_north(char **map, t_data *x)
{
	int	o;
	int	f;
	int y = 0;

	o = 0;
	f = 3;
	while (map[0][f])
	{
		f++;
	}
	x->north = malloc(sizeof(char) * (f + 1));
	f = 3;
	while (map[0][f])
	{
		x->north[y] = map[0][f];
		y++;
		f++;
	}
	x->north[y] = '\0';
	dprintf(2, "~~~~~~~~~~>>> %s\n", x->north);
	return (0);
}

int		ft_fill_path_south(char **map, t_data *x)
{
	int	o;
	int	f;
	int y = 0;

	o = 0;
	f = 3;
	while (map[1][f])
	{
		f++;
	}
	x->south = malloc(sizeof(char) * (f + 1));
	f = 3;
	while (map[1][f])
	{
		x->south[y] = map[1][f];
		y++;
		f++;
	}
	x->south[y] = '\0';
	dprintf(2, "~~~~~~~~~~>>> %s\n", x->south);
	return (0);
}

int		ft_fill_path_west(char **map, t_data *x)
{
	int	o;
	int	f;
	int y = 0;

	o = 0;
	f = 3;
	while (map[2][f])
	{
		f++;
	}
	x->west = malloc(sizeof(char) * (f + 1));
	f = 3;
	while (map[2][f])
	{
		x->west[y] = map[2][f];
		y++;
		f++;
	}
	x->west[y] = '\0';
	dprintf(2, "~~~~~~~~~~>>> %s\n", x->west);
	return (0);
}

int		ft_fill_path_east(char **map, t_data *x)
{
	int	o;
	int	f;
	int y = 0;

	o = 0;
	f = 3;
	while (map[3][f])
		f++;
	x->east = malloc(sizeof(char) * (f + 1));
	f = 3;
	while (map[3] && map[3][f])
	{
		x->east[y] = map[3][f];
		y++;
		f++;
	}
	x->east[y] = '\0';
	dprintf(2, "~~~~~~~~~~>>> %s\n", x->east);
	return (0);
}

int	ft_map_coor_tab(char **map, t_data *x) //MAP ENTIERE
{
	char	**tab_coor;
	int		y;
	int		o;

	(void)x;
	y = 0;
	o = 0;
	tab_coor = malloc(sizeof(char *) * (6 + 1));
	while (map[o] && o <= 5)
	{
		dprintf(2, "coord ==> %s\n", map[o]);
		tab_coor[y] = map[o];
		y++;
		o++;
	}
	if (ft_check_coordinates(tab_coor, x) == 1)
		return (1);
	if (ft_fill_path_north(map, x) == 1)
		return (1);
	if (ft_fill_path_south(map, x) == 1)
		return (1);
	if (ft_fill_path_west(map, x) == 1)
		return (1);
	if (ft_fill_path_east(map, x) == 1)
		return (1);
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
				//f++;
			}
			// if (map[o][f] == 'A')
			// 	dprintf(2, "+++ : ESPACE\n");
			// else
			// 	dprintf(2, "+++ : %c\n", map[o][f]);
			if ((f + 1 == len) && len < x->len)
			{
				//f++;
				while (len < x->len)
				{
					map[o][f] = 'B';
					f++;
					// if (map[o][f] == 'A')
					// 	dprintf(2, "+++ : ESPACE FIN\n");
					len++;
				}
			}
			f++;
		}
		dprintf(2, "join ==> %s\n", map[o]);
		o++;
	}
}
