/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:22:46 by rvernius          #+#    #+#             */
/*   Updated: 2020/09/08 14:14:23 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include "v_types.h"
#include "cub.h"
#include "keys.h"
#include "x11_events.h"
#include "cub.h"
#include "libft.h"

static void	convert_map_to_i(char ***map, size_t height,
						size_t width, int *sprites_count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int)height)
	{
		j = -1;
		while (++j < (int)width)
		{
			(*map)[i][j] -= (int)'0';
			if ((*map)[i][j] == 2)
				++(*sprites_count);
			if ((*map)[i][j] == -16)
				(*map)[i][j] += 17;
		}
	}
}

static void	init_game(t_game *game)
{
	game->vars.win = NULL;
	if (!(game->vars.win = mlx_new_window(game->vars.mlx, game->config.win.x,
								game->config.win.y, "Bonk")))
		game_exit(11, game);
	game->map_active = 0;
	game->rays_count = RAYS_COUNT;
	game->player.pos = new_vector2(
	game->config.player.x * GRID_SIZE + (float)GRID_SIZE / 2,
	game->config.player.y * GRID_SIZE + (float)GRID_SIZE / 2);
	game->img.img = NULL;
	game->player.rotation = game->config.player.dir;
	game->player.run = 0;
}

static void	setup_hooks(t_game *game)
{
	mlx_loop_hook(game->vars.mlx, draw_frame, game);
	mlx_hook(game->vars.win, KEY_PRESS, KEY_PRESS_MASK, move_player, game);
	mlx_hook(game->vars.win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK,
			cross_exit, game);
}

static void	make_screenshot(t_game *game)
{
	draw_frame(game);
	save_bmp(game->config.win.x, game->config.win.y, game->img.addr);
	game_exit(0, game);
}

int			main(int argc, char **argv)
{
	t_game		game;
	int			line_width;
	t_ivector2	screen_size;

	game.vars.mlx = NULL;
	make_config(argc, argv, &game);
	validate_config(&game);
	if (!(game.vars.mlx = mlx_init()))
		game_exit(11, &game);
	init_game(&game);
	convert_map_to_i(&game.config.map.map, game.config.map.rows,
					game.config.map.m, &game.sprites_count);
	screen_size = new_ivector2(game.config.win.x, game.config.win.y);
	while (!same_value((float)screen_size.x / (float)game.rays_count,
			(int)((float)screen_size.x / (float)game.rays_count)))
		--game.rays_count;
	line_width = (int)round((float)screen_size.x / (float)game.rays_count);
	if (game.config.save)
		make_screenshot(&game);
	setup_hooks(&game);
	mlx_loop(game.vars.mlx);
	return (0);
}
