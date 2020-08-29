/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:31:38 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/29 19:02:02 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define PI 3.141592
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct	s_map
{
	char	**map;
	int		x;
	int		y;
	int		rows;
	int		m;
}				t_map;

typedef struct	s_textures
{
	char *n_path;
	char *s_path;
	char *w_path;
	char *e_path;
	char *i_path;
}				t_textures;

typedef	struct	s_player_pos
{
	int		x;
	int		y;
	double	dir;
}				t_player_pos;

typedef	struct	s_win
{
	int		x;
	int		y;
	void	*win;
}				t_win;

typedef	struct	s_config
{
	void				*mlx;
	t_win				win;
	t_textures			textures;
	t_map				map;
	t_player_pos		player;
	unsigned int		floor;
	unsigned int		ceiling;
	int					save;
}				t_config;


char			*ft_strdup_cub3d(char *str);
void			check_args(int argc, char **argv, t_config *config);
int				is_space(int c);
int				check_extension(char *filename, char *extension);
int				check_file(char *filename);
int				skip_spaces(char *line, int *i);
int				ft_atoi_cub3d(char *line, int *i);
int				parse_file(char *filename, t_config *config);
void			get_color(char *line, unsigned int *color, int *i);
void			parse_resolution(char *line, t_config *config, int *i);
void			texture_path(char *line, char **path, int *i);
void			get_map(t_config *s, char *line);
void			config_error(char *message);
void			check_borders(t_config *config);
void			check_map_cells(char **map, int rows, int cols);
void			feel_map_with_love(t_config *conf);
void			get_player_pos(t_config *con, char **map, int rows, int cols);
void			check_window_resolution(t_config *config);
void			final_validation(t_config *c);
void			make_screen(t_config *config);
#endif
