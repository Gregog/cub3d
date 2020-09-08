/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:16:09 by rvernius          #+#    #+#             */
/*   Updated: 2020/09/08 14:14:23 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

double			local_abs(double x)
{
	return (x > 0 ? x : -x);
}

int				same_value(double x, double y)
{
	if (local_abs(x - y) < 0.0001)
		return (1);
	return (0);
}
