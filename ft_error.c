/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:26:25 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/11 21:32:45 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error(int n_error)
{
	if (n_error == 1)
		write(2, "inserte map\n", 13);
	else if (n_error == 2)
		write(2, "please inserte just map\n", 25);
	else if (n_error == 3)
		write(2, "please inserte correcte your map\n", 34);
	else if (n_error == 4)
		write(2, "insert map type ***.ber\n", 25);
	exit(1);
}