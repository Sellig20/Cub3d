/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:12 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/10 15:17:56 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	x;

	ft_bzero(&x, sizeof(x));
	x.file = 0;
	if (ft_check_argv(argc, argv) == 1)
		return (1);
	if (ft_open_map(argv, &x) == 1)
		return (1);
	return (0);
}
