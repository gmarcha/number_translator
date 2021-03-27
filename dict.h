#ifndef DICT_H
# define DICT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_dict
{
	char			*value;
	char			*key;
}					t_dict;

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

#endif