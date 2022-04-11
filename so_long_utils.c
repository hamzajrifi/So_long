/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:51:38 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/11 21:38:29 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* ----------- calcule line array  ------------- */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0 ;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/* ----------- allocation array  ------------- */
char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;
	int		len_s1;

	len_s1 = ft_strlen(s1);
	i = 0;
	ptr = (char *)malloc(len_s1 * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*--------   read line to new line -------*/
char	*read_line(int fd)
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