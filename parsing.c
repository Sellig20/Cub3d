
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

int	ft_check_coordinates(char **map, t_data *x)
{
	int f;
	int o;
	char *str;
	int i = 0;

	o = 4;
	(void)x;
	int count = 0;
	while (map[o])
	{
		f = 0;
		while (!((map[o][f] >= 48 && map[o][f] <= 57 && map[o][f] != ',')))
			f++;
		while (map[o][f] >= 48 && map[o][f] <= 57 && map[o][f] != ',')
		{
			count++;
			f++;
		}
		f = 0;
		i = 0;
		str = malloc(sizeof(char) * (count + 1));
		while (!((map[o][f] >= 48 && map[o][f] <= 57 && map[o][f] != ',')))
			f++;
		while (map[o][f] >= 48 && map[o][f] <= 57 && map[o][f] != ',')
		{
			str[i] = map[o][f];
			i++;
			f++;
			dprintf(2, "-> %s\n", str);
		}
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

int	ft_map_coor_tab(char **map, t_data *x)
{
	char	**tab_coor;
	//char	*join;
	int		y;
	int		o;

	(void)x;
	y = 0;
	o = 0;
	tab_coor = malloc(sizeof(char *) * (6 + 1));
	//join = NULL;
	while (map[o] && o <= 5)
	{
		//join = ft_strjoin(join, map[o]);
		tab_coor[y] = map[o];
		y++;
		dprintf(2, "coord ==> %s\n", map[o]);
		o++;
	}
	//tab_coor = ft_split(join, '\n', x);
	if (ft_check_coordinates(tab_coor, x) == 1)
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
