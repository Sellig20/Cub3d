
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
	char	*join;
	char	**split;
	int k;
	
	k = 0;
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
		str = get_next_line(x->file, 0);
	}
	get_next_line(x->file, 1);
	free(str);
	int y = -1;
	int len = 0;
	int o = 0;
	int f = 0;
	while(join[++y])
		split = ft_split(join, '\n');
	while (split[o])
	{
		f = 0;
		len = ft_strlen(split[o]);
		dprintf(2, "join ==> %s\n", split[o]);
		while (split[o][f])
		{
			if (split[o][f] == ' ')
				split[o][f] = 'A';
			if (split[o][f] == 'A')
				dprintf(2, "+++ : ESPACE\n");
			else
				dprintf(2, "+++ : %c\n", split[o][f]);
			if ((f + 1 == len) && len < x->len)
			{
				while (len <= x->len)
				{
					dprintf(2, "+++ : ESPACE FIN\n");
					len++;
				}
			}
			f++;
		}
		o++;
	}
	return (0);
}