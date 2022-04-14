/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:26:25 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/12 21:18:43 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_error(int n_error, char *str)
{
	int	i;

	i = ft_strlen(str);
	write(2, str, i);
	//if (n_error == 1)
	//	write(2, "inserte map\n", i);
	//else if (n_error == 2)
	//	write(2, "please inserte just map\n", i);
	//else if (n_error == 3)
	//	write(2, "please inserte correcte your map\n", i);
	//else if (n_error == 4)
	//	write(2, "insert map type ***.ber\n", 25);
	exit(1);
}