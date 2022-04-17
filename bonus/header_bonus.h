/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:27:46 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/17 00:45:27 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct n_list
{
	char	*path_img;
	void	*img;
	char	**map;
	int		size_height;
	int		size_with;
	int		n_coin;
	int		n_hole;
	int		n_enemy;
	int		*x_exit;
	int		*y_exit;
	int		*x_enemy;
	int		*y_enemy;
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
	void	*img_police_left;
	void	*img_police_right;
	char	*path_police_left;
	char	*path_police_right;
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
	t_list	*map;
	t_path	data;
	int		x;
	int		y;
}		t_all_list;

char	*get_next_line(int fd);
void	free_mytab(char	**str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
long	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int len);
void	check_arg(int ac, int fd, int line_map);
void	create_map(int fd, t_list *map);
void	check_type_map(char *name_map, int fd);
void	ft_split(int fd, t_list **data_map);
void	ft_error(char *str);
void	ft_puts(t_all_list *all, long n_move);
void	check_map(int fd, int line_map, int n_check, int i);
int		check_character(char *ptr);
void	check_charactire(t_list *map, t_path data, int y, int x);
int		myf(int key, t_all_list *all);
int		check_coin(t_all_list *all, int y, int x);
int		ft_bye(char *ptr);
void	path_image(t_list *map);
void	index_exit(t_list *map);
int		ft_loop_img(t_all_list *all);
char	*ft_itoa(int n);
#endif