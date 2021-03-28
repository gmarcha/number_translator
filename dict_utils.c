/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:32:52 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/28 16:49:53 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int					check_line(char **buf)
{
	while (**buf && is_sep(**buf, "\n"))
		(*buf)++;
	while (**buf && is_sep(**buf, " \t"))
		(*buf)++;
	if (**buf && !is_sep(**buf, "0123456789"))
		return (0);
	while (**buf && is_sep(**buf, "0123456789"))
		(*buf)++;
	while (**buf && is_sep(**buf, " \t"))
		(*buf)++;
	if (**buf && !is_sep(**buf, ":"))
		return (0);
	(*buf)++;
	while (**buf && is_sep(**buf, " \t"))
		(*buf)++;
	if (**buf && is_sep(**buf, "\n"))
		return (0);
	while (**buf && !is_sep(**buf, " \t\n"))
		(*buf)++;
	while (**buf && is_sep(**buf, " \t\n"))
		(*buf)++;
	return (1);
}

int					get_nb_entries(char *buf)
{
	int				count;

	count = 0;
	while (*buf)
	{
		if (!check_line(&buf))
			return (0);
		count++;
	}
	return (count);
}

char				*trim(char *str)
{
	char			*res;
	int				start;
	int				i;

	if (ft_strlen(str) < 2 && *str == 48)
		return (ft_strdup(str));
	start = 0;
	while (str[start] && str[start] == 48)
		start++;
	if (!str[start])
		return (ft_strdup(str));
	if (!(res = (char *)malloc(ft_strlen(str) - start + 1)))
		return (0);
	i = 0;
	while (str[start])
		res[i++] = str[start++];
	res[i] = 0;
	return (res);
}
