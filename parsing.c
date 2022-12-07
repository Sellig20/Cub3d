
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

void	ft_map_space_a(char **map, t_data *x)
{
	(void)x;
	int p;
	int y;
	int fou;
    
	p = 0;
    fou = 0;
	while (map[p])
	{
		y = 0;
		dprintf(2, "----------> %s", map[p]);
		fou = ft_strlen(map[p]);
		while (map[p][y])
		{
			if (map[p][y] == ' ')
				map[p][y] = 'A';
			if (map[p][y] == 'A')
				dprintf(2, "+++ : ESPACE\n");
			else if (map[p][y] != '\n')
				dprintf(2, "+++ : %c\n", map[p][y]);
			if (map[p][y] == '\n' && ((y + 1) == fou) && fou < x->len)
			{
				while (fou <= x->len)
				{
					dprintf(2, "+++ : ESPACE FIN\n");
					fou++;
				}
			}
			y++;
		}
		p++;
	}
}

int	ft_count_line(t_data *x)
{
	char	*str;
	int		count;

	count = 0;
	str = get_next_line(x->file, 0);
	if (!str)
		return (ft_empty_map(x));
	while (str)
	{
		str = get_next_line(x->file, 0);
		if (str == NULL)
		{
			free(str);
			get_next_line(x->file, 1);
		}
		count++;
	}
	free(str);
	return (count);
}