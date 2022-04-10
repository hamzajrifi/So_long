/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:22:45 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/10 17:00:37 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//***---------- check one if in up adn down --------**/
int	check_one_up_down(char *ptr, int n_check)
{
	int	i;
	
	i = 0;
	while (ptr[i++] == '1');
	if (ptr[--i] != '\n')
		check_arg(0, -1);
	return (ft_strlen(ptr));
}
//*------------- check if any other character in map ---------------/
int	check_character(char *ptr)
{
	int		i;
	int		j;
	char	*char_map;
	int		n;

	char_map = ft_strdup("1ECP0");
	i = 0;
	
	while (ptr[i] && ptr[i] != '\n')
	{
		n = 0;
		j = 0;
		while (char_map[j])
		{
			if (char_map[j] == ptr[i])
				n++;
			j++;
		}
		if (n == 0)
		{
		
			return (1);
		}
		i++;
	}
	return (0);
}

//--------  check caracter if 1 in left and right ---------/
int	check_one_left_right(char *ptr, int size_line)
{
	int	i;
	
	i = -1;
	if (!ptr)
		return (1);
	if (size_line != ft_strlen(ptr) || check_character(ptr) == 1)
	{
		check_arg(0, -1);
	}
	while (ptr[++i] != '\n' && ptr[i])
	{
		if (ptr[0] != '1')
		{
			
			check_arg(0, -1);
		}
		else if (ptr[i + 1] == '\n')
			if (ptr[i] != '1')
			{
				check_arg(0, -1);
			}
	}
	return (0);	
}

//*------ check P and E if repeater ------/
void	check_P_C(char *ptr, int n)
{
	static int 	p;
	static int	e;
	int			i;
	
	i = 0;
	if ((p != 1 || e != 1) && n == 1)
	{
		check_arg(0, -1);	
	}
	while (ptr[i])
	{
		if (ptr[i] == 'P')
			p++;
		else if (ptr[i] == 'E')
			e++;
		i++;
	}
}

//--------  check map ---------/
char 	*check_map(fd)
{
	char	*ptr;
	int		i;
	int		size_line;
	int		n_check;
	char	*temp;
	
	ptr = get_next_line(fd);
	size_line = ft_strlen(ptr);
	i = 0;
	n_check = 0;
	while (n_check == 0)
	{
		if (ptr)
			temp = ptr;
		n_check = check_one_left_right(ptr, size_line);
		if (i == 0 || n_check == 1)
		{
			check_one_up_down(temp, n_check);
		
		}
		if (i > 0)
		{
			check_P_C(temp, n_check);
		}
		if (n_check == 0)
		{
			ptr = get_next_line(fd);
		}
		i++;
	}
	return (ptr);
}
//--------  check argiment ---------/
char	*check_arg(int ac, int fd)
{
	char	*ptr;

	if (ac == 1)
		write(1, "inserte map\n", 13);
	else if (ac > 2)
		write(1, "please inserte just map\n", 25);
	else if (fd < 0)
		write(1, "please inserte correcte your map\n", 34);
	if (ac == 1 || ac > 2 || fd < 0)
		exit(1);
	check_map(fd);
	return ptr;
}