/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:51:09 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/22 18:51:14 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*spec_c_modify(int width, t_flags flags, char c)
{
	char	*res_d;
	char	*s_space;
	int		i;

	i = 0;
	s_space = fillsmb(' ', width - 1);
	res_d = (char *)malloc(sizeof(char) + 1);
	res_d[i++] = c;
	res_d[i] = '\0';
	flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
	(res_d = ft_strjoin(s_space, res_d));
	return (res_d);
}

int			ft_c_low(va_list elem, t_flags flags)
{
	int		width;
	char	c;

	c = (char)va_arg(elem, void *);
	width = flags.get_width;
	flags.args = spec_c_modify(width, flags, c);
	return (ft_printing(flags.args));
}
