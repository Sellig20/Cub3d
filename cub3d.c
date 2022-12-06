/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:12 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/06 18:52:57 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_add_back(t_map *a_list, char *value)
{
	t_map	*a;
	t_map	*tmp;

	a = malloc(sizeof(t_map));
	if (a == NULL || value == NULL)
	{
		dprintf(2, "RETURN A OU VALUE NULL ADD BACK\n");
		return (NULL);
	}
	a->x = value;
	a->next = NULL;
	tmp = a_list;
	if (!tmp)
	{
		dprintf(2, "IF !TMP ADD BACK\n");
		a_list = a;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = a;
	}
	return (a_list);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

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

int	ft_open_file(char **argv, t_data *x)
{
	char	*str;

	//dprintf(2, "FILEEEEEEEEE=>>> %d\n", x->file);
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

void	ft_lstclear(t_map **tab)
{
	t_map	*map;

	map = *tab;
	while (*tab)
	{
		map = (*tab)->next;
		free((*tab)->x);
		free(*tab);
		*tab = map;
	}
}

int	ft_empty_map(t_data *x)
{
	close(x->file);
	ft_putstr_fd("Error : Empty map\n", 2);
	return (get_next_line(x->file, 1), 0);
}

void	ft_display(t_map **map)
{
	t_map *list;

	list = *map;
	while (list)
	{
		dprintf(2, "=> %s\n", list->x);
		list = list->next;
	}
}

int	ft_strcmmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_fill_start(t_map **map, t_data *x)
{
	t_map *list;
	char	*str;

	int	i = 0;
	x->tmp_len = 0;
	list = *map;
	str = list->x;
	x->len = ft_strlen(str);
	while (list)
	{
		str = list->x;
		x->tmp_len = ft_strlen(str);
		if (x->tmp_len > x->len)
			x->len = x->tmp_len;
		i = 0;
		//dprintf(2, "STR ===> %s | LEN ===> %d\n", str, ft_strlen(str));
		while (str[i])
		{
			if (str[i] == ' ')
			{
				//dprintf(2, "X");
				str[i] = 'X';
				//dprintf(2, "%c", str[i]);
			}
			// else
			// 	dprintf(2, "%c", str[i]);
			i++;
		}
		list = list->next;
	}
	dprintf(2, "WINNER LENGTH = %d\n", x->len);
}

void	ft_fill_end(t_map **map, t_data *x)
{
	t_map	*list;
	char	*str;
	int i;
	int j;
	int max;
	int difference;

	max = x->len;
	list = *map;
	j = 0;
	difference = 0;
	while (list)
	{
		difference = 0;
		str = list->x;
		i = 0;
		dprintf(2, "=> %s | max len = %d | len = %d\n", str, x->len, ft_strlen(str));
		if (x->len > ft_strlen(str))
		{
			difference = x->len - ft_strlen(str);
		}
		dprintf(2, "DIFFERENCE                                    %d\n", difference);
		while (difference > 0)
		{
			while (str[i])
			{
				if (str[i] == '\n')
				{
					dprintf(2, "back slash n trouve\n");
					//str[i] = 'X';
				}
				i++;
			}
			difference--;
		}
		list = list->next;
	}
}

void	ft_free_args(char **args)
{
	char	**tmp;

	tmp = args;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(args);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	final = (char *)malloc(sizeof(char)
			* ((ft_strlen(s1) + (ft_strlen(s2))) + 1));
	if (final == NULL)
		return (NULL);
	while ((char)s1[i])
	{
		final[i] = (char)s1[i];
		i++;
	}
	while ((char)s2[j])
	{
		final[i] = (char)s2[j];
		j++;
		i++;
	}
	final[i] = '\0';
	return (final);
}


void	ft_print_map(char **map, t_data *x)
{
	(void)x;
	//  int k;
	// int i;
	// int j;
	// char	**map_final;
	int p;
	int y;
	p = 0;
	while (map[p])
	{
		y = 0;
		dprintf(2, "----------> %s", map[p]);
		while (map[p][y])
		{
			dprintf(2, "+++ : %c\n", map[p][y]);
			y++;
		}
		p++;

	}

	// i = 0;
	// k = 0;
	// int o = 0;
	// map_final = malloc(sizeof(char *) * (x->count + 1));
	// dprintf(2, "COUNT=====>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> %d\n", x->len);
	// while (i < x->count)
	// {
	// 	j = 0;
	// 	map_final[i] = malloc(sizeof(char) * (x->len + 1));
	// 	while (map[k][o])
	// 	{
	// 		map_final[i][j] = map[k][o];
	// 		j++;
	// 		o++;
	// 	}
	// 		printf("print => %s\n", map_final[i]);
	// 	i++;
	// 	k++;
	// }
}

int	ft_count_line(t_data *x)
{
	char	*str;
	int		count;

	count = 0;
	str = get_next_line(x->file, 0);
	if (!str)
		return (ft_empty_map(x));
	while (str)
	{
		str = get_next_line(x->file, 0);
		if (str == NULL)
		{
			free(str);
			get_next_line(x->file, 1);
		}
		count++;
	}
	free(str);
	return (count);
}

int	ft_open_map(char **argv, t_data *x)
{
	//t_map	*tab;
	char	*str;
	char	**map;
	int k = 0;
//	int i = 0;
	//tab = NULL;
	if (ft_open_file(argv, x) == 1)
		return (1);
	x->count = 0;
	str = get_next_line(x->file, 0);
	if (!str)
		return (ft_empty_map(x));
	x->len = ft_strlen(str);
	map = malloc(sizeof(char *) * 1000 + 1);
	ft_bzero(map, sizeof(map));
	//count = ft_count_line(x);
	while (str)
	{
		//dprintf(2, "STR =============> %s\n", str);
		//map[k] = malloc(sizeof(char) * (ft_strlen(str) + 1));
		map[k] = str;
		k++;
		x->tmp_len = ft_strlen(str);
		if (x->tmp_len > x->len)
			x->len = x->tmp_len;
		// if (map == NULL)
		// {
		// 	free(str);
		// 	get_next_line(x->file, 1);
		// }
		//dprintf(2, "=> %s\n", map[k]);
		str = get_next_line(x->file, 0);
		x->count++;
		// tab = ft_add_back(tab, str);
		// if (tab == NULL)
		// {
		// 	free(str);
		// 	get_next_line(x->file, 1);
		// }
		// str = get_next_line(x->file, 0);
	}
	get_next_line(x->file, 1);
	free(str);
	//ft_fill_start(&tab, x);

	ft_print_map(map, x);
	//ft_fill_end(&tab, x);
	dprintf(2, "-----------------------------\n");
	//ft_display(&tab);
	dprintf(2, "MAX LEN = %d\n", x->len);
	dprintf(2, "-----------------------------\n");
	ft_free_args(map);
	//ft_lstclear(&tab);
	return (0);
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
	return (0);
}
