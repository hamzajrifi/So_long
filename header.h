/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:47:41 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/11 21:51:17 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
# include <fcntl.h>

typedef struct n_list
{
	char	*path_img;
	void	*img;
	char	**map;
	int		img_width;
	int		img_height;
	int		i;
}	t_list;

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
t_list	*check_map(int fd, char *name_map);
void	ft_error(int n_error);
char	*read_line(int fd);

#endif