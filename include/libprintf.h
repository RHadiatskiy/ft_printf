/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:23:09 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/12 20:19:35 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# define SPECIFICATE 	"sSpdDioOuUxXcC%"
# define base_base 			base[17] = "0123456789abcdef";

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//# include "../include/printf.h"

void				ft_putchar(char c);
size_t				ft_strlen(const char *str);
void				ft_putnbr(int nb);
char				*ft_to_lowcase(const char *str);
int					sqr(int nb, int sq);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int str_base);
char				*ft_itoa(long int nbr);
int					ft_putstrf(char *str);
char				*ft_strdup(const char *str);
char				*ft_strchrdup(char *str, char chr);
char				*memaloc_str(char *str, int *i);
int					ft_strlenchr(const char *s, int c);
int					parse_precision(char *str);
int					parse_width(char *str);
int					ft_isdigit(int n);

#endif
