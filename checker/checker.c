/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:22:45 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/11 00:08:15 by hjrifi           ###   ########.fr       */
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
int	check_one_left_right(char *ptr, int size_line, int n_check)
{
	int	i;

	i = -1;
	if (!ptr)
		return (1);
	if (ptr[size_line - 1] == '\0' && size_line != ft_strlen(ptr) && n_check == 1)
			size_line -= 1;
	if (size_line != ft_strlen(ptr) || check_character(ptr) == 1)
		check_arg(0, -1);
	while (ptr[++i] != '\n' && ptr[i])
	{
		if (ptr[0] != '1')
			check_arg(0, -1);
		else if (ptr[i + 1] == '\n')
		{
			if (ptr[i] != '1')		
				check_arg(0, -1);		
		}	
	}
	return (0);
}

//*------ check P and E if repeater ------/
void	check_p_c(char *ptr, int n)
{
	static int	p;
	static int	e;
	int			i;

	i = 0;
	if ((p != 1 || e < 1) && n == 1)
		check_arg(0, -1);
	else if (n == 1)
	{
		p = 0;
		e = 0;
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
t_list	*check_map(int fd, t_list *str)
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
		write(1, ptr, ft_strlen(ptr));
		if (ptr)
			temp = ptr;
		if (i == 0 || n_check == 1)
		{
			check_one_up_down(temp, n_check);
		}
		if (n_check == 0 && i++ > 0)
		{
			n_check = check_one_left_right(ptr, size_line, n_check);
			check_p_c(temp, n_check);
			free(ptr);
			ptr = get_next_line(fd);
		}
		
	}
	free(ptr);
	str->img_width = i;
	str->img_height = size_line - 2;
	return (str);
}

//--------  check argiment ---------/
t_list	*check_arg(int ac, int fd)
{
	t_list	*ptr;

	if (ac == 1)
		write(2, "inserte map\n", 13);
	else if (ac > 2)
		write(2, "please inserte just map\n", 25);
	else if (fd < 0)
		write(2, "please inserte correcte your map\n", 34);
	if (ac == 1 || ac > 2 || fd < 0 )
		exit(1);	
	ptr = check_map(fd, ptr);
	return (ptr);
}
