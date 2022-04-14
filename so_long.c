/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:54:32 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/13 20:37:28 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"



int main(int ac, char **av)
{
	///**** variables ***//
	char	*ptr;
	int		fd;
	int		line_map;
	t_list	*data_map;
	/*** en variable **/
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_up;
	void	*img_down;
	void	*img_left;
	void	*img_right;
	void	*img_player;
	void	*img_wall_center;
	char	*path_up = "./img/wall_up.xpm";
	char	*path_down = "./img/wall_down.xpm";
	char	*path_left = "./img/wall_left.xpm";
	char	*path_right = "./img/wall_right.xpm";
	char	*path_player = "./img/player.xpm";
	char	*path_wall_center = "./img/wall_center.xpm";
	int		img_width;
	int		img_height;
	int		i, j, l;
	(void)	ac;
	
	data_map = malloc(sizeof(t_list));
	/**** --- done ---****/
	fd = open(av[1], O_RDWR);
	ft_split(fd, &data_map);
	fd = open(av[1], O_RDWR);
	check_arg(ac, fd, data_map->size_height);
	check_type_map(av[1], fd);
	/*** --- en cours --- ***/
	printf("with = %d \n", data_map->size_with);
	printf("height = %d \n", data_map->size_height);
	printf("-----------------------\n");
	fd = open(av[1], O_RDWR);
	
	create_map(fd, data_map);
	/******/

	//// read map

	return(0);
}
