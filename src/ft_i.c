/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:37:00 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 15:37:02 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_i(va_list elem, t_flags flags)
{
	int		width;
	int		prec;
	int		r;
	int		minus;

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
	if ((flags.zero != 1) && (ft_strcmp(flags.args, "0") == 0) && \
		flags.precision == 1)
		flags.args = ft_strdup("");
	flags.args = spec_d_modify(width, prec, flags, minus);
	return (ft_printing(flags.args));
}
