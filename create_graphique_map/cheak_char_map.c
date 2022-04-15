/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_char_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:19:19 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/15 03:09:33 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/** ** --------------- check_wall --------------- **/
int	check_coin(t_all_list *all, int y, int x)
{
	if (all->map->map[y][x] == 'C')
	{
		all->map->n_coin -= 1;
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
			all->data.img_floor, x * 50, y * 50);
	}
	else if (all->map->map[y][x] == 'E' && !(all->map->n_coin))
		exit(0);
	return (1);
}

/*** ----------------- move player left ---------------- */
int	move_player_left(t_all_list *all, int x, int y)
{
	while (all->map->map[y] && all->map->size_height > y)
	{
		x = 0;
		while (all->map->map[y][x] != 'P' && all->map->size_with > x)
			x++;
		if (all->map->size_with > x && all->map->map[y][x - 1] == 'E')
			check_coin(all, y, x - 1);
		if (all->map->map[y][x] == 'P' && all->map->map[y][x - 1] != '1'
			&& all->map->map[y][x - 1] != 'E')
		{
			check_coin(all, y, x - 1);
			all->map->map[y][x] = '0';
			mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
				all->data.img_floor, x * 50, y * 50);
			all->map->map[y][x - 1] = 'P';
			mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
				all->data.img_player, (x - 1) * 50, y * 50);
			return (1);
		}
		y++;
	}
	return (0);
}

/*** ----------------- move player right ---------------- */
int	move_player_right(t_all_list *all, int x, int y)
{
	while (all->map->map[y] && all->map->size_height > y)
	{
		x = 0;
		while (all->map->map[y][x] != 'P' && all->map->size_with > x)
			x++;
		if (all->map->size_with > x && all->map->map[y][x + 1] == 'E')
			check_coin(all, y, x + 1);
		if (all->map->map[y][x] == 'P' && all->map->map[y][x + 1] != '1'
			&& all->map->map[y][x + 1] != 'E')
		{
			check_coin(all, y, x + 1);
			all->map->map[y][x] = '0';
			all->map->map[y][x + 1] = 'P';
			mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
				all->data.img_floor, x * 50, y * 50);
			mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
				all->data.img_player, (x + 1) * 50, y * 50);
			return (1);
		}
		y++;
	}
	return (0);
}

/*** ----------------- move player down ---------------- */
int	move_player_down(t_all_list *all, int x, int y)
{
	while (all->map->map[y] && all->map->size_height > y)
	{
		x = 0;
		while (all->map->map[y][x] != 'P' && all->map->size_with > x)
			x++;
		if (all->map->size_with > x && all->map->map[y + 1][x] == 'E')
			check_coin(all, y + 1, x);
		if (all->map->map[y][x] == 'P' && all->map->map[y + 1][x] != '1'
			&& all->map->map[y + 1][x] != 'E')
		{
			check_coin(all, y + 1, x);
			all->map->map[y][x] = '0';
			all->map->map[y + 1][x] = 'P';
			mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
				all->data.img_floor, x * 50, y * 50);
			mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
				all->data.img_player, x * 50, (y + 1) * 50);
			return (1);
		}
		y++;
	}
	return (0);
}

/*** ----------------- move player up ---------------- */
int	move_player_up(t_all_list *all, int x, int y)
{
	while (all->map->map[y] && all->map->size_height > y)
	{
		x = 0;
		while (all->map->map[y][x] != 'P' && all->map->size_with > x)
			x++;
		if (all->map->size_with > x && all->map->map[y - 1][x] == 'E')
			check_coin(all, y - 1, x);
		if (all->map->map[y][x] == 'P' && all->map->map[y - 1][x] != '1'
			&& all->map->map[y - 1][x] != 'E')
		{
			check_coin(all, y - 1, x);
			all->map->map[y][x] = '0';
			all->map->map[y - 1][x] = 'P';
			mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
				all->data.img_floor, x * 50, (y) * 50);
			mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
				all->data.img_player, x * 50, (y - 1) * 50);
			return (1);
		}
		y++;
	}
	return (0);
}

