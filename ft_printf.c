/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:28:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/03/22 19:20:59 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
//#include "include/libprintf.h"

t_flags		ft_print(char *format, ...)
{
	va_list		elem;
	t_flags		flags;
	int			i;
	int			n;
	char		*s;
	TYPE_F

	i = 0;
	n = 0;
	va_start(elem, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, &format[i], 1);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			flags.str = memaloc_str(format, &i);
//			printf("\nflags : %-15s", flags.str);
			n = ft_strlenchr(SPECIFICATE, flags.str[ft_strlen(flags.str) - 1]);
			flags = ft_parse(flags);
//			printf("id : %-15d", n);
			flags.specificate = flags.str[ft_strlen(flags.str) - 1];
//			flags.precision = parse_precision(flags.str);
//			flags.width = parse_width(flags.str);
			write(1, "<FLAG>", 6);
		}
		else
			write(1, &format[i++], 1);
	}
	va_end(elem);
	return (flags);
}

char		*ft_strjoin_f(char *s1, char *s2)
{
	char	*s_join;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!s1 || !s2 || \
		!(s_join = (char *)malloc(sizeof(char) * i + j + 3)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		s_join[j++] = s1[i++];
	s_join[j++] = ' ';
	i = 0;
	while (s2[i])
		s_join[j++] = s2[i++];
	s_join[j++] = ' ';
	s_join[j] = '\0';
	return (s_join);
}

char		*ft_strchrdup(char *str, char chr)
{
	int		i;
	int		j;
	char	*dup;

	i = 1;
	j = 0;
	while (str[i] && str[i] != chr)
		i++;
	if (!(dup = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	i = 1;
	dup[j++] = str[0];
	while (str[i] && str[i] != chr)
		dup[j++] = str[i++];
	dup[j++] = str[i++];
	dup[j] = '\0';
	return (dup);
}

t_flags		flags_reset(t_flags flags)
{
	flags.zero = 0;
	flags.plus = 0;
	flags.minus = 0;
	flags.space = 0;
	flags.hash = 0;
//	flags.point = 0;
	flags.width = 0;
	flags.precision = 0;
//	flags.lenght = 0;
	flags.specificate = 0;
	flags.str = NULL;
	flags.args = NULL;
	return (flags);
}

void	print_flags(t_flags flags)
{
	printf("%-15s", "ZERO :");
	printf("%15d\n", flags.zero);
	printf("%-15s", "PLUS :");
	printf("%15d\n", flags.plus);
	printf("%-15s", "MINUS :");
	printf("%15d\n", flags.minus);
	printf("%-15s", "SPACE :");
	printf("%15d\n", flags.space);
	printf("%-15s", "HASH :");
	printf("%15d\n", flags.hash);
//	printf("%-15s", "POINT :");
//	printf("%15d\n", flags.point);
	printf("%-15s", "WIDTH :");
	printf("%15d\n", flags.width);
	printf("%-15s", "PRECISION :");
	printf("%15d\n", flags.precision);
//	printf("%-15s", "LENGHT :");
//	printf("%15d\n", flags.lenght);
	printf("%-15s", "SPECIFICATE :");
	printf("%15c\n", flags.specificate);
	printf("%-15s", "STRING :");
	printf("%15s\n", flags.str);
	printf("%-15s", "ARGUMENT :");
	printf("%15s\n", flags.args);
}

char		*memaloc_str(char *str, int *i)
{
	int			l;
	char		*s;

	l = *i;
	*i += 1;
	while (str[*i] != 's' && str[*i] != 'S' && str[*i] != 'p' && \
		str[*i] != 'd' && str[*i] != 'D' && str[*i] != 'i' && \
		str[*i] != 'o' && str[*i] != 'O' && str[*i] != 'u' && \
		str[*i] != 'U' && str[*i] != 'x' && str[*i] != 'X' && \
		str[*i] != 'c' && str[*i] != 'C' && str[*i] != '%' && str[*i])
		(*i)++;
	if (!(s = ft_strchrdup(&str[l], str[*i])))
		return (NULL);
	(*i)++;
	return (s);
}
