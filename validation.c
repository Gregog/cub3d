/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:11:04 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/28 15:51:29 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_borders(t_config *config)
{
	int i;
	int j;
	int last_index;

	i = 0;

	while (config->map.map[i])
	{
		last_index = ft_strlen(config->map.map[i]) - 1;
		if (i == 0 || i == config->map.rows - 1)
		{
			j = 0;
			while (config->map.map[i][j])
			{
				if (config->map.map[i][j] != '1')
					config_error("Error\nInvalid map\n");
				j++;
			}
		}
		else if (config->map.map[i][0] != '1' ||
				config->map.map[i][last_index] != '1')
			config_error("Error\nInvalid map\n");
		i++;
	}
}
