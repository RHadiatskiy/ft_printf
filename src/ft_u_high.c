/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_high.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:34:15 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/24 14:34:17 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

intmax_t	check_lenght_u_high(t_flags flags, intmax_t d)
{
	if (flags.ll == 1)
		return ((unsigned long long)d);
	else if (flags.z == 1)
		return ((size_t)d);
	else if (flags.j == 1)
		return ((uintmax_t)d);
	else if (flags.l == 1)
		return ((unsigned long)d);
	else
		return ((unsigned long int)d);	
}

int			ft_u_high(va_list elem, t_flags flags)
{
	int				width;
	int				prec;
	intmax_t		r;
	int				minus;

	minus = 0;
	r = check_lenght_u_high(flags, va_arg(elem, intmax_t));
	flags.args = ft_itoa_base(r, 10);
	prec = flags.get_precision;
	width = flags.get_width;
	flags.args = spec_u_modify(width, prec, flags, minus);
	return (ft_printing(flags.args));
}
