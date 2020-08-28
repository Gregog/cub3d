/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:58:50 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/28 14:35:40 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <mlx.h>

void	init_shit(t_config *config)
{
	config->win.x = 0;
	config->win.y = 0;
	config->textures.e_path = NULL;
	config->textures.i_path = NULL;
	config->textures.n_path = NULL;
	config->textures.s_path = NULL;
	config->textures.w_path = NULL;
	config->floor = 0;
	config->ceiling = 0;
	config->map.map = NULL;
	config->map.x = 0;
	config->map.y = 0;
}

void	make_config(int argc, char **argv, t_config *config)
{
	check_args(argc, argv, config);
	init_shit(config);
	if (argc == 2)
		parse_file(argv[1], config);
	if (argc == 3)
		parse_file(argv[1], config);
}

/*
void	validate_config(t_config *config)
{
	check_borders(config);
}
*/
int	main(int argc, char **argv)
{
	t_config	conf;
	char		*line;
	int			i = 0;
	int			j = 0;

	make_config(argc, argv, &conf);
	while (conf.map.map[i] != '\0')
	{
		printf("%s\n", conf.map.map[i]);
		i++;
	}
	printf("%lu\n", ft_strlen(conf.map.map[0]));
	printf("%i\n", conf.map.x);
	printf("%i\n", conf.map.y);
	// validate_config(&conf);
	printf("Windows x: %i\nWindows y: %i\n", conf.win.x, conf.win.y);
	printf("North Texture path: %s\nSouth Texture path: %s\n\
	West Texture path: %s\n\
	East Texture path: %s\n\
	Item Texture path: %s\n\
	Floor Color: %u\n\
	Ceiling Color: %u\n\n\n"\
	, conf.textures.n_path, \
	conf.textures.s_path, \
	conf.textures.w_path, \
	conf.textures.e_path, \
	conf.textures.i_path, \
	conf.floor, \
	conf.ceiling);
	return(0);
}