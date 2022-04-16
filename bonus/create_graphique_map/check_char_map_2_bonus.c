/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_map_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 05:59:32 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/16 06:45:56 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

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
	else if (all->map->map[y][x] == 'W')
		exit(0);
	return (1);
}

/* -------------- put index door exit in arrary --------*/
void	index_exit(t_list *map)
{
	int			y;
	int			x;
	int			i;
	int			j;
	static int	k;

	i = 0;
	j = 0;
	y = 0;
	if (k == 0)
	{
		map->x_exit = malloc(sizeof(int) * map->n_hole);
		map->y_exit = malloc(sizeof(int) * map->n_hole);
		map->x_enemy = malloc(sizeof(int) * map->n_enemy);
		map->y_enemy = malloc(sizeof(int) * map->n_enemy);
		k++;
	}
	while (y < map->size_height)
	{
		x = 0;
		while (x < map->size_with)
		{
			if (map->map[y][x] == 'E' && k == 1)
			{
				map->x_exit[i] = x;
				map->y_exit[i++] = y;
			}
			if (map->map[y][x] == 'W')
			{
				map->x_enemy[j] = x;
				map->y_enemy[j++] = y;
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
	map->n_enemy = 0;
	while (y < map->size_height)
	{
		x = 0;
		while (x < map->size_with)
		{
			if (map->map[y][x] == 'C')
				map->n_coin += 1;
			if (map->map[y][x] == 'E')
				map->n_hole += 1;
			if (map->map[y][x] == 'W')
				map->n_enemy += 1;
			x++;
		}
		y++;
	}
	index_exit(map);
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
