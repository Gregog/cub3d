/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:49:06 by rvernius          #+#    #+#             */
/*   Updated: 2020/09/08 14:14:23 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "v_types.h"
#include <math.h>

double	get_distance(t_vector2 start, t_vector2 end)
{
	t_vector2	diff;

	diff = new_vector2(start.x - end.x, start.y - end.y);
	return (sqrt(diff.x * diff.x + diff.y * diff.y));
}
