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

int			ucodelen(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c > 127 && c <= 2047)
		return (2);
	else if (c > 2047 && c <= 65535)
		return (3);
	else
		return (4);
}

int			choose_mask_f(unsigned int value, int prec)
{
	unsigned int	mask[4];

	mask[0] = 0;
	mask[1] = 49280;
	mask[2] = 14712960;
	mask[3] = 4034953344;
	// printf("YES!");
	f_uprec[0] = take_mask_0;
	f_uprec[1] = take_mask_1;
	f_uprec[2] = take_mask_2;
	f_uprec[3] = take_mask_3;
	return ((*f_uprec[prec - 1])(value, mask[prec - 1]));
}

int			ft_strlen_u(wchar_t *s)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i])
		len += ucodelen(s[i++]);
	return (len);
}

int			print_u_prec(wchar_t *s, int prec)
{
	int		i;
	int		sum;
	int		n;

	n = 0;
	sum = prec;
	i = 0;
	while (s[i] && prec > i)
	{
		if (ucodelen(s[i]) <= sum)
		{
			n += choose_mask(s[i]);
			sum -= ucodelen(s[i]);
		}
		else if (sum > 0)
			n += choose_mask_f(s[i], sum);
		i++;
	}
	return (n);
}

int			ft_s_high(va_list elem, t_flags flags)
{
	wchar_t		*s;
	int			i;
	int			n;
	int			wise;

	n = 0;
	i = 0;
	(void)flags;
	s = (wchar_t *)va_arg(elem, wchar_t *);
	if (s == NULL)
	{
		flags.args = ft_strdup("(null)");
		return (ft_printing(flags.args));
	}
	wise = flags.get_width - (flags.precision == 1 ? \
		flags.get_precision : ft_strlen_u(s));
	if (flags.zero == 1)
		while (wise-- > 0)
			n += write(1, "0", 1);
	if (flags.precision == 1)
		n += print_u_prec(s, flags.get_precision);
	else
		while (s[i])
			n += choose_mask(s[i++]);
	return (n);
}
