/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:22:45 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/18 00:27:07 by hjrifi           ###   ########.fr       */
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
		ft_error("map must be surrounded by walls\n");
	}
	if (ptr[i] != '\n' && k == 0)
	{
		ft_error("map must be surrounded by walls\n");
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
			ft_error("map must be surrounded by walls\n");
	}	
	if (size_line != ft_strlen(ptr) || check_character(ptr) == 1)
	{
		ft_error("the lines of the map are not identical\n");
	}
	while ((ptr[++i] != '\n' && ptr[i]))
	{
		if (ptr[0] != '1')
			ft_error("map must be surrounded by walls\n");
		else if (ptr[i + 1] == '\n' && ptr[i] != '1')
			ft_error("map must be surrounded by walls\n");
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
		ft_error("Check the map requirments\n");
	else if (n == 1)
	{
		p = 0;
		e = 0;
	}
	if (p > 1)
		ft_error("Number of players is greater than one\n");
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
			if (n_check == 0 && line_map != i + 1)
				free(temp);
		}
		i++;
	}
	free(ptr);
	free(temp);
}
