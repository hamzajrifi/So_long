/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:40 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/12 01:07:35 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//--------  check argiment ---------/
void	check_arg(int ac, char **av,int fd)
{
	if (ac == 1)
		ft_error(1);
	else if (ac > 2)
		ft_error(2);
	else if (fd < 0)
		ft_error(3);
}

//--------  main  ---------/
int	main(int ac, char **av)
{
	int		fd;
	char	*ptr;
	t_list	*map_data;
	
	/***-- done --***/
	fd = open(av[1], O_RDWR);
	//check_arg(ac, av, fd);
	/*** -- en coure -- ***/
	map_data = check_map(fd, av[1]);
	map_data->i = 0;
	//while (map_data->map[map_data->i])
	//{
	//	printf("map = %s", map_data->map[map_data->i++]);
	//}
	
	
	return (0);
}
