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

int				ft_printf(const char *format, ...)
{
	va_list		elem;
	int			ret;

	ret = 0;
	va_start(elem, format);
	ret = ft_print(elem, format);
	va_end(elem);
	return (ret);
}

int				ft_print(va_list elem, const char *format)
{
	int			i;
	int			ret;
	t_flags		flags;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, &format[i], 1);
			i += 2;
			ret += 1;
		}
		else if (format[i] == '%' && format[i + 1] != '%' && format[i + 1])
		{
			flags = flags_reset(flags);
			flags.str = memaloc_str(format, &i);
			ft_parse(elem, &flags);
			ret += ft_output_func(elem, flags);
			// print_flags(flags);
			// write(1, "------------------------------\n", 31);
			free(flags.str);
			free(flags.args);
		}
		else
		{
			if (format[i] == '%')
				i++;
			else
				ret += (write(1, &format[i++], 1));
		}
	}
	return (ret);
}

char			*ft_strjoin_f(char *s1, char *s2)
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

char			*ft_strchrdup(const char *str, char chr)
{
	int		i;
	int		j;
	char	*dup;

	i = 1;
	j = 0;
	while (str[i] && str[i] != chr && \
		(ft_strlenchr(SPECIFICATE, str[i] == -1)))
		i++;
	if (!(dup = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	i = 1;
	dup[j++] = str[0];
	while (str[i] && str[i] != chr && \
		(ft_strlenchr(SPECIFICATE, str[i]) == -1))
		dup[j++] = str[i++];
	dup[j++] = str[i++];
	dup[j] = '\0';
	return (dup);
}

char			*memaloc_str(const char *str, int *i)
{
	int			l;
	char		*s;

	l = *i;
	(*i) += 1;
	while (str[*i] != 's' && str[*i] != 'S' && str[*i] != 'p' && \
		str[*i] != 'd' && str[*i] != 'D' && str[*i] != 'i' && \
		str[*i] != 'o' && str[*i] != 'O' && str[*i] != 'u' && \
		str[*i] != 'U' && str[*i] != 'x' && str[*i] != 'X' && \
		str[*i] != 'c' && str[*i] != 'C' && str[*i] != '%' && str[(*i) + 1])
	{
		if ((str[(*i) + 1] == '%') && \
			(ft_strlenchr(SPECIFICATE, str[(*i) + 2]) != -1))
			break ;
		(*i)++;
	}
	if (!(s = ft_strchrdup(&str[l], str[(*i) + 1])))
		return (NULL);
	(*i)++;
	return (s);
}
