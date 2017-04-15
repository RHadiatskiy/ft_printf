/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_output_1_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:57:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/14 17:58:00 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_s_low(va_list elem, t_flags flags)
{
	char	*s;
	int		length;
	int		width;
	int		i;

	i = 0;
	s = va_arg(elem, char *);
	length = ft_strlen(s);
	width = 0;
	if (flags.precision == 1)
		length = flags.get_precision;
	if (flags.width == 1)
		width = flags.get_width - (length < ft_strlen(s) ? length : ft_strlen(s));
	if (flags.minus == 1)
		while (length-- > 0)
			write(1, &s[i++], 1);
	while (width-- > 0)
	{
		if (flags.zero == 1 && flags.minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	if (flags.minus == 0)
		while (length-- > 0)
			write(1, &s[i++], 1);
	return (i);
}

int		ft_d_low(va_list elem, t_flags flags)
{
	int		d;

	d = va_arg(elem, int);
	ft_putnbr(d);
	return (0);
}

int		ft_percent(va_list elem, t_flags flags)
{
	int		i;

	i = 1;
	while (flags.str[i] == ' ' && flags.str[i])
		i++;
	if (flags.minus == 1)
		write(1, "%", 1);
	while (flags.get_width-- > 1)
	{
		if (flags.zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	if (flags.minus != 1)
		write(1, "%", 1);
	return (0);
}
