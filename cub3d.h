/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:31:38 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/28 13:45:07 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct	s_map
{
	char	**map;
	int		x;
	int		y;
	int		sprites;
}				t_map;

typedef struct	s_textures
{
	char *n_path;
	char *s_path;
	char *w_path;
	char *e_path;
	char *i_path;
}				t_textures;

typedef	struct	s_win
{
	int	x;
	int	y;
}				t_win;

typedef	struct	s_config
{
	t_win				win;
	t_textures			textures;
	t_map				map;
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

#endif
