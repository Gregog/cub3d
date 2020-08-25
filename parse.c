/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:28:01 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/25 15:27:13 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_resolution(char *line, t_config *config, int *i)
{
	if (config->win.x || config->win.y)
	{
		ft_putstr_fd("Error\nPlease, choose one resolution\n", 2);
		exit(0);
	}
	(*i)++;
	config->win.x = ft_atoi_cub3d(line, i);
	config->win.y = ft_atoi_cub3d(line, i);
	skip_spaces(line, i);
	if (config->win.x <= 0 || config->win.y <= 0 || line[*i] != '\0')
	{
		ft_putstr_fd("Error\nPlease, configure resolution properly", 2);
		exit(0);
	}
	return (0);
}

int		parse_line(char *line, t_config *config)
{
	int i;

	i = 0;
	skip_spaces(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ')
		parse_resolution(line, config, &i);
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
