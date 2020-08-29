/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:36:39 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/29 17:55:09 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	final_validation(t_config *c)
{
	if (!c->win.x || !c->win.y)
		config_error("Error\nResolution is not specified\n");
	if (!c->textures.e_path || !c->textures.i_path
		|| !c->textures.n_path || !c->textures.s_path || !c->textures.w_path)
		config_error("Error\nOne of the textures wasn't specified\n");
	if (!*c->map.map || !c->map.map)
		config_error("Error\nMap wasn't specified\n");
	if (!c->player.x)
		config_error("Error\nPlayer wasn't specified\n");
	if (!c->floor)
		config_error("Error\nFloor wasn't specified\n");
	if (!c->ceiling)
		config_error("Error\nCeiling wasn't specified\n");
}