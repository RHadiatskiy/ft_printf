/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:33:31 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/21 19:41:15 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*spec_s_modify(int width, int prec, t_flags flags)
{
	char	*res_d;
	char	*s_space;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (flags.precision == 1)
	{
		res_d = (char *)malloc(sizeof(char) * prec + 1);
		while (prec > i)
			res_d[i++] = flags.args[j++];
		res_d[i] = '\0';
	}
	else
		res_d = ft_strdup(flags.args);	
	s_space = ft_fill_symb(' ', width - ft_strlen(res_d));
	flags.minus == 1 ? (res_d = ft_strjoin(res_d, s_space)) : \
	(res_d = ft_strjoin(s_space, res_d));
	return (res_d);
}

int			ft_s_low(va_list elem, t_flags flags)
{
	int		width;
	int		prec;
	
	flags.args = va_arg(elem, char *);
	prec = flags.get_precision;
	width = flags.get_width;
	flags.args = spec_s_modify(width, prec, flags);
	return (ft_printing(flags.args));
}
