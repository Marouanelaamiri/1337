/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:48:25 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/03 12:01:59 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct p_position
{
	int	row;
	int	column;
}		t_posi;

typedef struct s_infob
{
	int		move;
	int		pic_width;
	int		pic_height;
	char	**rows;
	char	step_str[500];
	void	*pic_closeddoor;
	void	*pic_opendoor;
	void	*pic_wall;
	void	*pic_background;
	void	*pic_character;
	void	*mlx_ptr;
	void	*mlx_window;
	void	*pic_cf[10];
	int		num_cf;
	int		current_cf;
	void	*pic_ef[8];
	int		num_ef;
	int		current_ef;
}	t_infob;

char	*get_next_line(int fd);
int		ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	first_row(char **rows);
void	each_row(char **rows);
void	last_row(char **rows);
void	map_parsing(char **lines, char *maps);
char	**filling(char **lines, int x, int y);
char	*readingmap(char *row);
void	map_check(char **lines);
void	name_error(char *name);
void	ft_rendering(char *maps);
void	get_texture_background(t_infob *pic, void *mlx_ptr);
void	get_texture_closeddoor(t_infob *pic, void *mlx_ptr);
void	get_texture_opendoor(t_infob *pic, void *mlx_ptr);
void	get_texture_coin(t_infob *pic, void *mlx_ptr);
void	get_texture_wall(t_infob *pic, void *mlx_ptr);
void	get_texture_enemy(t_infob *pic, void *mlx_ptr);
t_infob	fetch_pic(t_infob *img, void *mlx_ptr);
int		ft_keycodes(int button, void *p);
void	up(t_infob *pic);
void	left(t_infob *pic);
void	down(t_infob *pic);
void	right(t_infob *pic);
size_t	check_len_rowsmap(char **lines);
size_t	check_col_lenmap(char *lines);
void	set_coin_frames(char *frames[]);
void	set_enemy_frames(char *frames[]);
void	handle_win_message(t_infob *pic);
void	handle_loss_message(t_infob *pic);
void	rendersize_background(char **rows, t_infob *pic);
void	rendersize_character(char **rows, t_infob *pic);
void	set_coin_frames(char *frames[]);
void	set_enemy_frames(char *frames[]);
void	rendersize_enemy(char **rows, t_infob *pic);
void	rendersize_wall(char **rows, t_infob *pic);
void	rendersize_coin(char **rows, t_infob *pic);
void	rendersize_door(char **rows, t_infob *pic);
void	ft_door(char **rows, t_infob *pic);
int		door_checker(char **rows);
void	borders_check(char **rows);
int		check_coins(char **rows);
void	checking_the_line(char **lines);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_printf(const char *f, ...);
int		ft_putchar(char c);
void	ren_again(t_infob *pic, t_posi coor, char **rows);
void	free_function(char **rows);
char	*ft_itoa(int n);
t_posi	ft_position(char **rows, int k);

#endif
