/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_high.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:54:59 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/04 20:55:01 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_s_high(va_list elem, t_flags flags)
{
	wchar_t		*s;
	int			i;
	int			n;
	int			wise;

	n = 0;
	i = 0;
	(void)flags;
	wise = flags.get_width - flags.get_precision;
	s = (wchar_t *)va_arg(elem, wchar_t *);
	if (s == NULL)
	{
		flags.args = ft_strdup("(null)");
		return (ft_printing(flags.args));
	}
	if (flags.zero == 1)
		while (wise-- > 0)
			n += write(1, "0", 1);
	if (flags.precision == 1)
		while(s[i] && i < flags.get_precision)
			n += choose_mask(s[i++]);
	else
		while (s[i])
			n += choose_mask(s[i++]);
	return (n);
}
