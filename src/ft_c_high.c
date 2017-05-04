/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_high.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:43:45 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/24 14:43:47 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

// char		*spec_c_high_modify(int width, t_flags flags, wchar_t c)
// {
// 	char		*res_d;
// 	char		*s_space;
// 	int			i;

// 	i = 0;
// 	if (flags.zero == 1 && flags.minus != 1)
// 		s_space = fillsmb('0', width - 1);
// 	else
// 		s_space = fillsmb(' ', width - 1);
// 	res_d = (char *)malloc(sizeof(char) + 1);
// 	res_d[i++] = c;
// 	res_d[i] = '\0';
// 	flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
// 	(res_d = ft_strjoin(s_space, res_d));
// 	return (res_d);
// }

int			ft_c_high(va_list elem, t_flags flags)
{
//	int			width;
	wchar_t		c;

	(void)flags;
	c = (wchar_t)va_arg(elem, void *);
//	width = flags.get_width;
//	flags.args = spec_c_high_modify(width, flags, c);
	return (choose_mask(c));
}
