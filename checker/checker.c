/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:22:45 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/14 02:31:51 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//***---------- check one if in up adn down --------**/
int	check_one_up_down(char *ptr, int k, int size_line)
{
	int	i;

	i = 0;
	while (ptr[i] == '1')
		i++;
	if (((k > 0 && ptr[i] != '\0') && (k > 0 && ptr[i] != '\n')) ||
		(size_line != i + 1 && k > 0))
	{
		ft_error(3,"don't have one in last line\n");
	}
	if (ptr[i] != '\n' && k == 0)
	{
		ft_error(3,"don't have one in first line\n");
	}
	return (ft_strlen(ptr));
}

//*---------- check if any other character in map ------------/
int	check_character(char *ptr)
{
	int		i;
	int		j;
	char	*cha_map;
	int		n;

	cha_map = ft_strdup("1ECP0");
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
	{
		n = 0;
		j = 0;
		while (cha_map[j])
		{
			if (cha_map[j] == ptr[i])
				n++;
			j++;
		}
		if (n == 0)
			return (1);
		i++;
	}
	free(cha_map);
	return (0);
}

//--------  check caracter if 1 in left and right ---------/
int	check_one_left_right(char *ptr, int size_line, int n_map)
{
	int			i;
	static int	k;

	k++;
	i = -1;
	if (!ptr)
		return (1);
	if (ptr[size_line - 1] == '\0' && size_line != ft_strlen(ptr) && n_map == k)
	{
		size_line -= 1;
		if (ptr[0] != '1' || ptr[ft_strlen(ptr) - 1] != '1')
			ft_error(3,"wall left or right it's wrong 1\n");
	}	
	if (size_line != ft_strlen(ptr) || check_character(ptr) == 1)
		{
			ft_error(3, "wall it's wrong 2 \n");
		}
	while ((ptr[++i] != '\n' && ptr[i]))
	{
		if (ptr[0] != '1')
			ft_error(3, "first wall it's wrong \n");
		else if (ptr[i + 1] == '\n' && ptr[i] != '1')
			ft_error(3, "right wall it's wrong\n");
	}
	return (0);
}

//*------ check P and E if repeater ------/
void	check_p_c(char *ptr, int n)
{
	static int	p;
	static int	e;
	static int	c;
	int			i;

	i = 0;
	if ((p != 1 || e < 1 || c == 0) && n == 1)
		ft_error(3, "check your port and player\n");
	else if (n == 1)
	{
		p = 0;
		e = 0;
	}
	if (p > 1)
		ft_error(3, "check player");
	while (ptr[i])
	{
		if (ptr[i] == 'P')
			p++;
		else if (ptr[i] == 'E')
			e++;
		else if (ptr[i] == 'C')
			c++;
		i++;
	}
}

//--------  check map ---------/
void	check_map(int fd, int line_map)
{
	char	*ptr;
	int		i;
	int		size_line;
	int		n_check;
	char	*temp;

	ptr = get_next_line(fd);
	
	i = 0;
	size_line = ft_strlen(ptr);
	n_check = 0;
	while (n_check == 0)
	{
		if (ptr)
			temp = ft_strdup(ptr);
		if (i == 0 || line_map == i)
			check_one_up_down(temp, i, size_line);
		if (n_check == 0)
		{
			n_check = check_one_left_right(ptr, size_line, line_map);
			check_p_c(temp, n_check);
			free(ptr);
			ptr = get_next_line(fd);
			if (n_check == 0)
				free(temp);
		}
		i++;
	}
	free(ptr);
}

//--------  check argiment ---------/
void	check_arg(int ac, int fd, int line_map)
{
	t_list	*ptr;

	if (ac == 1)
		ft_error(1, "add map \n");
	else if (ac > 2)
		ft_error(2, "you should insert just map \n");
	else if (fd < 0)
		ft_error(3, "can't read map\n");
	check_map(fd, line_map);
}
