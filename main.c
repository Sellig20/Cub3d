/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:12 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/27 19:53:59 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_all(t_data *data)
{
	ft_free_image(data, 4);
	//FREE ALL MAP, MAP PATH, TMP SI IL Y A, DATA, PATH, IMGDATA,
	free(data->imgdata);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == 100)
		data->right = 1;
	else if (keycode == 97)
		data->left = 1;
	else if (keycode == 119)
		data->front = 1;
	else if (keycode == 115)
		data->back = 1;
	else if (keycode == 65361)
		data->rotate_left = 1;
	else if (keycode == 65363)
		data->rotate_right = 1;
	else if (keycode == 65307)
		ft_free(data, 4);
	return (1);
}

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == 100)
		data->right = 0;
	else if (keycode == 97)
		data->left = 0;
	else if (keycode == 119)
		data->front = 0;
	else if (keycode == 115)
		data->back = 0;
	else if (keycode == 65361)
		data->rotate_left = 0;
	else if (keycode == 65363)
		data->rotate_right = 0;
	else if (keycode == 65307)
		ft_free(data, 4);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	x;

	ft_bzero(&x, sizeof(x));
	x.file = 0;
	if (ft_check_argv(argc, argv) == 1)
		return (1);
	if (ft_open_map(argv, &x) == 1)
		return (1);
	// RECUPERER INFO MAP -> FAIRE FONCTION GET_INFO QUI DOIT RECUPERER LES INFO DE LA MAP DONC LES COULEURS A METTRE DANS NOTRE STRUCTURE GENRE data->floor POUR LE SOL ET data->ceiling POUR LE PLAFOND
	// PUIS RECUPERER LES COULEURS DE CES INT RGB data->RGB[0] = atoi du premier nombre en question etc
	// Il FAUT AUSSI RECUPERER LES PATHS DE NOS IMAGES DONC UN NOUVEAU TAB AVEC LES INFOS DU DEBUT DE MAP DONC 1ere LIGNE DU TABLEAU LE PATH DE NO DEUXIEME LIGNE LE PATH DE SO
	// TROISIEME LIGNE WE ET QUATRIEME EA data->mappath par exemple
	if (ft_position_psx_psy(x.map, &x) == 1)
		return (1);
	// int p = 0;
	// while (x.map[p])
	// {
	// 	dprintf(2, "pppppppp----- %s\n", x.map[p]);
	// 	p++;
	// }

	ft_free_args(x.map);
	// x.map[x.psx][x.psy] = '0';
	// new_window(&x);
	// init_game(&x); // INIT TOUTES LES VARIABLES NECESSAIRES AU JEU A 0 + DIRECTION
	// x.img = mlx_new_image(x.mlx_ptr, 2560, 1440);
	// x.addr = (int *)mlx_get_data_addr(x.img,
	// 		&x.bits_per_pixel, &x.size_line, &x.endian);
	// mlx_hook(x.mlx_win, 2, 1L << 0, ft_key_press, &x);
	// mlx_loop_hook(x.mlx_ptr, draw, &x);
	// mlx_hook(x.mlx_win, 3, 1L << 1, ft_key_release, &x);
	// mlx_hook(x.mlx_win, 17, 0, close_all, &x);
	// mlx_loop(x.mlx_ptr);
	free(x.north);
	free(x.south);
	free(x.west);
	free(x.east);
	return (0);
}

	// dprintf(2, "x psx -----------------------------------------------> %d\n", x.psx);
	// dprintf(2, "x psy -----------------------------------------------> %d\n", x.psy);
