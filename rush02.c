#include "dict.h"
#include <stdio.h>

void				*ft_puterr(char *error)
{
	int				i;

	i = 0;
	while (error[i])
		i++;
	write(2, error, i);
	return (0);
}

void				*ft_putstr(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (0);
}

void				*free_strs(char **strs)
{
	int				i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int					ft_atoi(char *str)
{
	int				result;
	int				i;

	result = 0;
	i = 0;
	while (str[i])
		result = result * 10 + str[i++] - 48;
	return (result);
}

int					get_len(int nb)
{
	int				size;

	size = 0;
	while (nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char				*ft_itoa(int nb)
{
	char			*str;
	int				len;

	len = get_len(nb);
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	str[len] = 0;
	while (len--)
	{
		str[len] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}

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

void				ft_free_list(t_list **begin_list)
{
	t_list			*node;

	if (!*begin_list)
		return ;
	while (begin_list)
	{
		node = *begin_list;
		*begin_list = (*begin_list)->next;
		free(node->data);
		free(node);
	}
}

void				ft_print_list(t_list *begin_list)
{
	if (!begin_list)
		return ;
	while (begin_list)
	{
		ft_putstr((char *)begin_list->data);
		begin_list = begin_list->next;
	}
}

t_list				*ft_create_element(void *data)
{
	t_list			*node;

	if (!(node = (t_list *) malloc(sizeof(t_list))))
		return (0);
	node->next = 0;
	node->data = data;
	return node;
}

void				ft_list_push_back(t_list **begin_list, void *data)
{
	t_list			*node;

	if (!*begin_list)
		*begin_list = ft_create_element(data);
	else 
	{
		node = *begin_list;
		while (node->next)
			node = node->next;
		node->next = ft_create_element(data);
	}
}

void				ft_list_push_front(t_list **begin_list, void *data)
{
	t_list			*node;

	node = ft_create_element(data);
	node->next = *begin_list;
	*begin_list = node;
}

void				ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list			*node;
	t_list			*curr;

	node = *begin_list1;
	*begin_list1 = begin_list2;
	curr = *begin_list1;
	while (curr->next)
		curr = curr->next;
	//printf("%s\n", (char *)curr->data);
	curr->next = node;
}

char				*check_input(char *str)
{
	int				i;
	
	if (!str || !str[0] || str[0] == 48)
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

t_dict				*read_dict(char *buf)
{
	t_dict			*dict;
	char			**strs;
	int				nb_entries;
	int				i;

	if (!(nb_entries = get_nb_entries(buf)))
		return (0);
	if (!(strs = ft_split(buf, " \t\n:")))
		return (0);
	if (!(dict = (t_dict *)malloc(sizeof(t_dict) * (nb_entries + 1))))
		return (free_strs(strs));
	i = -1;
	while (++i < nb_entries)
	{
		dict[i].value = ft_strdup(strs[i * 2]);
		dict[i].key = ft_strdup(strs[i * 2 + 1]);
	}
	dict[i].value = 0;
	free_strs(strs);
	return (dict);
}

t_dict				*parse_dict(char *file)
{
	t_dict			*dict;
	char			buf[4096];
	int				buf_size;
	int				fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_puterr("Dict Error Fuck\n"));
	if ((buf_size = read(fd, buf, 4096)) < 1)
		return (ft_puterr("Dict Error\n"));
	buf[buf_size] = 0;
	if (!(dict = read_dict(buf)))
		return (ft_puterr("Dict Error\n"));
	close(fd);
	return (dict);
}

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

int					add_value(t_dict *dict, t_list **begin_list, int val)
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
			ft_list_push_back(begin_list, dict[j].key);
			break;
		}
		if (!dict[j + 1].value)
		{
			free(value);
			ft_puterr("Dict Error\n");
			return (0);
		}
		j++;
	}
	free(value);
	return (1);
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
	printf("%s\n", value);
	return (value);
}

int					add_coeff(t_dict *dict, t_list **begin_list, int zero)
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
			ft_list_push_back(begin_list, dict[j].key);
			break;
		}
		if (!dict[j + 1].value)
		{
			free(value);
			ft_puterr("Dict Error\n");
			return (0);
		}
		j++;
	}
	free(value);
	return (1);
}

t_list				*add_three_groups(t_dict *dict, char *nbr, int coeff)
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
		val = ft_atoi(str);
		if (val / 100)
		{
			if (!add_value(dict, &begin_list2, val / 100))
				return (0);
			ft_list_push_back(&begin_list2, " ");
			if (!add_value(dict, &begin_list2, 100))
				return (0);
		}
		if (val / 100 && val % 100)
			ft_list_push_back(&begin_list2, " ");
		if (val % 100)
		{
			val %= 100;
			if (val < 20)
			{
				if (!add_value(dict, &begin_list2, val))
					return (0);
			}
			else
			{
				if (val / 10)
					if (!add_value(dict, &begin_list2, val / 10 * 10))
						return (0);
				if (val / 10 && val % 10)
					ft_list_push_back(&begin_list2, " ");
				if (val % 10)
					if (!add_value(dict, &begin_list2, val % 10))
						return (0);
			}
		}
		if (val && i > 0)
		{
			ft_list_push_back(&begin_list2, " ");
			if (!add_coeff(dict, &begin_list2, i * 3))
				return (0);
			ft_list_push_back(&begin_list2, " ");
		}
		if (val)
			ft_list_merge(&begin_list1, begin_list2);
		nbr += 3;
		free(str);
	}
	return (begin_list1);
}

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
	coeff = get_coeff(nbr);
	printf("%d\n", coeff);
	ft_strrev(nbr);
	if (!(begin_list = add_three_groups(dict, nbr, coeff)))
		return (0);
	ft_print_list(begin_list);
	write(1, "\n", 1);
	return (0);
}