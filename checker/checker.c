/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:22:45 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/10 00:58:59 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char 	*check_map(fd)
{
	char	*ptr;
	int		i;
	
	ptr = get_next_line(fd);
	while(ptr[0] == '\n')
		ptr = get_next_line(fd);
	i = 0;
	while (ptr[i++] == '1');
	if (ptr[--i] != '\n')
		check_arg(0, -1);
	return (ptr);
}

char	*check_arg(int ac, int fd)
{
	char	*ptr;

	if (ac == 1)
		write(1, "inserte map\n", 13);
	else if (ac > 2)
		write(1, "please inserte just map\n", 25);
	else if (fd < 0)
		write(1, "please inserte correcte your map\n", 34);
	if (ac == 1 || ac > 2 || fd < 0)
		exit(1);
	ptr = check_map(fd);
	return ptr;
}