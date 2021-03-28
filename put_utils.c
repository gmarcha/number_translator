#include "dict.h"

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
