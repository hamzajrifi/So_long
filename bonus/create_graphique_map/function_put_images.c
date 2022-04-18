/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_put_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:01:09 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/18 01:18:20 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	put_images(t_list *map, t_path data, int x, int y)
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
}
