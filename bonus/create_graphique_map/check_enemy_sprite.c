/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:59:00 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/17 00:32:16 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

/* ----------------- enmey image loop -------------*/
void	enemy_loop_if_left(t_all_list *all, int *x_e, int *y_e, int j)
{
	if (all->map->map[y_e[j]][x_e[j] - 1] == '0')
	{
		all->map->map[y_e[j]][x_e[j] - 1] = 'W';
		all->map->map[y_e[j]][x_e[j]] = '0';
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
			all->data.img_floor, x_e[j] * 50, y_e[j] * 50);
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
			all->data.img_police_left, (x_e[j] - 1) * 50, y_e[j] * 50);
		index_exit(all->map);
	}
}

/* ----------------- enmey image loop -------------*/
void	enemy_loop_if_right(t_all_list *all, int *x_e, int *y_e, int j)
{
	while (j < all->map->n_enemy)
	{
		if (all->map->map[y_e[j]][x_e[j] + 1] == 'P')
			exit(0);
		if (all->map->map[y_e[j]][x_e[j] - 1] == 'P')
			exit(0);
		if (all->map->map[y_e[j]][x_e[j] + 1] == '0')
		{
			all->map->map[y_e[j]][x_e[j] + 1] = 'W';
			all->map->map[y_e[j]][x_e[j]] = '0';
			mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
				all->data.img_floor, x_e[j] * 50, y_e[j] * 50);
			mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
				all->data.img_police_left, (x_e[j] + 1) * 50, y_e[j] * 50);
			index_exit(all->map);
		}
		else
			enemy_loop_if_left(all, x_e, y_e, j);
		if (++j < all->map->n_enemy && all->map->map[y_e[j]][x_e[j] + 1]
			== 'P')
			exit(0);
		if (j < all->map->n_enemy && all->map->map[y_e[j]][x_e[j] - 1]
			== 'P')
			exit(0);
	}
}

/* ----------------- image loop -------------------*/
int	ft_loop_img(t_all_list *all)
{
	static int	i;
	int			j;
	int			*x_e;
	int			*y_e;

	y_e = all->map->y_enemy;
	x_e = all->map->x_enemy;
	j = all->map->n_enemy;
	j = 0;
	if (i == 5000)
	{
		enemy_loop_if_right(all, x_e, y_e, j);
		i = 0;
	}
	i++;
	return (0);
}
