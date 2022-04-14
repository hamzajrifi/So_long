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
	int		size_height;
	int		size_with;
	int		n_coin;
	int		n_hole;
	int		x;
	int		y;
}	t_list;

typedef struct t_path
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_floor;
	void	*img_up;
	void	*img_down;
	void	*img_left;
	void	*img_right;
	void	*img_player;
	void	*img_hole;
	void	*img_wall_center;
	void	*img_corner;
	void	*img_coin;
	char	*path_coin;
	char	*path_floor;
	char	*path_corner;
	char	*path_hole;
	char	*path_up;
	char	*path_down;
	char	*path_left;
	char	*path_right;
	char	*path_player;
	char	*path_wall_center;
	int		img_width;
	int		img_height;
}		t_path;

typedef struct all_list
{
	t_list *map;
	t_path data;
}	all_list;

char	*get_next_line(int fd);
void	free_mytab(char	**str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int len);
void	check_arg(int ac, int fd, int line_map);
void	create_map(int fd, t_list *map);
void	check_type_map(char *name_map, int fd);
void	ft_split(int fd, t_list **data_map);
void	ft_error(int n_error, char *str);
void	ft_putnbr(long nbr);
// ---  ----- -----  graphiaue ------- -- --- ------ //
void	check_charactire(t_list *map, t_path data, int y, int x);
// void	put_images_in_wind(t_list *map, t_path data);
#endif