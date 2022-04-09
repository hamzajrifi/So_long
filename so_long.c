/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:54:32 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/09 21:26:27 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "./get_next_line/get_next_line.h"

int	myF(int key, void *n)
{
	
	if (key == 0)
		write(1, "<==\n", 5);
	else if (key == 13)
		write(1, "^\n", 3);
	else if (key == 2)
		write(1, "==>\n", 5);
	else if (key == 1)
		write(1, "\\/\n", 4);
	else if (key == 53)
		exit(0);
	return 0;
}

int main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_up;
	void	*img_down;
	void	*img_left;
	void	*img_right;
	void	*img_player;
	char	*path_up = "./img/wall_up.xpm";
	char	*path_down = "./img/wall_down.xpm";
	char	*path_left = "./img/wall_left.xpm";
	char	*path_right = "./img/wall_right.xpm";
	char	*path_player = "./img/player.xpm";
	int		img_width;
	int		img_height;
	int		i, j, l;
	int		fd;
	(void)	ac;
	char	*ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hjrifi");
	img_up = mlx_xpm_file_to_image(mlx_ptr, path_up, &img_width, &img_height);
	img_down = mlx_xpm_file_to_image(mlx_ptr, path_down, &img_width, &img_height);
	img_left = mlx_xpm_file_to_image(mlx_ptr, path_left, &img_width, &img_height);
	img_right = mlx_xpm_file_to_image(mlx_ptr, path_right, &img_width, &img_height);
	img_player = mlx_xpm_file_to_image(mlx_ptr, path_player, &img_width, &img_height);
	
	//// read map
	fd = open(av[1], O_RDWR);
	ptr = get_next_line(fd);
	i = 0;
	j = 0;
	l = 0;
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_up, i, j);
	while(ptr[0] == '\n')
	{
		ptr = get_next_line(fd);
	}
	write(1, ptr, ft_strlen(ptr));
	i = 0;
	while (ptr[i] != '\0')
	{
			write(1, &ptr[i], 1);
		if (ptr[i] == '1')
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_up, l, j);
		}
		else if (ptr[i] == '0')
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_player, l, j);
		}
		else if (ptr[i] == '\n')
		{
			ptr = get_next_line(fd);
			if (!ptr)
				break;
			write(1, "-n-\n", 5);
			i = 0;
		}
		l += 50;
		i++;
	}
	
	mlx_key_hook(win_ptr, myF, "maroc");
	mlx_loop(mlx_ptr);
	return(0);
}

