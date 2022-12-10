
#include "cub3d.h"

int	ft_open_file(char **argv, t_data *x)
{
	char	*str;

	x->file = open(argv[1], O_DIRECTORY);
	if (x->file > 2)
		return (close(x->file), ft_putstr_fd("Error : Is a folder\n", 2), 1);
	str = argv[1];
	if (!(ft_strnstr(&str[ft_strlen(argv[1]) - 4], ".cub", 4)))
		return (ft_putstr_fd("Error : Invalid extension map\n", 2), 1);
	if (ft_strcmp(str, ".cub") == 0)
		return (ft_putstr_fd("Error : Invalid infile\n", 2), 1);
	x->file = open(argv[1], O_RDONLY);
	if (x->file == -1)
		return (ft_putstr_fd("Error : Invalid file\n", 2), 1);
	return (0);
}

int	ft_empty_map(t_data *x)
{
	close(x->file);
	ft_putstr_fd("Error : Empty map\n", 2);
	return (get_next_line(x->file, 1), 0);
}

int	ft_parse_map_line1(char **map, t_data *x)
{
	int i;
	int j;
	int count1;
	int count2;
	(void)x;
	//int y = -1;

	i = 0;
	count2 = 0;
	while (map[i])
	{
		j = 0;
		count1 = 0;
		while (map[i][j] == 'A')
		{
			count1++;
			j++;
		}
	//	dprintf(2, "line = %d, count1 A = %d\n", ++y, count1);
		count2 = count1;
		i++;
		j = 0;
		while (count2 - 1 >= 0 && map[i][j])
		{
			//dprintf(2, "BABABABBABABABABABABABA\n");
			if (!((map[i][j] == '1') || (map[i][j] == 'A')))
			{
				// dprintf(2, "i => %s\n", map[i]);
				// dprintf(2, "j ---> %c\n", map[i][j]);
				dprintf(2, "(SENS 1) Error : no wall in beginning line\n");
				return (1);
			}
			j++;
			count2--;
		}
	}
	return (0);
}

int	ft_parse_map_line2(char **map, t_data *x)
{
	int i;
	int j;
	int count1;
	int count2;
	(void)x;
	int y = -1;

	i = 0;
	count2 = 0;
	int len;
	while (map[i])
	{
		j = 0;
		count1 = 0;
		while (map[i][j] != 'B')
			j++;
		dprintf(2, "j ------------- %d\n", j);
		while (map[i][j] == 'B')
		{
			count1++;
			j++;
		}
		dprintf(2, "line = %d, count1 B = %d\n", ++y, count1);
		count2 = count1;
		len = ft_strlen(map[i]) - 1;
		i++;
		while (count2 - 1 >= 0 && map[i][len])
		{
			if (!((map[i][len] == '1') || (map[i][len] == 'B')))
			{
				dprintf(2, "(SENS 1) Error : no wall in ending line\n");
				return (1);
			}
			len--;
			count2--;
		}
		i++;
	}
	return (0);
}

int	ft_parse_map_letter(char **map, t_data *x)
{
	int i;
	int j;
	(void)x;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == 'A' || map[i][j] == '1'
				|| map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == '0' || map[i][j] == 'B'))
			{
				dprintf(2, "i => %s\n", map[i]);
				dprintf(2, "j ---> %c\n", map[i][j]);
				ft_putstr_fd("Error : Stranger element in map\n", 2);
				return (1);
			}
			if ((map[i][j] == 'A' && map[i][j + 1] == '0')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'N')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'S')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'W')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'E')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'B'))
			{
				dprintf(2, "i => %s\n", map[i]);
				dprintf(2, "j ---> %c\n", map[i][j]);
				ft_putstr_fd("Error : No wall in begginning map\n", 2);
				return (1);
			}
			if ((map[i][j] == '0' && map[i][j + 1] == 'B')
				|| (map[i][j] == 'N' && map[i][j + 1] == 'B')
				|| (map[i][j] == 'S' && map[i][j + 1] == 'B')
				|| (map[i][j] == 'W' && map[i][j + 1] == 'B')
				|| (map[i][j] == 'E' && map[i][j + 1] == 'B')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'B'))
			{
				dprintf(2, "i => %s\n", map[i]);
				dprintf(2, "j ---> %c\n", map[i][j]);
				ft_putstr_fd("Error : No wall in ending map\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_map_split(char *join, t_data *x)
{
	char	**split;

	split = ft_split(join, '\n', x);
	ft_map_space_change(split, x);
	if (ft_parse_map_letter(split, x) == 1)
		return ;
	if (ft_parse_map_line1(split, x) == 1)
		return ;
	if (ft_parse_map_line2(split, x) == 1)
		return ;
	ft_free_args(split);
}

int	ft_open_map(char **argv, t_data *x)
{
	char	*str;
	char	*join;
	if (ft_open_file(argv, x) == 1)
		return (1);
	str = get_next_line(x->file, 0);
	if (!str)
		return (ft_empty_map(x));
	x->len = ft_strlen(str);
	join = NULL;
	while (str)
	{
		x->tmp_len = ft_strlen(str);
		if (x->tmp_len > x->len)
			x->len = x->tmp_len;
		join = ft_strjoin(join, str);
		if (join == NULL)
		{
			free(str);
			get_next_line(x->file, 1);
		}
		free(str);

		str = get_next_line(x->file, 0);
	}
	ft_map_split(join, x);
	get_next_line(x->file, 1);
	//free(join);
	return (0);
}
