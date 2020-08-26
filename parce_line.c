/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:52:59 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/26 13:21:50 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_resolution(char *line, t_config *config, int *i)
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
		ft_putstr_fd("Error\nPlease, configure resolution properly\n", 2);
		exit(0);
	}
}

void		texture_path(char *line, char **path, int *i)
{
	int		buff;
	int		j;

	if (*path != NULL)
	{
		ft_putstr_fd("Error\nYou need to configure textures only once\n", 2);
		exit(0);
	}
	(*i) += 2;
	skip_spaces(line, i);
	*path = ft_strdup_cub3d(&line[*i]);
	while(line[*i] != ' ' && line[*i] != '\0')
		(*i) += 1;
	skip_spaces(line, i);
	if (path == NULL || line[*i] != '\0')
	{
		ft_putstr_fd("Error\nPlease, configure textures properly\n", 2);
		exit(0);
	}
}
