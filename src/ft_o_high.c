/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_high.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:34:40 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/24 14:34:41 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_o_high(va_list elem, t_flags flags)
{
	int		width;
	int		prec;
	int		r;

	r = va_arg(elem, int);
	flags.args = ft_itoa_base((unsigned int)r, 8);
	prec = flags.get_precision;
	width = flags.get_width;
	flags.args = spec_o_modify(width, prec, flags);
	return (ft_printing(flags.args));
}
