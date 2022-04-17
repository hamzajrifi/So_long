/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:13:25 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/17 01:06:06 by hjrifi           ###   ########.fr       */
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

static int	ft_nchar(int k)
{
	int				i;
	unsigned int	n;

	n = k;
	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	int				h;
	unsigned int	k;

	k = n;
	h = 0;
	len = ft_nchar(k);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	while (len >= h)
	{
		str[len] = (k % 10) + '0';
		k = k / 10;
		len--;
	}
	return (str);
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

void	ft_puts(t_all_list *all, long n_move)
{
	ft_putnbr(n_move);
	write(1, "\n", 1);
	mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr,
		all->data.img_corner, 0, 0);
	mlx_string_put(all->data.mlx_ptr, all->data.win_ptr, 15, 10, 26,
		ft_itoa(n_move));
}
