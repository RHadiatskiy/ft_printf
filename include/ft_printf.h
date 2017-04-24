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

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <inttypes.h>
# include <stdint.h>

typedef struct		s_flags
{
	unsigned int		zero : 1;
	unsigned int		plus : 1;
	unsigned int		minus : 1;
	unsigned int		space : 1;
	unsigned int		hash : 1;
	unsigned int		width : 1;
	unsigned int		precision : 1;
	unsigned int		get_width;
	unsigned int		get_precision;
	unsigned int		asterix : 1;
	unsigned int		h : 1;
	unsigned int		hh : 1;
	unsigned int		l : 1;
	unsigned int		ll : 1;
	unsigned int		j : 1;
	unsigned int		z : 1;
	char				specificate;
	char				*str;
	char				*args;
}					t_flags;

int					ft_printf(const char *format, ...);

int					ft_print(va_list elem, const char *format);
char				*ft_strjoin_f(char *s1, char *s2);
t_flags				flags_reset(t_flags flags);
void				print_flags(t_flags flags);
void				ft_putchar(char c);
size_t				ft_strlen(const char *str);
void				ft_putnbr(int nb);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_to_lowcase(const char *str);
int					sqr(int nb, int sq);
int					ft_atoi(const char *str);
char				*ft_itoa(long int nbr);
char				*ft_itoa_base(intmax_t value, int base);
int					ft_nbrlen(long int nbr);
int					ft_putstrf(char *str);
char				*ft_strdup(const char *str);
char				*ft_strchrdup(const char *str, char chr);
char				*memaloc_str(const char *str, int *i);
int					ft_strlenchr(const char *s, int c);
t_flags				ft_parse(va_list elem, t_flags flags);
t_flags				parse_flags(va_list elem, char *str, t_flags flags);
t_flags				parse_precision(va_list elem, char *str, t_flags flags);
t_flags				parse_width(va_list elem, char *str, t_flags flags);
t_flags				parse_length(va_list elem, char *str, t_flags flags);
int					ft_isdigit(int n);
int					ft_printing(char *s);
char				*fillsmb(char c, int n);
char				*spec_d_modify(int width, int prec, t_flags flags, int m);
char				*spec_x_modify(int width, int prec, t_flags flags);
char				*spec_o_modify(int width, int prec, t_flags flags);
char				*spec_u_modify(int width, int prec, t_flags flags, int minus);
intmax_t			check_lenght(t_flags flags, intmax_t d);

char				*ft_strjoin(char const *s1, char const *s2);

int					(*func[15])(va_list elem, t_flags flags);

int					ft_output_func(va_list elem, t_flags flags);

int					ft_s_low(va_list elem, t_flags flags);
int					ft_s_high(va_list elem, t_flags flags);
int					ft_p(va_list elem, t_flags flags);
int					ft_d_low(va_list elem, t_flags flags);
int					ft_d_high(va_list elem, t_flags flags);
int					ft_i(va_list elem, t_flags flags);
int					ft_o_low(va_list elem, t_flags flags);
int					ft_o_high(va_list elem, t_flags flags);
int					ft_u_low(va_list elem, t_flags flags);
int					ft_u_high(va_list elem, t_flags flags);
int					ft_x_low(va_list elem, t_flags flags);
int					ft_x_high(va_list elem, t_flags flags);
int					ft_c_low(va_list elem, t_flags flags);
int					ft_c_high(va_list elem, t_flags flags);
int					ft_percent(va_list elem, t_flags flags);

#endif
