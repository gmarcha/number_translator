/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:51:05 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/28 13:26:36 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int					get_coeff(char *nbr)
{
	int				coeff;
	int				count;
	int				i;

	coeff = 0;
	count = 0;
	i = 0;
	while (nbr[i])
	{
		if (count == 3)
		{
			count = 0;
			coeff++;
		}
		count++;
		i++;
	}
	return (coeff);
}

int					handle_zero(t_dict *dict)
{
	int				i;

	i = 0;
	while (dict[i].value)
	{
		if (ft_strcmp(dict[i].value, "0") == 0)
		{
			ft_putstr(dict[i].key);
			ft_putstr("\n");
			ft_free_dict(dict);
			return (0);
		}
		i++;
	}
	ft_puterr("Dict Error\n");
	ft_free_dict(dict);
	return (0);
}

int					is_zero(char *nbr)
{
	int				i;

	i = 0;
	while (nbr[i])
		if (nbr[i++] != 48)
			return (0);
	return (1);
}

int					main(int argc, char *argv[])
{
	t_list			*begin_list;
	t_dict			*dict;
	char			*nbr;
	int				coeff;

	begin_list = 0;
	if (!parse_input(argc, argv))
		return (0);
	if (!(dict = parse_dict((argc == 3) ? argv[1] : "numbers.dict")))
		return (0);
	nbr = (argc == 3) ? argv[2] : argv[1];
	if (is_zero(nbr))
		return (handle_zero(dict));
	coeff = get_coeff(nbr);
	ft_strrev(nbr);
	if (!(begin_list = digit_to_letter(dict, nbr, coeff)))
	{
		ft_free_dict(dict);
		return (0);
	}
	ft_print_list(begin_list);
	ft_free_list(begin_list);
	ft_free_dict(dict);
	return (0);
}
