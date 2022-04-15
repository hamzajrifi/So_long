/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:26:25 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/15 07:53:49 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	ft_error(char *str)
{
	int		i;

	i = ft_strlen(str);
	write(1, "Error\n", 7);
	write(2, str, i);
	exit(1);
}

/* --------------- */
int	ft_bye(char *ptr)
{
	write(1, ptr, ft_strlen(ptr));
	exit(0);
}
