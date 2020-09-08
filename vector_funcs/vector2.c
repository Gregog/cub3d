/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:46:36 by rvernius          #+#    #+#             */
/*   Updated: 2020/09/08 14:14:23 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_types.h"

t_vector2	new_vector2(double x, double y)
{
	t_vector2 new_vector;

	new_vector.x = x;
	new_vector.y = y;
	return (new_vector);
}

t_ivector2	new_ivector2(int x, int y)
{
	t_ivector2 new_vector;

	new_vector.x = x;
	new_vector.y = y;
	return (new_vector);
}
