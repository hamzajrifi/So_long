/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:54:32 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/10 15:18:52 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	myF(int key, void *n)
{
	if (key == 53)
		exit(0);
	return 0;
}

int main(int ac, char **av)
{
	///**** variables ***//
	char	*ptr;
	int		fd;
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
	

	/******/
	fd = open(av[1], O_RDWR);
	check_arg(ac, fd);
	
	/******/
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hjrifi");
	img_up = mlx_xpm_file_to_image(mlx_ptr, path_up, &img_width, &img_height);
	img_down = mlx_xpm_file_to_image(mlx_ptr, path_down, &img_width, &img_height);
	img_left = mlx_xpm_file_to_image(mlx_ptr, path_left, &img_width, &img_height);
	img_right = mlx_xpm_file_to_image(mlx_ptr, path_right, &img_width, &img_height);
	img_player = mlx_xpm_file_to_image(mlx_ptr, path_player, &img_width, &img_height);
	img_wall_center = mlx_xpm_file_to_image(mlx_ptr, path_wall_center, &img_width, &img_height);
	
	//// read map
	i = 0;
	j = 0;
	l = 0;
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_up, i, j);
	
	mlx_key_hook(win_ptr, myF, "maroc");
	mlx_loop(mlx_ptr);
	return(0);
}

