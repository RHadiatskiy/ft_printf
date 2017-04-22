/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_high.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 22:19:37 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/22 22:19:39 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*mal_uppercase(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s || !(str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			str[j++] = s[i++] - 32;
		else
			str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}

int			ft_x_high(va_list elem, t_flags flags)
{
	int		width;
	int		prec;
	int		r;

	r = va_arg(elem, int);
	flags.args = ft_itoa_base((unsigned int)r, 16);
	prec = flags.get_precision;
	width = flags.get_width;
	flags.args = spec_x_modify(width, prec, flags);
	flags.args = mal_uppercase(flags.args);
	return (ft_printing(flags.args));
}
