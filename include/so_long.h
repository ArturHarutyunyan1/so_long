/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:59:00 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/13 00:59:24 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_ESC XK_Escape

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_map
{
	int		rows;
	int		cols;
}			t_map;

typedef struct s_textures
{
	void		*floor;
	void		*wall;
	void		*exit;
	void		*player;
	void		*collectable;
}			t_textures;

typedef struct s_player
{
	int		x;
	int		y;
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	int			map_width;
	int			map_height;
	int			collectables;
	int			collected;
	int			moves;
	int			x;
	int			y;
	t_player	player;
	t_textures	textures;
}			t_game;

/*
** String Manipulation Functions
*/

char			*ft_strchr(const char *str, int c);
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);

/*
** Memory Functions
*/
void			*ft_memset(void *str, int c, size_t n);
void			*ft_calloc(size_t items, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t n);

/*
** Character Classification Functions
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);

/*
** I/O Functions
*/
char			*get_next_line(int fd);

/*
** Additional Utility Functions
*/
int				get_size(char *path);
void			ft_putchar(int c);
void			ft_putnbr(int n);

/*
** Game Related Functions
*/
void			validation(int argc, char **argv);
bool			check_format(char *path);
char			**read_map(char *path);
bool			validate_map(char *path);
void			init_game(char *path);
t_map			get_dimensions(char **str);
void			draw(t_game *game, int x, int y, char c);
int				key_press(int keycode, t_game *game);
void			parse_map(t_game *game);
t_game			get_counts(char **str);
void			free_matrix(char **matrix);
void			init_textures(t_game *game);
void			destroy_textures(t_game *game);
int				exit_game(t_game *game);

#endif
