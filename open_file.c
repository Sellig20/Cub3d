
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

int	ft_open_map(char **argv, t_data *x)
{
	char	*str;
	char	**map;
	int k;
	
	k = 0;
	if (ft_open_file(argv, x) == 1)
		return (1);
	x->count = 0;
	str = get_next_line(x->file, 0);
	if (!str)
		return (ft_empty_map(x));
	x->len = ft_strlen(str);
	map = malloc(sizeof(char *) * 1000 + 1);
	ft_bzero(map, sizeof(map));
	while (str)
	{
		map[k] = str;
		k++;
		x->tmp_len = ft_strlen(str);
		if (x->tmp_len > x->len)
			x->len = x->tmp_len;
		str = get_next_line(x->file, 0);
		x->count++;
	}
	get_next_line(x->file, 1);
	free(str);
	ft_map_space_a(map, x);
	ft_free_args(map);
	return (0);
}