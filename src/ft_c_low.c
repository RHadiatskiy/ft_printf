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

char	*ft_strnew(size_t size);

char		*spec_c_modify(int width, t_flags flags, char c)
{
	char	*res_d;
	char	*s_space;
	int		i;

	i = 0;
	if (flags.zero == 1 && flags.minus != 1)
		s_space = fillsmb('0', width -1);
	else
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

	if (!(c = (char)va_arg(elem, void *)) && flags.width == 0)
		return (1);
	width = flags.get_width;
	flags.args = spec_c_modify(width, flags, c);
	return (ft_printing(flags.args));
}
