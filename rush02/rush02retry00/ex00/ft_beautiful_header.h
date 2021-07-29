/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_beautiful_header.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:21:43 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 20:55:42 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BEAUTIFUL_HEADER_H
# define  FT_BEAUTIFUL_HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZE 4096

int				ft_atoi(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int nbr);
void			ft_putstr(char *str);
char			**ft_split(char *str, char *charset);
int				ft_strlen(char *str);
void			ft_swap(int *a, int *b);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strndup(char *src, int n);
int				ft_str_is_printable(char *str);
char			*ft_parse_argv(char *str);
char			**ft_get_lines(char *dic); // PAS TERMINEE
int				ft_tablen(char **tab);
int				ft_is_double_point_ok(char **lines);
int				ft_is_dic_ok(char **lines); // PAS TERMINEE
char			**ft_get_nums(char **lines);
int				ft_check_duplicate_nums(char **nums);
char			**ft_get_keys(char **lines);
struct	t_dict	*ft_get_dict(char **nums, char **keys);
void			ft_swap_dict(struct t_dict *dict1, struct t_dict *dict2);
void			ft_sort_dict(struct t_dict *dict);
int				ft_strncmp(char *s1, char *s2, int n);
int				ft_nbrlen(char *nbr);
void			ft_print_words(char *numbers, struct t_dict *dict);
int				ft_ischarprt(char c);
void			ft_get_past_doublepoint(char **str);
void			ft_get_past_spaces(char **str);
void			ft_get_past_whitespaces(char **str);
int				ft_get_number_len(char *str);

typedef struct t_dict
{
	char		*key;
	char		*number;
}				t_dict;

#endif
