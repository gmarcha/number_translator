/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:51:31 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/28 12:51:33 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void				ft_swap(char *a, char *b)
{
	char			tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void				ft_strrev(char *str)
{
	int				n;
	int				i;

	n = ft_strlen(str);
	i = -1;
	while (++i < n / 2)
		ft_swap(&str[i], &str[n - i - 1]);
}

int					ft_strcmp(char *s1, char *s2)
{
	int				i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
