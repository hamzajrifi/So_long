/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:50:54 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/11 22:00:21 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* ----------- funtion check type map if __.ber --------- */
void check_type_map(char *name_map)
{
	int		i;
	char	*tab;
	int		j;

	j = 0;
	tab = ft_strdup("reb.");
	i = ft_strlen(name_map) - 1;
	while (name_map[i--] == tab[j])
		j++;
	if(tab[j] != '\0')
		ft_error(4);
	free (tab);
}

/* ----------- funtion check map --------- */
t_list	*check_map(int fd, char *name_map)
{
	t_list	*map_data;
	check_type_map(name_map);
	
	map_data = malloc(sizeof(t_list));
	map_data->i = 0;
	map_data->map[0] = read_line(fd);
	//while ((map_data.map[map_data.i++] = read_line(fd)));
	return (map_data);
}