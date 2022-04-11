/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:58:12 by hjrifi            #+#    #+#             */
/*   Updated: 2022/04/10 22:34:32 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void check_type_map(char *name_map)
{
	int		i;
	char	*tab;
	int		j;

	j = 0;
	tab = ft_strdup("rib.");
	i = ft_strlen(name_map) - 1;
	while (name_map[i--] == tab[j++]);
	if(tab[j] != '\0')
	{
		write(2, "inserte map type ***.bir\n", 26);
		exit(1);
	}
	free (tab);
}