/*** ----------------- function read movement ---------------- */
int	myf(int key, t_all_list *all)
{
	static long	n;
	long long	n_move;
	int			x;
	int			y;

	y = 0;
	x = 0;
	n_move = 0;
	if (key == 0)
		n_move += move_player_left(all, x, y);
	else if (key == 2)
		n_move += move_player_right(all, x, y);
	else if (key == 1)
		n_move += move_player_down(all, x, y);
	else if (key == 13)
		n_move += move_player_up(all, x, y);
	else if (key == 53)
		exit(0);
	if (n_move == 1)
	{
		n += n_move;
		ft_putnbr(n);
		write(1, "\n", 1);
	}
	return (n);
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
	else if (x == 0)
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
	if (map->map[y][x] == 'E')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_hole,
			map->x, map->y);
	if (map->map[y][x] == 'P')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_player,
			map->x, map->y);
}

/* -------------- function put images in window -------------- */
void	put_images_in_wind(t_list *map, t_path data)
{
	int			y;
	int			x;
	t_all_list	*all;

	all = malloc(sizeof(t_all_list));
	all->map = map;
	all->data = data;
	y = 0;
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
	mlx_key_hook(data.win_ptr, myf, all);
	mlx_loop(data.mlx_ptr);
}

/* -------------- function path images -------------- */
void	path_image(t_list *map)
{
	t_path	data;

	data.path_floor = "./img/floor.xpm";
	data.path_up = "./img/wall_up.xpm";
	data.path_down = "./img/wall_down.xpm";
	data.path_left = "./img/wall_left.xpm";
	data.path_right = "./img/wall_right.xpm";
	data.path_player = "./img/player.xpm";
	data.path_hole = "./img/hole.xpm";
	data.path_corner = "./img/corner.xpm";
	data.path_coin = "./img/coin.xpm";
	data.path_wall_center = "./img/wall_center.xpm";
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, (map->size_with - 1) * 50, map->size_height * 50, "So_long");
	data.img_floor = mlx_xpm_file_to_image(data.mlx_ptr, data.path_floor, &(data.img_width), &(data.img_height));
	data.img_down = mlx_xpm_file_to_image(data.mlx_ptr, data.path_down, &(data.img_width), &(data.img_height));
	data.img_left = mlx_xpm_file_to_image(data.mlx_ptr, data.path_left, &(data.img_width), &(data.img_height));
	data.img_right = mlx_xpm_file_to_image(data.mlx_ptr, data.path_right, &(data.img_width), &(data.img_height));
	data.img_up = mlx_xpm_file_to_image(data.mlx_ptr, data.path_up, &(data.img_width), &(data.img_height));
	data.img_hole = mlx_xpm_file_to_image(data.mlx_ptr, data.path_hole, &(data.img_width), &(data.img_height));
	data.img_corner = mlx_xpm_file_to_image(data.mlx_ptr, data.path_corner, &(data.img_width), &(data.img_height));
	data.img_player = mlx_xpm_file_to_image(data.mlx_ptr, data.path_player, &(data.img_width), &(data.img_height));
	data.img_coin = mlx_xpm_file_to_image(data.mlx_ptr, data.path_coin, &(data.img_width), &(data.img_height));
	data.img_wall_center = mlx_xpm_file_to_image(data.mlx_ptr, data.path_wall_center, &(data.img_width), &(data.img_height));
	put_images_in_wind(map, data);
}

/* -------------- put index door exit in arrary --------*/
void	index_exit(t_list *map, int n)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	map->x_exit = malloc(sizeof(int) * n);
	map->y_exit = malloc(sizeof(int) * n);
	while (y < map->size_height)
	{
		x = 0;
		while (x < map->size_with)
		{
			if (map->map[y][x] == 'E')
			{
				map->x_exit[i] = x;
				map->y_exit[i++] = y;
			}
			x++;
		}
		y++;
	}	
}

/** -------------- function calcul coin --------------*/
int	ft_calcul_coin(t_list *map)
{
	int	n;
	int	y;
	int	x;

	y = 0;
	n = 0;
	map->n_coin = 0;
	map->n_hole = 0;
	while (y < map->size_height)
	{
		x = 0;
		while (x < map->size_with)
		{
			if (map->map[y][x] == 'C')
				map->n_coin += 1;
			if (map->map[y][x] == 'E')
				map->n_hole += 1;
			x++;
		}
		y++;
	}
	index_exit(map, n);
	return (n);
}

/* ------------- create map --------------- */
void	create_map(int fd, t_list *map)
{
	int		i;
	int		n;

	i = 0;
	n = map->size_height;
	map->map = malloc(sizeof(char *) * n + 1);
	while (n > i)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	ft_calcul_coin(map);
	path_image(map);
}
