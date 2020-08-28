/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:11:04 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/28 19:36:53 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_borders(t_config *c)
{
	int i;
	int j;
	int last;

	i = 0;
	while (c->map.map[i])
	{
		last = c->map.m - 1;
		if (i == 0 || i == c->map.rows - 1)
		{
			j = 0;
			while (c->map.map[i][j])
			{
				if (c->map.map[i][j] == ' ' || c->map.map[i][j] == '1')
					j++;
				else
					config_error("Error\nInvalid map\n");
			}
		}
		else if (c->map.map[i][0] != ' ' && c->map.map[i][0] != '1')
			config_error("Error\nInvalid map\n");
		else if (c->map.map[i][last] != ' ' && c->map.map[i][last] != '1')
			config_error("Error\nInvalid map\n");
		i++;
	}
}

void	check_map_cells(char **map, int rows, int cols)
{
	int i;
	int	j;

	i = 1;
	while (map[i] && i < rows - 1)
	{
		j = 1;
		while (map[i][j] && j < cols - 1)
		{
			if (map[i][j] == '0')
			{
				if (map[i][j - 1] == ' ' || map[i][j + 1] == ' '
					|| map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
					config_error("Error\nInvalid Map\n");
			}
			j++;
		}
		i++;
	}
}
