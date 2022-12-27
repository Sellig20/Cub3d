/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:53:46 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/27 19:03:16 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_parse_map_first_case(char **map, t_data *x)
{
	int	i;

	i = 0;
	(void)x;
	while (map[i])
	{
		if (!(map[i][0] == ' ' || map[i][0] == '1'))
			return (ft_putstr_fd("Error : No wall around the map\n", 2), 1);
		i++;
	}
	return (0);
}

int	ft_parse_map_last_case(char **map, t_data *x)
{
	int	i;

	i = 0;
	(void)x;
	while (map[i])
	{
		if (!(map[i][x->len - 2] == ' ' || map[i][x->len - 2] == '1'))
			return (ft_putstr_fd("Error : No wall around the map\n", 2), 1);
		i++;
	}
	return (0);
}

int	ft_parse_start_position(char **map, t_data *x)
{
	int	i;
	int	j;

	i = 0;
	x->countpos = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				x->countpos++;
				if (x->countpos > 1)
				{
					ft_putstr_fd("Error : More than one start position\n", 2);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
