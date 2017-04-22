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
	int		l;
	int		width;
	int		i;

	i = 0;
	s = va_arg(elem, char *);
	l = ft_strlen(s);
	width = 0;
	if (flags.precision == 1)
		l = flags.get_precision;
	if (flags.width == 1)
		width = flags.get_width - (l < ft_strlen(s) ? l : ft_strlen(s));
	if (flags.minus == 1)
		while (l-- > 0)
			write(1, &s[i++], 1);
	while (width-- > 0)
		(flags.zero == 1 && flags.minus == 0) ? write(1, "0", 1) : \
		write(1, " ", 1);
	if (flags.minus == 0)
		while (l-- > 0)
			write(1, &s[i++], 1);
	return (flags.width == 1 ? flags.get_width : i);
}

int		ft_d_low(va_list elem, t_flags flags)
{
	int		d;
	int		width;
	int		prec;

	prec = 0;
	d = va_arg(elem, int);
	width = 0;
	if (flags.minus == 1)
		ft_putnbr(d);
	if (flags.width == 1)
		width = flags.get_width - ft_nbrlen(d);
	if (flags.precision == 1)
	{
		width = flags.get_precision - ft_nbrlen(d);
		prec = flags.get_width - flags.get_precision;
	}
	while (prec-- > 0)
		write(1, " ", 1);
	while (width-- > 0)
		flags.precision == 1 ? write(1, "0", 1) : write(1, " ", 1);
	if (flags.minus == 0)
		ft_putnbr(d);
	return (flags.width == 1 ? (flags.get_width > ft_nbrlen(d) ? \
		flags.get_width : ft_nbrlen(d)) : flags.precision == 1 ? \
		((flags.get_precision - ft_nbrlen(d)) + ft_nbrlen(d)) : ft_nbrlen(d));
}

int		ft_percent(va_list elem, t_flags flags)
{
	int		i;
	int		width;

	i = 1;
	width = flags.get_width;
	while (flags.str[i] == ' ' && flags.str[i])
		i++;
	if (flags.minus == 1)
		write(1, "%", 1);
	while (width-- > 1)
		(flags.zero == 1 && flags.minus == 0) ?	write(1, "0", 1) : \
		write(1, " ", 1);
	if (flags.minus != 1)
		write(1, "%", 1);
	return (flags.width == 1 && flags.get_width != 0 ? flags.get_width : 1);
}