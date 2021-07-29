/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_beautiful_header.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:38:24 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/19 11:18:18 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BEAUTIFUL_HEADER_H
# define FT_BEAUTIFUL_HEADER_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);
int		ft_check_args(int ac, char **av);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_add(int a, int b);
void	ft_sub(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
void	ft_mul(int a, int b);

#endif
