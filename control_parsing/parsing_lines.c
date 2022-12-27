/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:52:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/21 20:23:54 by jecolmou         ###   ########.fr       */
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
			return (ft_putstr_fd("Error : No wall around the map last line\n", 2), 1);
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
			return (ft_putstr_fd("Error : No wall around the map first line\n", 2), 1);
		j++;
	}
	return (0);
}

int	ft_parse_map_line1(char **map, t_data *x)
{
	int i;
	(void)x;
	int j;
	int count1;
	(void)map;
	dprintf(2, "COUCOU\n");
	i = 0;
	while (x->map[i])
	 {
		j = 0;
		count1 = 0;
		while (x->map[i][j])// == ' ')
		{
			if (map[i][j] == ' ')
				count1++;
			j++;
		}
		dprintf(2, "COUNT 1 = %d\n", count1);
		dprintf(2, "=> %s\n", map[i]);
		i++;
		// j = 0;
		// while (count1 - 1 >= 0 && x->map[i][j])
		// {
		// 	if (!((x->map[i][j] == '1') || (x->map[i][j] == ' ')))
		// 	{
		// 		dprintf(2, "(SENS 1) Error : no wall in beginning line\n");
		// 		return (1);
		// 	}
		// 	j++;
		// 	count1--;
		// }
	}
	return (0);
}

int	ft_parse_map_line2(char **map, t_data *x)
{
	int i;
	int j;
	(void)x;
	int count;
	int len;
	int diff;
	(void)map;

	len = 0;
	diff = 0;
	i = 0;
	while (x->map[i])
	{
		j = 0;
		count = 0;
		len = ft_strlen(x->map[i]);
		//dprintf(2, "x->map : %s\n", x->map[i]);
		while(x->map[i][j])
		{
			if (x->map[i][j] == 'B')
				count++;
			j++;
		}
		diff = len - count;
		i++;
		while (x->map[i] && i && x->map[i][diff])
		{
			if (!(x->map[i][diff] == 'B' || x->map[i][diff] == '1'))
			{
				return (1);
			}
			diff++;
		}
	}
	return (0);
}
