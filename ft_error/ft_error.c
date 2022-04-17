/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:26:25 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/17 20:40:41 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_error(char *str)
{
	int		i;

	i = ft_strlen(str);
	write(1, "Error\n", 7);
	exit(1);
}

/* --------------- */
int	ft_bye(char *ptr)
{
	write(1, ptr, ft_strlen(ptr));
	exit(0);
}
