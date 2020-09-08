/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:59:52 by rvernius          #+#    #+#             */
/*   Updated: 2020/09/08 14:14:23 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int		get_map_len(t_config *config, char *line)
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
	if (config->map.x != 0 && i != count)
		return (-1);
	return (count);
}

static char		*copy_map_line(t_config *config, char *line)
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
			copy[j++] = line[i];
		}
		i++;
	}
	copy[j] = '\0';
	return (copy);
}

void			get_map(t_config *con, char *line)
{
	char	**tmp;
	int		j;

	if (!(tmp = malloc(sizeof(char *) * (con->map.y + 2))))
		config_exit(20, con);
	j = -1;
	while (++j < con->map.y)
		tmp[j] = con->map.map[j];
	if ((tmp[con->map.y] = copy_map_line(con, line)) == NULL)
	{
		free(tmp);
		config_exit(21, con);
	}
	con->map.rows += 1;
	con->map.m = ft_strlen(line) > con->map.m ? ft_strlen(line) : con->map.m;
	tmp[con->map.y + 1] = NULL;
	if (con->map.y > 0)
		free(con->map.map);
	con->map.map = tmp;
	con->map.y++;
	if ((con->map.x = get_map_len(con, line)) == -1)
		config_exit(21, con);
}

void			fill_map(t_config *conf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (conf->map.map[i])
	{
		while (ft_strlen(conf->map.map[i]) < conf->map.m)
		{
			if (!(conf->map.map[i] = ft_strjoin_gnl(conf->map.map[i], " ")))
				config_exit(20, conf);
		}
		i++;
	}
}
