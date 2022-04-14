/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:58:12 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/14 08:02:26 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/*---------------- function check type map if __.ber ---------*/
void check_type_map(char *name_map, int fd)
{
	int		i;
	char	*tab;
	int		j;

	j = 0;
	tab = ft_strdup("reb.");
	i = ft_strlen(name_map) - 1;
	while (name_map[i--] == tab[j++]);
	if(tab[j] != '\0')
	{
		ft_error(4, "cheack type file map\n");
		free (tab);
		return ;
	}
	free(tab);
	close(fd);
}

void	ft_putnbr(long nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		nbr = nbr + 48;
		write(1, &nbr, 1);
	}
}
