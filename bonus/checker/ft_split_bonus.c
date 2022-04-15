/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:13:25 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/15 07:55:05 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

/* ------------ calcule size height map --------*/
void	ft_split(int fd, t_list **map)
{
	int		i;
	char	*ptr;

	ptr = get_next_line(fd);
	(*map)->size_with = ft_strlen(ptr);
	i = 0;
	while (ptr)
	{
		free(ptr);
		ptr = get_next_line(fd);
		i++;
	}
	close(fd);
	(*map)->size_height = i;
}
