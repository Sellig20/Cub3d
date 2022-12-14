/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:55:29 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/27 19:57:58 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	ft_map_split(char *join, t_data *x)
{
	char	**map;
	int		i;

	map = ft_split(join, '\n', x);
	i = 0;
	if (ft_tab_coord(map, x) == 1)
		return (ft_free_args(map), 1);
	ft_fill_new_map(map, x);
	i = 0;
	if (ft_parse_map_letter1(x->map, x) == 1)
		return (ft_free_args(map), 1);
	if (ft_parse_map_letter2(x->map, x) == 1)
		return (ft_free_args(map), 1);
	if (ft_parse_map_letter3(x->map, x) == 1)
		return (ft_free_args(map), 1);
	if (ft_parse_start_position(x->map, x) == 1)
		return (ft_free_args(map), 1);
	ft_map_split2(x, map);
	return (0);
}

int	ft_map_split2(t_data *x, char **map)
{
	if (ft_parse_map_line(x->map, x) == 1)
		return (ft_free_args(map), 1);
	if (ft_parse_map_first_lines(x->map, x) == 1)
		return (ft_free_args(map), 1);
	if (ft_parse_map_last_lines(x->map, x) == 1)
		return (ft_free_args(map), 1);
	if (ft_parse_map_first_case(x->map, x) == 1)
		return (ft_free_args(map), 1);
	if (ft_parse_map_last_case(x->map, x) == 1)
		return (ft_free_args(map), 1);
	return (0);
}

int	ft_open_map(char **argv, t_data *x)
{
	char	*str;
	char	*join;

	x->max = 0;
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
		x->max++;
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
	free(join);
	return (0);
}
