/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_none.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:37:02 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/27 12:37:03 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_none(va_list elem, t_flags flags)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	(void)elem;
	while (flags.str[i])
	{
		if ((ft_strlenchr(SPECIFICATE, flags.str[i]) == -1) && flags.str[i] != 'l' && \
			flags.str[i] != 'h' && flags.str[i] != 'j' && flags.str[i] != 'z' && \
			flags.str[i] != ' ' && flags.str[i] != '.' && flags.str[i] != '-' && \
			flags.str[i] != '+' && !ft_isdigit(flags.str[i]))
			while ((ft_strlenchr(SPECIFICATE, flags.str[i]) == -1) && flags.str[i])
			{
				write(1, &flags.str[i++], 1);
				count++;
			}
		else
			i++;
	}
	return (count);
}