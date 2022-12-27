/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:49:46 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/27 19:56:19 by jecolmou         ###   ########.fr       */
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
# include <math.h>
# include <X11/keysym.h>

typedef struct s_imgdata
{
	void	*image;
	int		*addr;
	int		img_width;
	int		img_height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_imgdata;

typedef struct	s_data
{
	char **map;
	int	file;
	int len;
	int tmp_len;
	int	count;
	int max;
	int	countrgb;
	int	index;
	int	countpos;
	void			*mlx_ptr;
	void			*mlx_win;
	int		texture_width;
	int		texture_height;
	struct s_imgdata	*imgdata;
	//
	char			pos;
	double			pos_x;
	double			pos_y;
	int				psx;
	int				psy;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				floor_color;
	int				ceiling_color;
	int				rgb[3];
	double			rotspeed;
	double			movespeed;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			olddirx;
	double			olddiry;
	double			oldplanex;
	double			oldplaney;
	double			raydirx;
	double			raydiry;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			sidedistx;
	double			sidedisty;
	double			step;
	double			wallx;
	double			texpos;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				rotate_right;
	int				rotate_left;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				left;
	int				right;
	int				front;
	int				back;
	int				texx;
	int				texy;
	int				texwidth;
	int				texheight;
	int				x;
	int				i;
	int				j;
	int				b;
	int				y;
	int				fd;
	char			*line;
	char			*str;

	void			*img;
	int				*addr;
	int				size_line;
	int				endian;
	int				bits_per_pixel;
}	t_data;

///////////////GET_NEXT_LINE/////
int		ft_strlen_gnl(char *str);
int		ft_read_buffer(int fd, char *buf);
int		ft_is_a_line(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd, int reset);
char	*ft_read_text(int fd, char *final);
char	*ft_extract_line(char *s1);
char	*ft_save_line(char *str);
// int		ft_strlen_bb(char *str);
// char	*ft_strjoin_bb(char *s1, char *s2);
// int		ft_read_buffer(int fd, char *buf);
// char	*get_next_line(int fd);
// int		ft_is_a_line(char *str);
// char	*ft_read_text(int fd, char *final);
// char	*ft_extract_line(char *s1);
// char	*ft_save_line(char *str);
// char	*get_next_line(int fd);

///////////////UTILS/////////////
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c, t_data *x);
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(const char *str);

//////////FREE///////////////////
void	ft_free_args(char **args);

////////////////PARSING///////////
//parsing
int		ft_check_argv(int argc, char **argv);
void	ft_map_space_change(char **map, t_data *x);
int		ft_count_line(char **argv, t_data *x);
int		ft_position_psx_psy(char **map, t_data *x);
void	ft_fill_new_map(char **map, t_data *x);
//pasing_coord.c
int		ft_tab_coord(char **map, t_data *x);
int		ft_check_coordinates(char **map, t_data *x);
//parsing_lines
int		ft_parse_map_first_lines(char **map, t_data *x);
int		ft_parse_map_line(char **map, t_data *x);
int		ft_parse_map_last_lines(char **map, t_data *x);
//parsing_cases.c
int		ft_parse_map_first_case(char **map, t_data *x);
int		ft_parse_map_last_case(char **map, t_data *x);
int		ft_parse_start_position(char **map, t_data *x);
//parsing_letters.c
int		ft_parse_map_letter1(char **map, t_data *x);
int		ft_parse_map_letter2(char **map, t_data *x);
int		ft_parse_map_letter3(char **map, t_data *x);
//open file
int		ft_open_file(char **argv, t_data *x);
int		ft_empty_map(t_data *x);
int		ft_open_map(char **argv, t_data *x);
int		ft_map_coor_tab(char **map, t_data *x);
int		ft_map_split2(t_data *x, char **map);
//fill_paths_map.c
int		ft_fill_path_north(char **map, t_data *x);
int		ft_fill_path_south(char **map, t_data *x);
int		ft_fill_path_west(char **map, t_data *x);
int		ft_fill_path_east(char **map, t_data *x);







/////////////////////////////////////////////////

void	ft_free_image(t_data *data, int j);
int	ft_free(t_data *data, int j);
char	*img_path(t_data *data, int i);
void	get_img(t_data *data);
void	new_window(t_data *data);
void	ft_init_raycast(t_data **data);
void	init_step_and_sidedist(t_data **data);
void	find_wall(t_data **data);
void	touch_wall(t_data **data);
void	pass_to_3d(t_data *ray);
void	view_left(t_data *data, double olddirx);
void	camera_rotation(t_data *data);
void	back_and_forth(t_data *data);
void	move_left_right(t_data *data);
int	draw(t_data *data);
void	which_texture(t_data *data, int *side);
void	calculate_texture(t_data *data);
void	display_texture(t_data *data, int y, int x, int i);
void	draw_texture(t_data *data);
void	init_data(t_data *data);
void	init_game(t_data *data);
void	init_direction(t_data *data);
void	init_game2(t_data *data);
void	init_path_text(t_data *data);

#endif
