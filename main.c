/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:07:18 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/09 17:53:46 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <stdio.h>

int main (int ac, char **av)
{
	int fd;
	(void) ac;
	char *ptr;
	
	fd = open(av[1], O_RDWR);
	ptr = get_next_line(fd);
	while (ptr)
	{
		printf("%s",ptr);
		ptr = get_next_line(fd);
	}
	
	return (0);
}