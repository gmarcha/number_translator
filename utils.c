#include "dict.h"

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
