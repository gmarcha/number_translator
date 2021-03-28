/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_to_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:50:45 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/28 16:30:22 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict				*treat_hundred(t_dict *dict, t_list **list, int val)
{
	if (val / 100)
	{
		if (!add_value(dict, list, val / 100))
			return (0);
		if (!ft_list_push_back(list, " "))
			return (0);
		if (!add_value(dict, list, 100))
			return (0);
	}
	if (val / 100 && val % 100)
		if (!ft_list_push_back(list, " and "))
			return (0);
	return (dict);
}

t_dict				*treat_remainder(t_dict *dict, t_list **list, int val)
{
	if (val % 100)
	{
		val %= 100;
		if (val < 20)
		{
			if (!add_value(dict, list, val))
				return (0);
		}
		else
		{
			if (val / 10)
				if (!add_value(dict, list, val / 10 * 10))
					return (0);
			if (val / 10 && val % 10)
				if (!ft_list_push_back(list, "-"))
					return (0);
			if (val % 10)
				if (!add_value(dict, list, val % 10))
					return (0);
		}
	}
	return (dict);
}

t_dict				*treat_coeff(t_dict *dict, t_list **list, int val, int i)
{
	if (val && i > 0)
	{
		if (!ft_list_push_back(list, " "))
			return (0);
		if (!add_coeff(dict, list, i * 3))
			return (0);
		if (!ft_list_push_back(list, ", "))
			return (0);
	}
	return (dict);
}

t_dict				*treat_value(t_dict *dict, t_list **list, int val, int i)
{
	if (!treat_hundred(dict, list, val))
		return (0);
	if (!treat_remainder(dict, list, val))
		return (0);
	if (!treat_coeff(dict, list, val, i))
		return (0);
	return (dict);
}

t_list				*digit_to_letter(t_dict *dict, char *nbr, int coeff)
{
	t_list			*begin_list1;
	t_list			*begin_list2;
	char			*str;
	int				val;
	int				i;

	begin_list1 = 0;
	i = -1;
	while (++i < coeff + 1)
	{
		begin_list2 = 0;
		if (!(str = get_value(nbr)))
			return (0);
		if (!treat_value(dict, &begin_list2, (val = ft_atoi(str)), i))
		{
			ft_free_list(begin_list2);
			ft_free_list(begin_list1);
			return (ft_free(str));
		}
		if (val)
			ft_list_merge(&begin_list1, begin_list2);
		nbr += 3;
		free(str);
	}
	return (begin_list1);
}
