/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:51:53 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/28 16:35:16 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

char				*get_value(char *nbr);
t_list				*add_value(t_dict *dict, t_list **begin_list, int val);
char				*find_coeff(int zero);
t_list				*add_coeff(t_dict *dict, t_list **begin_list, int zero);

int					check_line(char **buf);
int					get_nb_entries(char *buf);
char				*trim(char *str);

t_dict				*fill_dict(t_dict *dict, char **strs, int nb_entries);
t_dict				*read_dict(char *buf);
t_dict				*parse_dict(char *file);

t_dict				*treat_hundred(t_dict *dict, t_list **list, int val);
t_dict				*treat_remainder(t_dict *dict, t_list **list, int val);
t_dict				*treat_coeff(t_dict *dict, t_list **list, int val, int i);
t_dict				*treat_value(t_dict *dict, t_list **list, int val, int i);
t_list				*digit_to_letter(t_dict *dict, char *nbr, int coeff);

void				*ft_free(void *data);
void				*ft_free_strs(char **strs);
void				*ft_free_dict(t_dict *dict);

void				ft_free_list(t_list *begin_list);
void				ft_print_list(t_list *begin_list);
t_list				*ft_create_element(void *data);
t_list				*ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_merge(t_list **begin_list1, t_list *begin_list2);

char				*ft_strdup(char *src);
int					is_sep(char c, char *sep);
int					nb_words(char *str, char *sep);
char				**ft_split(char *str, char *sep);

char				*check_input(char *str);
char				**parse_input(int ac, char **av);

void				*ft_puterr(char *error);
void				*ft_putstr(char *str);

void				ft_swap(char *a, char *b);
void				ft_strrev(char *str);
int					ft_strcmp(char *s1, char *s2);

int					ft_strlen(char *str);
int					ft_atoi(char *str);
int					get_len(int nb);
char				*ft_itoa(int nb);

#endif
