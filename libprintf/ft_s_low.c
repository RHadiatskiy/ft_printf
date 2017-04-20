/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:33:31 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/20 14:33:33 by rhadiats         ###   ########.fr       */
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
	return (flags.get_width > flags.get_precision ? flags.get_width : i);
}
