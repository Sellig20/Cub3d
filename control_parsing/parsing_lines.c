/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:52:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/27 18:40:01 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_parse_map_last_lines(char **map, t_data *x)
{
	int	i;
	int	j;

	(void)map;
	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (x->map[i - 1][j])
	{
		if (!(x->map[i - 1][j] == ' ' || x->map[i - 1][j] == '1'))
			return (ft_putstr_fd("Error : No wall around the map\n", 2), 1);
		j++;
	}
	return (0);
}

int	ft_parse_map_first_lines(char **map, t_data *x)
{
	int	i;
	int	j;

	(void)map;
	i = 0;
	j = 0;
	while (x->map[0][j])
	{
		if (!(x->map[0][j] == ' ' || x->map[0][j] == '1'))
			return (ft_putstr_fd("Error : No wall around the map\n", 2), 1);
		j++;
	}
	return (0);
}

int	ft_parse_map_line(char **map, t_data *x)
{
	int	i;
	int	j;

	i = 0;
	(void)x;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' &&
				(map[i - 1][j] == ' ' || map[i + 1][j] == ' '))
				return (ft_putstr_fd("Error : No wall around the map\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}
