/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:06:06 by malaamir          #+#    #+#             */
/*   Updated: 2025/01/12 13:29:59 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE_SIZE
#  define TILE_SIZE 75
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_map
{
	void	*mlx;
	void	*win;
	void	*img_floor;
	void	*img_wall;
	void	*img_exit;
	void	*img_collectible;
	void	*img_player;
	int		img_width;
	int		img_height;
	int		width;
	int		height;
	char	**data;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		movements;
}		t_map;

void	free_map(t_map *map);
void	destroy_images(t_map *map);
void	display_error(const char *msg);
t_map	*read_map(const char *file_path);
int		move_player(t_map *map, int new_x, int new_y);
void	remaining_collectible(t_map *map, int new_x, int new_y);
int		check_exit(t_map *map, int new_x, int new_y);
int		key_hook(int keycode, t_map *vars);
void	draw_map(t_map *map);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_joinfree(char *buffer, char *new_buffer);
char	*get_remaning(char *buffer);
char	*ft_getline(char *buffer);
char	*read_from_file(int fd, char *buffer);
char	*get_next_line(int fd);
int		check_map_shape(t_map *map);
int		check_walls(t_map *map);
int		close_window(t_map *map);
int		ft_printf(const char *format, ...);
void	ft_putchar_printf(char c, size_t *count);
void	ft_putstr_printf(char *s, size_t *count);
void	ft_putnbr_printf(int nbr, size_t *count);
int		ft_strcmp(const char *s1, const char *s2);
void	load_images(t_map *map);
int		check_map_extension(const char *file_path);
void	display_error(const char *msg);
void	init_player_pos(t_map *map);
void	init_game(int ac, char **av, t_map *map);
int		check_path(t_map *map);
int		check_player_and_exit(t_map *map);
void	free_visited(int **visited, t_map *map);
void	put_image(t_map *map, int x, int y, void *img);
void	validate_map(t_map *map);
int		check_collectibles(t_map *map);
void	check_unknown_characters(t_map *map);

#endif