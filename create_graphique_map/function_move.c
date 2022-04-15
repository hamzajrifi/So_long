/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 05:55:24 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/15 06:04:04 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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
