/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_char_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:19:19 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/17 21:47:40 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

/* -------------- check caractire -----------------------*/
void	check_charactire_2(t_list *map, t_path data, int y, int x)
{
	if (x == 0)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_left,
			map->x, map->y);
	else if (y == 0)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_up,
			map->x, map->y);
	else if (y == map->size_height - 1)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_down,
			map->x, map->y);
	else if (map->map[y][x] == '1' )
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.img_wall_center, map->x, map->y);
	else if (map->map[y][x] == 'C')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_coin,
			map->x, map->y);
	else if (map->map[y][x] == 'W')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
			data.img_police_left, map->x, map->y);
}

/* ------------ check charactire  ------------------------ */
void	check_charactire(t_list *map, t_path data, int y, int x)
{	
	if ((x == 0 && y == 0) || (x == map->size_with - 1
			&& y == map->size_height - 1) || (y == 0 && x == map->size_with - 1)
		|| (y == map->size_height - 1 && x == 0))
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_corner,
			map->x, map->y);
	else if (x == map->size_with - 1)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_right,
			map->x, map->y);
	else
		check_charactire_2(map, data, y, x);
	if (map->map[y][x] == 'E')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_hole,
			map->x, map->y);
	if (map->map[y][x] == 'P')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_player,
			map->x, map->y);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 65, 10, 26, "move");
}

/* -------------- function put images in window -------------- */
void	put_images_in_wind(t_list *map, t_path data, int x, int y)
{
	t_all_list	*all;

	all = malloc(sizeof(t_all_list));
	all->map = map;
	all->data = data;
	map->y = 0;
	map->size_with = map->size_with - 1;
	while (y < map->size_height)
	{
		map->x = 0;
		x = 0;
		while (x < map->size_with)
		{
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_floor,
				map->x, map->y);
			check_charactire(map, data, y, x);
			map->x += 50;
			x++;
		}
		map->y += 50;
		y++;
	}
	mlx_loop_hook (data.mlx_ptr, ft_loop_img, all);
	mlx_key_hook(data.win_ptr, myf, all);
}

/*--------------- ft_data path img -------------------*/
t_path	ft_data(t_path data, t_list *map)
{
	data.win_ptr = mlx_new_window(data.mlx_ptr, (map->size_with - 1) * 50,
			map->size_height * 50, "so_long bonus");
	data.img_floor = mlx_xpm_file_to_image(data.mlx_ptr, data.path_floor,
			&(data.img_width), &(data.img_height));
	data.img_down = mlx_xpm_file_to_image(data.mlx_ptr, data.path_down,
			&(data.img_width), &(data.img_height));
	data.img_left = mlx_xpm_file_to_image(data.mlx_ptr, data.path_left,
			&(data.img_width), &(data.img_height));
	data.img_right = mlx_xpm_file_to_image(data.mlx_ptr, data.path_right,
			&(data.img_width), &(data.img_height));
	data.img_up = mlx_xpm_file_to_image(data.mlx_ptr, data.path_up,
			&(data.img_width), &(data.img_height));
	data.img_hole = mlx_xpm_file_to_image(data.mlx_ptr, data.path_hole,
			&(data.img_width), &(data.img_height));
	data.img_corner = mlx_xpm_file_to_image(data.mlx_ptr, data.path_corner,
			&(data.img_width), &(data.img_height));
	data.img_player = mlx_xpm_file_to_image(data.mlx_ptr, data.path_player,
			&(data.img_width), &(data.img_height));
	data.img_coin = mlx_xpm_file_to_image(data.mlx_ptr, data.path_coin,
			&(data.img_width), &(data.img_height));
	data.img_wall_center = mlx_xpm_file_to_image(data.mlx_ptr,
			data.path_wall_center, &(data.img_width), &(data.img_height));
	data.img_police_left = mlx_xpm_file_to_image(data.mlx_ptr,
			data.path_police_left, &(data.img_width), &(data.img_height));
	return (data);
}

/* -------------- function path images -------------- */
void	path_image(t_list *map)
{
	t_path	data;
	int		x;
	int		y;

	y = 0;
	x = 0;
	data.path_floor = "./img/floor.xpm";
	data.path_up = "./img/wall_up.xpm";
	data.path_down = "./img/wall_down.xpm";
	data.path_left = "./img/wall_left.xpm";
	data.path_right = "./img/wall_right.xpm";
	data.path_player = "./img/player.xpm";
	data.path_hole = "./img/hole.xpm";
	data.path_corner = "./img/corner.xpm";
	data.path_coin = "./img/coin.xpm";
	data.path_police_right = "./img/police_right.xpm";
	data.path_police_left = "./img/police_left.xpm";
	data.path_wall_center = "./img/wall_center.xpm";
	data.mlx_ptr = mlx_init();
	data = ft_data(data, map);
	data.img_police_right = mlx_xpm_file_to_image(data.mlx_ptr,
			data.path_police_right, &(data.img_width), &(data.img_height));
	put_images_in_wind(map, data, x, y);
	mlx_hook(data.win_ptr, 17, 0, ft_bye, "bye\n");
	mlx_loop(data.mlx_ptr);
}
