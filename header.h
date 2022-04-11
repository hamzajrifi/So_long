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
	int		img_width;
	int		img_height;
}	t_list;

char	*get_next_line(int fd);
void	free_mytab(char	**str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int len);
t_list	*check_arg(int ac, int fd);
void	create_map(int fd);
void	check_type_map(char *name_map);

#endif