/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:55:38 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/21 18:18:51 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	ft_position_psx_psy(char **map, t_data *x)
{
	int	o;
	int	f;

	o = 0;
	while (map[o])
	{
		f = 0;
		while (map[o][f])
		{
			if (map[o][f] == 'N' || map[o][f] == 'S'
				|| map[o][f] == 'W' || map[o][f] == 'E')
			{
				x->pos = x->map[o][f];
				x->pos_x = o + 0.5;
				x->pos_y = f + 0.5;
				// dprintf(2, "o ---> %d\n", o);
				// dprintf(2, "f ---> %d\n", f);
				x->psx = o;
				x->psy = f;
				return (0);
			}
			f++;
		}
		o++;
	}
	return (1);
}

void	ft_fill_new_map(char **map, t_data *x)
{
	int	i;
	int	j;
	int	k;

	i = 6;
	j = 0;
	while (map[i])
		i++;
	x->map = malloc(sizeof(char *) * (i + 1));
	i = 6;
	k = 0;
	while (map[i])
	{
		j = 0;
		x->map[k] = malloc(sizeof(char) * (x->len + 1));
		while (map[i][j])
		{
			x->map[k][j] = map[i][j];
			j++;
		}
		x->map[k][j] = '\0';
		k++;
		i++;
	}
	x->map[k] = NULL;
}
