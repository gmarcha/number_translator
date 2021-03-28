#include "dict.h"

void				*ft_free(void *data)
{
	free(data);
	return (0);
}

void				*ft_free_strs(char **strs)
{
	int				i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}

void				*ft_free_dict(t_dict *dict)
{
	int				i;

	i = 0;
	while (dict[i].value)
	{
		free(dict[i].value);
		free(dict[i].key);
		i++;
	}
	free(dict);
	return (0);
}
