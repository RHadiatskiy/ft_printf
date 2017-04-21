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

// int		ft_s_low(va_list elem, t_flags flags)
// {
// 	char	*s;
// 	int		l;
// 	int		width;
// 	int		i;

// 	i = 0;
// 	s = va_arg(elem, char *);
// 	l = ft_strlen(s);
// 	width = 0;
// 	if (flags.precision == 1)
// 		l = flags.get_precision;
// 	if (flags.width == 1)
// 		width = flags.get_width - (l < (int)(ft_strlen(s)) ? l : (int)(ft_strlen(s)));
// 	if (flags.minus == 1)
// 		while (l-- > 0)
// 			write(1, &s[i++], 1);
// 	while (width-- > 0)
// 		(flags.zero == 1 && flags.minus == 0) ? write(1, "0", 1) : \
// 		write(1, " ", 1);
// 	if (flags.minus == 0)
// 		while (l-- > 0)
// 			s ?	write(1, &s[i++], 1) : write(1, "", 1);
// 	return (flags.get_width > flags.get_precision ? flags.get_width : i);
// }

char		*spec_s_modify(int width, int prec, t_flags flags)
{
	char	*res_d;
	char	*s_space;
	int		is_max;
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
	is_max = flags.get_precision > ft_strlen(flags.args) ? \
		ft_strlen(flags.args) : flags.get_precision;
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
