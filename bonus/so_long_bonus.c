/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:54:32 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/17 21:58:26 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	main(int ac, char **av)
{
	int		fd;
	t_list	*data_map;

	data_map = malloc(sizeof(t_list));
	fd = open(av[1], O_RDWR);
	ft_split(fd, &data_map);
	fd = open(av[1], O_RDWR);
	check_arg(ac, fd, data_map->size_height);
	check_type_map(av[1], fd);
	fd = open(av[1], O_RDWR);
	create_map(fd, data_map);
	return (0);
}
