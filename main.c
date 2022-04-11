/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:59:40 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/11 20:50:12 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

/*--------   read line to new line -------*/
char	*read_line(fd)
{
	char		*tab;
	int			i;
	int			size_line;
	
	if (!(tab = malloc(sizeof(char) * 99999)))
		return (NULL);
	i = 0;
	size_line  = 1;
	while((size_line = read(fd, &tab[i], 1)) > 0)
		if (tab[i++] == '\n')
			break;
	if ((tab[i - 1] == '\0' && size_line == 0) || size_line == -1)
	{
		free(tab);
		return (NULL);
	}
	return(tab);
}

//--------  check argiment ---------/
void	check_arg(int ac, char **av,int fd)
{
	if (ac == 1)
		write(2, "inserte map\n", 13);
	else if (ac > 2)
		write(2, "please inserte just map\n", 25);
	else if (fd < 0)
		write(2, "please inserte correcte your map\n", 34);
	if (ac == 1 || ac > 2 || fd < 0 )
		exit(1);
}

//--------  main  ---------/
int	main(int ac, char **av)
{
	int		fd;
	char	*ptr;
	
	fd = open(av[1], O_RDWR);
	check_arg(ac, av, fd);
	check_map(fd);
	ptr = read_line(fd);
	while (ptr)
	{
		printf("ptr = %s", ptr);
		ptr = read_line(fd);
	}
	return (0);
}

