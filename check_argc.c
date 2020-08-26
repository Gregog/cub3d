/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernius <rvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:20:24 by rvernius          #+#    #+#             */
/*   Updated: 2020/08/26 19:36:46 by rvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_args(int argc, char **argv, t_config *config)
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error\nWrong amount of args\n", 2);
		exit(0);
	}
	else if ((argc == 2 && (!(check_extension(argv[1], "cub") \
			|| (argc == 3 && (!(check_extension(argv[2], "cub"))))))))
	{
		ft_putstr_fd("Error\nWrong extenstion\n", 2);
		exit(0);
	}
	else if (argc == 3)
	{
		if ((ft_strncmp(argv[1], "--save", ft_strlen(argv[2])) != 0))
		{
			ft_putstr_fd("Error\nOnly --save option is available\n", 2);
			exit(0);
		}
		else
			config->save = 1;
	}
}

int		check_file(char *filename)
{
	int fd;
	int res;

	res = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 1)
	{
		ft_putstr_fd("Error\nFile doesn't exists\n", 2);
		res = 0;
	}
	close(fd);
	return (res);
}
