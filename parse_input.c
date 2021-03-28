/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:51:18 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/28 13:00:16 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char				*check_input(char *str)
{
	int				i;

	if (!str || !str[0])
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] < 48 || str[i] > 57)
			return (0);
	return (str);
}

char				**parse_input(int ac, char **av)
{
	int				fd;

	if (ac != 2 && ac != 3)
		return (ft_puterr("Error\n"));
	if (!check_input(av[ac - 1]))
		return (ft_puterr("Error\n"));
	fd = open(av[1], O_RDONLY);
	if (ac == 3 && fd == -1)
		return (ft_puterr("Dict Error\n"));
	close(fd);
	return (av);
}
