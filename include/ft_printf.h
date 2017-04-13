/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:33:25 by rhadiats          #+#    #+#             */
/*   Updated: 2017/03/22 19:22:41 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFICATE 	"sSpdDioOuUxXcC%"
# define base_base 			base[17] = "0123456789abcdef";

# define CHAR_1 		char
# define CHAR_2 		char *
# define VOID_1 		void
# define VOID_2 		void *
# define INT 			int

# define TYPE_F char	*type_f[16] =	\
	{									\
		"char *",						\
		"char *",						\
		"void *",						\
		"int",							\
		"int",							\
		"int",							\
		"int",							\
		"int",							\
		"int",							\
		"int",							\
		"int",							\
		"int",							\
		"char",							\
		"char",							\
		"char"							\
	};

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libprintf.h"

typedef struct		s_flags
{
	unsigned int		zero : 1;
	unsigned int		plus : 1;
	unsigned int		minus : 1;
	unsigned int		space : 1;
	unsigned int		hash : 1;
//	unsigned int		point : 1;
	unsigned int		width;
	unsigned int		precision;
/*	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}					lenght;
*/	char				specificate;
	char				*str;
	char				*args;
}					t_flags;

t_flags				ft_print(char *format, ...);
char				*ft_strjoin_f(char *s1, char *s2);
t_flags				flags_reset(t_flags flags);
void				print_flags(t_flags flags);

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
t_flags				ft_parse(t_flags flags);
t_flags				parse_flags(char *str, t_flags flags);
int					parse_precision(char *str);
int					parse_width(char *str);
int					ft_isdigit(int n);

#endif
