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

	n = 0;
	i = 0;
	(void)flags;
	s = (wchar_t *)va_arg(elem, wchar_t *);
	if (s == NULL)
	{
		flags.args = ft_strdup("(null)");
		return (ft_printing(flags.args));
	}
	while (s[i])
		n += choose_mask(s[i++]);
	return (n);
}
