/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:13:25 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/18 00:27:39 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_split(int fd, t_list **map)
{
	int		i;
	char	*ptr;

	ptr = get_next_line(fd);
	if (!ptr)
		ft_error("The map is empty\n");
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
