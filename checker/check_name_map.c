/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:58:12 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/18 00:48:28 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/*---------------- function check type map if __.ber ---------*/
void	check_type_map(char *name_map, int fd)
{
	int		i;
	char	*tab;
	int		j;
	int		k;

	j = 0;
	k = 0;
	tab = ft_strdup("reb.");
	i = ft_strlen(name_map) - 1;
	while (name_map[i--] == tab[j++])
		k++;
	if (tab[j] != '\0')
	{
		ft_error("cheack type file map\n");
		free (tab);
		return ;
	}
	free(tab);
	close(fd);
}

/* --------------- ft_putnbr -----------*/
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

//--------  check arguments ---------/
void	check_arg(int ac, int fd, int line_map)
{
	int		i;
	int		n_check;

	i = 0;
	n_check = 0;
	if (ac == 1)
		ft_error("add map \n");
	else if (ac > 2)
		ft_error("args require a map only \n");
	else if (fd < 0)
		ft_error("map can not be readed\n");
	check_map(fd, line_map, n_check, i);
}

//*---------- check if any other character in map ------------/
int	check_character(char *ptr)
{
	int		i;
	int		j;
	char	*cha_map;
	int		n;

	cha_map = ft_strdup("1ECP0");
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
	{
		n = 0;
		j = 0;
		while (cha_map[j])
		{
			if (cha_map[j] == ptr[i])
				n++;
			j++;
		}
		if (n == 0)
			return (1);
		i++;
	}
	free(cha_map);
	return (0);
}
