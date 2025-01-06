/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:09:23 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/05 13:39:49 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct p_position
{
	int	row;
	int	column;
}		t_posi;

typedef struct info_struct
{
	int		move;
	int		pic_width;
	int		pic_height;
	char	**rows;
	void	*pic_closeddoor;
	void	*pic_opendoor;
	void	*pic_wall;
	void	*pic_background;
	void	*pic_coin;
	void	*pic_character;
	void	*mlx_ptr;
	void	*mlx_window;
} t_info;

void	*ft_calloc(size_t count, size_t size);
// static void	ckeck_format(const char *str, va_list args, size_t *count);
int	ft_printf(const char *format, ...);
void	ft_putchar_printf(char c, size_t *count);
void	ft_putnbr_printf(int nbr, size_t *count);
void	ft_putstr_printf(char *str, size_t *count);
char	**ft_split(char const *s, char c);
// static void	*ft_free(char **arr, int count);
// static size_t	get_len(const char *s, char c);
// static size_t	ft_countword(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_joinfree(char *buffer, char *new_buffer);
char	*get_remaning(char *buffer);
char	*ft_getline(char *buffer);
char	*read_from_file(int fd, char *buffer);
char	*get_next_line(int fd);
void	first_row(char **rows);
void	each_row(char **rows);
void	last_row(char **rows);
void	map_parsing(char **lines, char *maps);
char	**filling(char **lines, int x, int y);
char	*readingmap(char *row);
void	map_check(char **lines);
void	name_error(char *name);
void	ft_rendering(char *maps);
void	get_texture_background(t_info *pic, void *mlx_ptr);
void	get_texture_closeddoor(t_info *pic, void *mlx_ptr);
void	get_texture_character(t_info *pic, void *mlx_ptr);
void	get_texture_opendoor(t_info *pic, void *mlx_ptr);
void	get_texture_coin(t_info *pic, void *mlx_ptr);
void	get_texture_wall(t_info *pic, void *mlx_ptr);
t_info	fetch_pic(t_info *img, void *mlx_ptr);
int		ft_keycodes(int button, void *p);
void	up(t_info *pic);
void	left(t_info *pic);
void	down(t_info *pic);
void	right(t_info *pic);
size_t	check_len_rowsmap(char **lines);
size_t	check_col_lenmap(char *lines);
void	rendersize_background(char **rows, t_info *pic);
void	rendersize_character(char **rows, t_info *pic);
void	rendersize_wall(char **rows, t_info *pic);
void	rendersize_coin(char **rows, t_info *pic);
void	rendersize_door(char **rows, t_info *pic);
void	ft_door(char **rows, t_info *pic);
int		door_checker(char **rows);
int		check_coins(char **rows);
void	checking_the_line(char **lines);
void	ren_again(t_info *pic, t_posi coor, char **rows);
void	free_function(char **rows);
t_posi	ft_position(char **rows, int k);

#endif