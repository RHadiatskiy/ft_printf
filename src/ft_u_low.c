/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:24:31 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 19:42:18 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*spec_u_modify(int width, int prec, t_flags flags, int minus)
{
	char	*res_d;
	char	*s_zero;
	char	*s_space;
	int		is_max;

	is_max = prec > (int)(ft_strlen(flags.args)) ? prec : (int)(ft_strlen(flags.args));
	s_zero = ft_fill_symb('0', prec - (int)(ft_strlen(flags.args)));
	s_space = (minus == 0 && flags.plus == 0) ? \
		(ft_fill_symb(' ', width - is_max)) : \
		(ft_fill_symb(' ', (width - is_max - 1)));
	res_d = ft_strjoin(s_zero, flags.args);
	flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
	(res_d = ft_strjoin(s_space, res_d));
	return (res_d);
}

int			ft_u_low(va_list elem, t_flags flags)
{
	int		width;
	int		prec;
	int		r;
	int		minus;

	minus = 0;
	r = va_arg(elem, int);
	flags.args = ft_itoa((unsigned int)r);
	prec = flags.get_precision;
	width = flags.get_width;
	flags.args = spec_u_modify(width, prec, flags, minus);
	return (ft_printing(flags.args));
}
