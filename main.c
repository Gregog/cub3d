/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:58:50 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/29 17:11:22 by rvernius         ###   ########.fr       */
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
	config->map.rows = 0;
	config->map.m = 0;
	config->player.x = 0;
	config->player.y = 0;
	config->mlx = NULL;
	config->win.win = NULL;
}

void	make_config(int argc, char **argv, t_config *config)
{
	check_args(argc, argv, config);
	init_shit(config);
	if (argc == 2)
		parse_file(argv[1], config);
	if (argc == 3)
		parse_file(argv[1], config);
	config->mlx = mlx_init();
	if (!config->mlx)
		config_error("Error\nFailed to init mlx\n");
}

void	validate_config(t_config *config)
{
	feel_map_with_love(config);
	check_window_resolution(config);
	check_borders(config);
	check_map_cells(config->map.map, config->map.rows, config->map.m);
	get_player_pos(config, config->map.map, config->map.rows, config->map.m);
	//config->win.win = mlx_new_window(config->mlx, config->win.x,
	//								config->win.y, "Cub3D");
	//if (!config->win.win)
	//	config_error("Error\nFailed to init window.\n");
}

int	main(int argc, char **argv)
{
	t_config	conf;
	char		*line;
	int			i = 0;
	int			j = 0;

	make_config(argc, argv, &conf);
	validate_config(&conf);
	printf("Windows x: %i\nWindows y: %i\n", conf.win.x, conf.win.y);
	printf("North Texture path: %s\nSouth Texture path: %s\n\
	West Texture path: %s\n\
	East Texture path: %s\n\
	Item Texture path: %s\n\
	Floor Color: %u\n\
	Ceiling Color: %u\n "
	, conf.textures.n_path, \
	conf.textures.s_path, \
	conf.textures.w_path, \
	conf.textures.e_path, \
	conf.textures.i_path, \
	conf.floor, \
	conf.ceiling);
	printf("Player pos |x, y|: |%i, %i|\n", conf.player.x, conf.player.y);
	printf("Player dir: %f\n\n\n", conf.player.dir);
	while (conf.map.map[i] != '\0')
	{
		printf("%s\n", conf.map.map[i]);
		i++;
	}
	//mlx_loop(conf.mlx);
	return (0);
}
