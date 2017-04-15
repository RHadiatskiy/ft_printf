/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:37:39 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/06 15:37:42 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
//#include "include/libprintf.h"

int			main(void)
{
	t_flags		flags;
//	printf("------------------------------\n");
	ft_printf("ololo%s%%ss%-04.0%%%%5.2sololo\n", "...", "42");
	printf("ololo%s%%ss%-04.0%%%%5.2sololo\n", "...", "42");
//	ft_printf("ololo%   %\n%10.5s\n%d\n", "kokoko", 42);
//	printf("ololo%   %\n%10.5s\n%d\n", "kokoko", 42);
//	printf("ret ft = %d\n", ft_printf("azaza%s\n", "ololo"));
//	printf("ret = %d\n", printf("azaza%s\n", "ololo"));
	return (0);
}
