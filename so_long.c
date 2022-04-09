/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:54:32 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/09 02:01:27 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*relative_path = "./salam.xpm";
	int		img_width;
	int		img_height;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hjrifi");
	img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	mlx_key_hook(win_ptr, myF, "maroc");
	mlx_loop(mlx_ptr);
	return(0);
}

