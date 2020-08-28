/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:59:52 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/28 15:33:16 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_map_len(t_config *config, char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2' ||\
			line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||\
			line[i] == 'E' || line[i] == ' ')
			count++;
		i++;
	}
	//printf("%i\n", config->map.x);
	//printf("%i\n", count);
	if (config->map.x != 0 && i != count)
		return (-1);
	return (count);
}

char		*copy_map_line(t_config *config, char *line)
{
	char	*copy;
	int		j;
	int		i;

	if (!(copy = malloc(sizeof(char) * (get_map_len(config, line) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == '0' || line[i] == '1' || line[i] == 'N')
			|| (line[i] == 'E' || line[i] == 'S' || line[i] == 'W'
			|| (line[i] == '2')))
			copy[j++] = line[i];
		else if (line[i] == ' ')
		{
			copy[j++] = '1';
		}
		i++;
	}
	copy[j] = '\0';
	return (copy);
}

void		get_map(t_config *config, char *line)
{
	char	**tmp;
	int		j;

	if (!(tmp = malloc(sizeof(char *) * (config->map.y + 2))))
		config_error("Error\nError while saving map.");
	j = -1;
	while (++j < config->map.y)
		tmp[j] = config->map.map[j];
	if ((tmp[config->map.y] = copy_map_line(config, line)) == NULL)
	{
		free(tmp);
		config_error("Error\nInvalid map\n");
	}
	config->map.rows += 1;
	tmp[config->map.y + 1] = NULL;
	if (config->map.y > 0)
		free(config->map.map);
	config->map.map = tmp;
	config->map.y++;
	if ((config->map.x = get_map_len(config, line)) == -1)
		config_error("Error\nInvalid map\n");
}
