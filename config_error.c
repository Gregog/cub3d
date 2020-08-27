/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:04:22 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/27 15:16:04 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	config_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(0);
}
