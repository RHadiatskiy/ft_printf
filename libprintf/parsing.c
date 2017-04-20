/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:28:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/12 21:56:26 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_flags		ft_parse(va_list elem, t_flags flags)
{
	flags = parse_flags(elem, flags.str, flags);
	flags = parse_width(elem, flags.str, flags);
	flags = parse_precision(elem, flags.str, flags);
	flags = parse_length(elem, flags.str, flags);
	flags.specificate = flags.str[ft_strlen(flags.str) - 1];
	return (flags);
}

t_flags		parse_flags(va_list elem, char *str, t_flags flags)
{
	int		i;

	i = 1;
	while (str[i] && (ft_atoi(&str[i - 1]) == 0))
	{
		if (str[i] == '0' || str[i] == ' ' || \
			str[i] == '+' || str[i] == '-' || \
			str[i] == '#')
		{
			if (str[i] == '0')
				flags.zero = 1;
			else if (str[i] == ' ')
				flags.space = 1;
			else if (str[i] == '+')
				flags.plus = 1;
			else if (str[i] == '-')
				flags.minus = 1;
			else if (str[i] == '#')
				flags.hash = 1;
		}
		i++;
	}
	return (flags);
}

t_flags		parse_precision(va_list elem, char *str, t_flags flags)
{
	int		i;
	
	i = 1;
	while (str[i])
	{
		if (str[i] == '.')
		{
			flags.precision = 1;
			if (str[++i] == '*')
				flags.get_precision = va_arg(elem, int);
			else
				flags.get_precision = ft_atoi(&str[i++]);
		}
		i++;
	}
	return (flags);
}

t_flags		parse_width(va_list elem, char *str, t_flags flags)
{
	int		i;

	i = 1;
	while (str[i] != '.' && str[i] != 'l' && \
		str[i] != 'h' && str[i] != 'j' && \
		str[i] != 'z' && str[i] != '%' && \
		str[i] && ft_strlenchr(SPECIFICATE, str[i]) == -1)
	{
		if (str[i] == ' ')
			i++;
		else if (ft_isdigit(str[i]) == 1 && flags.asterix != 1)
		{
			flags.get_width = flags.get_width * 10 + (str[i++] - '0');
			flags.width = 1;
		}
		else if (ft_isdigit(str[i]) != 1 && str[i] != ' ' && str[i++] != '*')
		{
			flags.get_width = 0;
			flags.width = 0;
		}
		else if (str[i++] == '*')
		{
			flags.get_width = va_arg(elem, int);
			flags.asterix = 1;
			flags.width = 1;
		}
	}
	return (flags);
}

t_flags		parse_length(va_list elem, char *str, t_flags flags)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'h' || str[i] == 'l' || \
			str[i] == 'j' || str[i] == 'z')
		{
			if (str[i] == 'h' && str[i + 1] == 'h')
				flags.hh = 1;
			else if (str[i] == 'h' && str[i + 1] != 'h' && str[i - 1] != 'h')
				flags.h = 1;
			else if (str[i] == 'l' && str[i + 1] != 'l' && str[i - 1] != 'l')
				flags.l = 1;
			else if (str[i] == 'l' && str[i + 1] == 'l')
				flags.ll = 1;
			else if (str[i] == 'j')
				flags.j = 1;
			else if (str[i] == 'z')
				flags.z = 1;
		}
		i++;
	}
	return (flags);
}
