/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:12:02 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/09 18:23:41 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	free_mytab(char	**str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int len);

#endif