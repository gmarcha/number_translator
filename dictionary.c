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
		return (ft_free_strs(strs));
	i = -1;
	while (++i < nb_entries)
	{
		dict[i].value = ft_strdup(strs[i * 2]);
		dict[i].key = ft_strdup(strs[i * 2 + 1]);
	}
	dict[i].value = 0;
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
		return (ft_puterr("Dict Error Fuck\n"));
	if ((buf_size = read(fd, buf, 32768)) < 1)
		return (ft_puterr("Dict Error\n"));
	buf[buf_size] = 0;
	if (!(dict = read_dict(buf)))
		return (ft_puterr("Dict Error\n"));
	close(fd);
	return (dict);
}
