/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beautiful_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:09:50 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/18 10:38:56 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BEAUTIFUL_HEADER_H
# define BEAUTIFUL_HEADER_H

void	ft_putchar(char c);
int	ft_is_in_charset(char *charset, char c);
char	*ft_strndup(char *src, int n);
int	ft_len_word(char *str, char *charset);
int	ft_count_words(char *str, char *charset);
char	**ft_split(char *str, char *charset);
int	ft_atoi(char *str);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);
int	ft_scrapverif(char *str, int size);
int	ft_line_left_right(char *str, int size);
int	ft_line_right_left(char *str, int size);
int	ft_column_up_down(char **tab, int x, int size);
int	ft_column_down_up(char **tab, int x, int size);
int	ft_strlen(char *str);
int	ft_is_valid_board(char **tab, int size);
int	ft_line_left_right2(char *str, int size, int x);
int	ft_line_right_left2(char *str, int size, int x);
int	ft_column_up_down2(char **tab, int x, int size, int y);
int	ft_column_down_up2(char **tab, int x, int size, int y);
void	ft_affichage(char **str, int size);



#endif
