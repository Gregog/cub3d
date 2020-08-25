/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:58:50 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/25 15:41:43 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_config conf;
	void *mlx;
	void *win;

	mlx = mlx_init();
	if (check_args(argc, argv, &conf))
		parse_file(argv[1], &conf);
	win = mlx_new_window(mlx, conf.win.x, conf.win.y, "Check");
	printf("Windows x: %i\nWindows y: %i\n", conf.win.x, conf.win.y);
	mlx_loop(mlx);

	return (0);
}