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
//#include "../include/libprintf.h"

//t_flags		parse_flags(char *str, t_flags flags);
//int		parse_precision(char *str);
//int		parse_width(char *str);

t_flags		ft_parse(t_flags flags)
{
	int		i;

	i = 1;
	flags = parse_flags(flags.str, flags);
	flags.width = parse_width(flags.str);
	flags.precision = parse_precision(flags.str);
//	flags.length = parse_length(flags.str);
	return (flags);
}

t_flags		parse_flags(char *str, t_flags flags)
{
	int		i;

	i = 1;
	while (str[i])
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

int		parse_precision(char *str)
{
	int		i;
	int		nb;

	i = 1;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '.')
			nb = ft_atoi(&str[++i]);
		i++;
	}
	return (nb);
}

int		parse_width(char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while ((ft_isdigit(str[i++])) != 1 && str[i] != '.')
		;
	return (ft_atoi(&str[i - 1]));
}

int		main(void)
{
	t_flags	flags;
	flags.str = "%      #-+5.42lls\n";
	flags = ft_parse(flags);
	print_flags(flags);
//	printf("precision = %d\n", parse_precision(str));
//	printf("width = %d\n", parse_width(str));
	return (0);
}
