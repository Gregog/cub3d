/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:28:01 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/25 17:59:37 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_line(char *line, t_config *config)
{
	int i;

	i = 0;
	skip_spaces(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ')
		parse_resolution(line, config, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		texture_path(line, &config->textures.n_path, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		texture_path(line, &config->textures.s_path, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		texture_path(line, &config->textures.w_path, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		texture_path(line, &config->textures.e_path, &i);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		texture_path(line, &config->textures.i_path, &i);
	return (0);
}

int		parse_file(char *filename, t_config *config)
{
	int		fd;
	int		r;
	char	*line;

	r = 1;
	if (!(check_file(filename)))
		exit(0);
	fd = open(filename, O_RDONLY);
	while ((r = get_next_line(fd, &line)) != 0)
	{
		if (parse_line(line, config) == -1)
			r = -1;
		free(line);
	}
	close(fd);
	if (r < 0)
	{
		ft_putstr_fd("Error\nParsing Error\n", 2);
		exit(0);
	}
	return (1);
}