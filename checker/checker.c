/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:22:45 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/17 20:33:57 by hjrifi           ###   ########.fr       */
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
	if (((k > 0 && ptr[i] != '\0') && (k > 0 && ptr[i] != '\n'))
		|| (size_line != i + 1 && k > 0))
	{
		ft_error("don't have one in last line\n");
	}
	if (ptr[i] != '\n' && k == 0)
	{
		ft_error("don't have one in first line\n");
	}
	return (ft_strlen(ptr));
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
			ft_error("wall left or right it's wrong 1\n");
	}	
	if (size_line != ft_strlen(ptr) || check_character(ptr) == 1)
	{
		ft_error("wall it's wrong 2 \n");
	}
	while ((ptr[++i] != '\n' && ptr[i]))
	{
		if (ptr[0] != '1')
			ft_error("first wall it's wrong \n");
		else if (ptr[i + 1] == '\n' && ptr[i] != '1')
			ft_error("right wall it's wrong\n");
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
		ft_error("check your port and player\n");
	else if (n == 1)
	{
		p = 0;
		e = 0;
	}
	if (p > 1)
		ft_error("check player");
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
void	check_map(int fd, int line_map, int n_check, int i)
{
	char	*ptr;
	int		size_line;
	char	*temp;

	ptr = get_next_line(fd);
	size_line = ft_strlen(ptr);
	while (n_check == 0 && line_map > i + 1)
	{
		if (ptr)
			temp = ft_strdup(ptr);
		if (i == 0 || line_map == i)
			check_one_up_down(temp, i, size_line);
		if (n_check == 0)
		{
			n_check = check_one_left_right(ptr, size_line, line_map);
			check_p_c(ptr, n_check);
			free(ptr);
			ptr = get_next_line(fd);
			if (n_check == 0 && line_map > i + 1)
				free(temp);
		}
		i++;
	}
	free(ptr);
}
