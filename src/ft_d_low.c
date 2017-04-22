/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:57:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 19:36:56 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_d_low(va_list elem, t_flags flags)
{
	int			width;
	int			prec;
	long long	r;
	int			minus;

	minus = 0;
	r = va_arg(elem, int);
	if (r < 0)
	{
		r *= -1;
		minus = 1;
	}
	flags.args = ft_itoa(r);
	prec = flags.get_precision;
	width = flags.get_width;
	flags.args = spec_d_modify(width, prec, flags, minus);
	return (ft_printing(flags.args));
}

char		*fillsmb(char c, int n)
{
	char		*s;
	int			i;

	i = 0;
	if (n <= 0)
		n = 0;
	if (!(s = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (n-- > 0)
		s[i++] = c;
	s[i] = '\0';
	return (s);
}

char		*spec_d_modify(int width, int prec, t_flags flags, int minus)
{
	char		*res_d;
	char		*s_zero;
	char		*s_space;
	int			is_max;

	is_max = prec > (int)(ft_strlen(flags.args)) ? \
		prec : (int)(ft_strlen(flags.args));
	if (flags.zero == 1 && flags.precision == 0 && flags.minus == 0)
		s_zero = (flags.plus == 1 || minus == 1) ? \
		fillsmb('0', width - ft_strlen(flags.args) - 1) : \
		fillsmb('0', width - ft_strlen(flags.args));
	else
		s_zero = fillsmb('0', prec - ft_strlen(flags.args));
	s_space = (minus == 0 && flags.space == 0 && flags.plus == 0) ? \
		(fillsmb(' ', width - is_max)) : (fillsmb(' ', (width - is_max - 1)));
	res_d = ft_strjoin(s_zero, flags.args);
	if (flags.plus == 1 && minus != 1)
		res_d = ft_strjoin("+", res_d);
	if (minus == 1)
		res_d = ft_strjoin("-", res_d);
	if (flags.space == 1 && minus == 0 && flags.plus == 0)
		res_d = ft_strjoin(" ", res_d);
	if (flags.precision == 1 || flags.zero == 0 || flags.minus == 1)
		flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
		(res_d = ft_strjoin(s_space, res_d));
	return (res_d);
}
