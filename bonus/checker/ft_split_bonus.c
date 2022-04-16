/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:13:25 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/16 07:28:24 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

/* ------------ calcule size height map --------*/
void	ft_split(int fd, t_list **map)
{
	int		i;
	char	*ptr;

	ptr = get_next_line(fd);
	if (!ptr)
		ft_error("map it's empty");
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

/* ---------------- ft_itoi ---------------- */

char	*ft_itoi(int nbr)
{
	int	n;
	int	i;
	
	i = 0;
	n = nbr;
	while (n > 0)
	{
		n /= 10 ;
		i++;
	}
	while(i > 0)
	{
		
	}
}