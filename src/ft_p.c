/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:28:36 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/24 12:28:38 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int					ft_p(va_list elem, t_flags flags)
{
	intmax_t	p;
	
	p = va_arg(elem, intmax_t);
	flags.args = ft_strjoin("0x", ft_itoa_base(p, 16));
	return (ft_printing(flags.args));
}
