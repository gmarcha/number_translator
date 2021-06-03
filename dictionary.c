/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:50:37 by gamarcha          #+#    #+#             */
/*   Updated: 2021/06/03 14:52:17 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include <stdio.h>
t_dict				*fill_dict(t_dict *dict, char **strs, int nb_entries)
{
	char			*array;
	int				i;
	int				j;

	i = -1;
	while (++i < nb_entries)
	{
		array = trim(strs[i * 2]);
		j = 0;
		while (j < i)
			if (ft_strcmp(dict[j++].value, array) == 0)
				return (0);
		printf("Value: %d\t%s\n", i, strs[i * 2]);
		dict[i].value = ft_strdup(array);
		dict[i].key = ft_strdup(strs[i * 2 + 1]);
		free(array);
	}
	dict[i].value = 0;
	return (dict);
}

t_dict				*read_dict(char *buf)
{
	t_dict			*dict;
	char			**strs;
	int				nb_entries;

	if (!(nb_entries = get_nb_entries(buf)))
		return (0);
	if (!(strs = ft_split(buf, " \t\n:")))
		return (0);
	if (!(dict = (t_dict *)malloc(sizeof(t_dict) * (nb_entries + 1))))
		return (ft_free_strs(strs));
	if (!fill_dict(dict, strs, nb_entries))
		return (ft_free_strs(strs));
	ft_free_strs(strs);
	return (dict);
}

t_dict				*parse_dict(char *file)
{
	t_dict			*dict;
	char			buf[32768];
	int				buf_size;
	int				fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_puterr("Dict Error\n"));
	if ((buf_size = read(fd, buf, 32768)) < 1)
		return (ft_puterr("Dict Error\n"));
	buf[buf_size] = 0;
	if (!(dict = read_dict(buf)))
		return (ft_puterr("Dict Error\n"));
	close(fd);
	return (dict);
}
