/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:49:46 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/06 18:05:27 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_data		t_data;

struct	s_data
{
	int	file;
	int len;
	int tmp_len;
	int	count;
};

typedef struct s_map		t_map;

struct	s_map
{
	char	*x;
	t_map	*next;
};

///////////////GET_NEXT_LINE/////
int		ft_strlen_gnl(char *str);
int		ft_read_buffer(int fd, char *buf);
int		ft_is_a_line(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd, int reset);
char	*ft_read_text(int fd, char *final);
char	*ft_extract_line(char *s1);
char	*ft_save_line(char *str);

///////////////UTILS/////////////
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);

#endif
