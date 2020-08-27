/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:52:59 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/27 15:15:20 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_resolution(char *line, t_config *config, int *i)
{
	if (config->win.x || config->win.y)
		config_error("Error\nPlease, choose one resolution\n");
	(*i)++;
	config->win.x = ft_atoi_cub3d(line, i);
	config->win.y = ft_atoi_cub3d(line, i);
	skip_spaces(line, i);
	if (config->win.x <= 0 || config->win.y <= 0 || line[*i] != '\0')
		config_error("Error\nPlease, configure resolution properly\n");
}

void		texture_path(char *line, char **path, int *i)
{
	int		buff;
	int		j;

	if (*path != NULL)
		config_error("Error\nYou need to configure textures only once\n");
	(*i) += 2;
	skip_spaces(line, i);
	if (line[*i] != '\0' && line[*i] != ' ')
		*path = ft_strdup_cub3d(&line[*i]);
	if (!(*path))
		config_error("Error\nCheck texture path. Empty or too long\n");
	while (line[*i] != '\0' && line[*i] != ' ')
		(*i) += 1;
	skip_spaces(line, i);
	if (path == NULL || line[*i] != '\0')
		config_error("Error\nPlease, configure textures properly\n");
}

void		get_color(char *line, unsigned int *color, int *i)
{
	int r;
	int g;
	int b;

	(*i)++;
	if (*color != 0)
	{
		ft_putstr_fd("Error\nYou specified floor or ceiling color twice", 2);
		exit(0);
	}
	r = ft_atoi_cub3d(line, i);
	(*i)++;
	g = ft_atoi_cub3d(line, i);
	(*i)++;
	b = ft_atoi_cub3d(line, i);
	skip_spaces(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		config_error("Error\nPlease configure color properly");
	*color = r * 65536 + g * 256 + b;
}
