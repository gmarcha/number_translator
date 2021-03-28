/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:51:12 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/28 12:51:13 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char				*ft_strdup(char *src)
{
	char			*dest;
	int				i;

	i = 0;
	while (src[i])
		i++;
	if (!(dest = (char *)malloc(i + 1)))
		return (0);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

int					is_sep(char c, char *sep)
{
	int				i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int					nb_words(char *str, char *sep)
{
	int				count;
	int				i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], sep))
			i++;
		if (str[i] && !is_sep(str[i], sep))
			count++;
		while (str[i] && !is_sep(str[i], sep))
			i++;
	}
	return (count);
}

char				**ft_split(char *str, char *sep)
{
	char			**strs;
	int				len;
	int				i;
	int				j;

	len = nb_words(str, sep);
	if (!(strs = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		while (*str && is_sep(*str, sep))
			str++;
		j = 0;
		while (str[j] && !is_sep(str[j], sep))
			j++;
		if (!(strs[i] = (char *)malloc(j + 1)))
			return (0);
		j = 0;
		while (*str && !is_sep(*str, sep))
			strs[i][j++] = *str++;
		strs[i++][j] = 0;
	}
	strs[i] = 0;
	return (strs);
}
