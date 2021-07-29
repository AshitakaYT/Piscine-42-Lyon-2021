/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kestucke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:47:35 by kestucke          #+#    #+#             */
/*   Updated: 2021/07/28 00:06:54 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

struct		s_map
{
	char	**fullmapchar;
	char	**mapchar;
	int		**mapint;
	int		xsize;
	int		ysize;
	int		maxsize;
	int		xmaxpos;
	int		ymaxpos;
	char	obstacle;
	char	space;
	char	fullfill;
	int		nbroflines;
	int		linelength;
	char	*firstline;
	char	*file;
}			map;

char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
char	*ft_get_file(char *dico);
int		ft_tablen(char **tab);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);
void	ft_swap(int *a, int *b);
int		**ft_create_int_tab(int xsize, int ysize);
int		**ft_make_int_tab(int **inttab, char **tab, char obstacle);
void	ft_obstacle_incrementation(int **inttab, char **tab, int *y, int *x);
int		ft_is_square(struct s_map structure, int x, int y);
int		ft_is_potentially_square(int **tab, int x, int y, int size);
void	ft_get_solution(struct s_map *structure, int x, int y, int mybool);
void	ft_print_int_tab(int **tab, int xsize, int ysize);
int		ft_atoi(char *str);
int		ft_atoi_remastered(char *str, int length);
int		ft_is_first_line_ok(struct s_map *strc, char *str);
int		ft_is_number_of_lines_ok(char **charmap, int nbroflines);
int		ft_is_line_lenghts_ok(char **charmap, int linelength);
int		ft_size_first_line(char *map);
int		ft_is_valid_charset(char obstacle, char space, char **map);
char	*ft_scooter(void);
void	ft_get_solution(struct s_map *str, int x, int y, int mybool);
void	ft_print_int_tab(int **tab, int xsize, int ysize);
void	ft_print_char_tab(char **tab);
int		ft_check_first_line(char **map);
int		ft_check_seconde_line(char **map);
int		ft_check_same_length(char **map);
int		ft_check_charset(char **map);

#endif
