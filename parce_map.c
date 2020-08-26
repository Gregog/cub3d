/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:59:52 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/26 17:01:31 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		len_map_line(char *line)
{
	int i;

	i = 0;
	if (!*line)
		return (0);
	while (line[i] == ' ' || line[i] == '1' || \
			line[i] == '2' || line[i] == '0' || \
			line[i] == 'N' || line[i] == 'S' || \
			line[i] == 'E' || line[i] == 'W')
		i++;
	if (i == ft_strlen(line))
		return (i);
	ft_putstr_fd("Error\nMap contains invalid symbols.\n", 2);
	exit(0);
}




void	get_map(t_config *config, char *line)
{
	if (config.map != NULL)

}