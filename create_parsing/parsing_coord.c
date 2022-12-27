/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:11:42 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/27 19:30:59 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_coordinates(char **map, t_data *x)
{
	(void)x;
	if (!(map[0][0] == 'N' && map[0][1] == 'O'))
		return (ft_putstr_fd("Error : 1 coordinates values are wrong\n", 2), 1);
	if (!(map[1][0] == 'S' && map[1][1] == 'O'))
		return (ft_putstr_fd("Error : 2 coordinates values are wrong\n", 2), 1);
	if (!(map[2][0] == 'W' && map[2][1] == 'E'))
		return (ft_putstr_fd("Error : 3 coordinates values are wrong\n", 2), 1);
	if (!(map[3][0] == 'E' && map[3][1] == 'A'))
		return (ft_putstr_fd("Error : 4 coordinates values are wrong\n", 2), 1);
	if (!(map[4][0] == 'F'))
		return (ft_putstr_fd("Error : RGB1 values are wrong\n", 2), 1);
	if (!(map[5][0] == 'C'))
		return (ft_putstr_fd("Error : RGB2 values are wrong\n", 2), 1);
	return (0);
}

int	ft_sizeofnumber(char **map, int o, int f)
{
	int	count;

	count = 0;
	while (map[o][f] >= 48 && map[o][f] <= 57)
	{
		count++;
		f++;
	}
	return (count);
}

int	ft_tab_rgb(char **map, t_data *x)
{
	int		f;
	int		o;
	int		j;
	char	*str;

	(void)x;
	o = 4;
	x->countrgb = 0;
	x->rgb[0] = 0;
	x->rgb[1] = 0;
	x->rgb[2] = 0;
	while (map[o])
	{
		f = 0;
		x->countrgb = 0;
		x->index = 0;
		j = 0;
		while ((!(map[o][f] >= 48 && map[o][f] <= 57)))
			f++;
		x->countrgb = ft_sizeofnumber(map, o, f);
		f = 0;
		str = malloc(sizeof(char) * (x->countrgb + 1));
		while ((!((map[o][f] >= 48 && map[o][f] <= 57))))
			f++;
		while ((map[o][f] >= 48 && map[o][f] <= 57) || map[o][f] == ',')
		{
			str[x->index] = map[o][f];
			x->index++;
			f++;
			if (x->index == x->countrgb)
			{
				str[x->index] = '\0';
				x->rgb[j] = ft_atoi(str);
				j++;
				f++;
				x->index = 0;
				x->countrgb = ft_sizeofnumber(map, o, f);
				free(str);
				str = malloc(sizeof(char) * (x->countrgb + 1));
			}
		}
		dprintf(2, "rgb 0 -> %d\n", x->rgb[0]);
		dprintf(2, "rgb 1 -> %d\n", x->rgb[1]);
		dprintf(2, "rgb 2 -> %d\n", x->rgb[2]);
		free(str);
		if (o == 4)
		{
			x->floor_color = x->rgb[0];
			x->floor_color = (x->floor_color * 256) + x->rgb[1];
			x->floor_color = (x->floor_color * 256) + x->rgb[2];
		}
		else if (o == 5)
		{
			x->ceiling_color = x->rgb[0];
			x->ceiling_color = (x->ceiling_color * 256) + x->rgb[1];
			x->ceiling_color = (x->ceiling_color * 256) + x->rgb[2];
		}
		o++;
	}
	return (0);
}

int	ft_organisation_coord(char **tab_coor, t_data *x)
{
	if (ft_check_coordinates(tab_coor, x) == 1)
		return (1);
	if (ft_tab_rgb(tab_coor, x) == 1)
		return (1);
	if (ft_fill_path_north(tab_coor, x) == 1)
		return (1);
	if (ft_fill_path_south(tab_coor, x) == 1)
		return (1);
	if (ft_fill_path_west(tab_coor, x) == 1)
		return (1);
	if (ft_fill_path_east(tab_coor, x) == 1)
		return (1);
	return (0);
}

int	ft_tab_coord(char **map, t_data *x)
{
	char	**tab_coor;
	int		y;
	int		o;

	(void)x;
	y = 0;
	o = 0;
	tab_coor = calloc(sizeof(char *), (6 + 1));
	while (map[o] && o <= 5)
	{
		tab_coor[y] = map[o];
		y++;
		o++;
	}
	if (ft_organisation_coord(tab_coor, x) == 1)
		return (1);
	free(tab_coor);
	return (0);
}
