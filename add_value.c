/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:50:17 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/28 12:59:44 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

char				*get_value(char *nbr)
{
	char			*str;
	int				len;
	int				i;

	len = 0;
	while (nbr[len] && len < 3)
		len++;
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	str[len] = 0;
	i = 0;
	while (len--)
		str[len] = nbr[i++];
	return (str);
}

t_list				*add_value(t_dict *dict, t_list **begin_list, int val)
{
	char			*value;
	int				j;

	if (!(value = ft_itoa(val)))
		return (0);
	j = 0;
	while (dict[j].value)
	{
		if (ft_strcmp(dict[j].value, value) == 0)
		{
			if (!ft_list_push_back(begin_list, dict[j].key))
				return (ft_free(value));
			break ;
		}
		if (!dict[j + 1].value)
		{
			ft_puterr("Dict Error\n");
			return (ft_free(value));
		}
		j++;
	}
	free(value);
	return (*begin_list);
}

char				*find_coeff(int zero)
{
	char			*value;
	int				i;

	if (!(value = (char *)malloc(zero + 2)))
		return (0);
	value[0] = '1';
	i = 1;
	while (i < zero + 1)
		value[i++] = '0';
	value[i] = 0;
	return (value);
}

t_list				*add_coeff(t_dict *dict, t_list **begin_list, int zero)
{
	char			*value;
	int				j;

	if (!(value = find_coeff(zero)))
		return (0);
	j = 0;
	while (dict[j].value)
	{
		if (ft_strcmp(dict[j].value, value) == 0)
		{
			if (!ft_list_push_back(begin_list, dict[j].key))
				return (ft_free(value));
			break ;
		}
		if (!dict[j + 1].value)
		{
			ft_puterr("Dict Error\n");
			return (ft_free(value));
		}
		j++;
	}
	free(value);
	return (*begin_list);
}
