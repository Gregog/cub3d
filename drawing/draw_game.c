/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:04:40 by rvernius          #+#    #+#             */
/*   Updated: 2020/09/08 14:22:58 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "cub.h"
#include <stdio.h>
#include "v_types.h"

static void	draw_map(t_game *game)
{
	t_ivector2	pos;
	t_vector2	start;
	t_vector2	end;
	int			wall_color;
	int			size;

	size = 500 / game->config.map.m > game->config.map.rows ?
			game->config.map.m : game->config.map.rows;
	pos.y = -1;
	while ((size_t)(++pos.y) < game->config.map.rows)
	{
		pos.x = -1;
		while ((size_t)(++pos.x) < game->config.map.m)
		{
			if (game->config.map.map[pos.y][pos.x] > 0 && game->config.map.rows)
			{
				start = new_vector2(pos.x * size, pos.y * size);
				end = new_vector2((pos.x + 1) * size, (pos.y + 1) * size);
				wall_color = game->config.map.map[pos.y][pos.x] == 1 ?
									0x00FF0000 : 0x000000FF;
				draw_rect_filled(game, start, end, wall_color);
				draw_rect(game, start, end, 0x00FFFFFF);
			}
		}
	}
}

static void	draw_sprites(char **map, t_game *game, t_ivector2 map_size)
{
	t_display_params	params;
	t_sprite			*sprites;
	int					i;

	params.source.img = mlx_xpm_file_to_image(game->vars.mlx,
		game->config.textures.i_path, &params.source.size.x,
			&params.source.size.y);
	if (!(sprites = malloc(sizeof(t_sprite) * game->sprites_count)))
		game_exit(20, game);
	setup_sprite_array(map, game, map_size, &sprites);
	i = -1;
	while (++i < game->sprites_count - 1)
	{
		if (sprites[i].distance < sprites[i + 1].distance)
		{
			swap_sprites(&(sprites[i]), &(sprites[i + 1]));
			i = 0;
		}
	}
	i = -1;
	while (++i < game->sprites_count)
		draw_sprite(params, game, sprites[i]);
	free(game->depth_buffer);
	game->depth_buffer = NULL;
	free(sprites);
}

static void	draw_skybox(t_win win, t_game *game)
{
	t_vector2	sky_start;
	t_vector2	sky_end;
	t_vector2	floor_start;
	t_vector2	floor_end;

	sky_start = new_vector2(0, 0);
	sky_end = new_vector2(win.x, win.y / 2);
	floor_start = new_vector2(0, win.y / 2);
	floor_end = new_vector2(win.x, win.y);
	draw_rect_filled(game, sky_start, sky_end, game->config.ceiling);
	draw_rect_filled(game, floor_start, floor_end, game->config.floor);
}

int			draw_frame(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->vars.mlx, game->img.img);
	game->img.img = mlx_new_image(game->vars.mlx,
		game->config.win.x, game->config.win.y);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
									&game->img.line_length, &game->img.endian);
	draw_skybox(game->config.win, game);
	cast_rays(game->player, game->rays_count, game);
	if (game->map_active)
		draw_map(game);
	draw_sprites(game->config.map.map, game,
		new_ivector2(game->config.map.m, game->config.map.rows));
	mlx_do_sync(game->vars.mlx);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
							game->img.img, 0, 0);
	return (0);
}
