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
	//	ft_print("%s%d%u%lld%i%o", "");
	t_flags		flags;
	flags = flags_reset(flags);
	printf("------------------------------\n");
	flags = ft_print("ololo%s%%ss%5%%%%05.3dololo\n", "...", "...");
	printf("ololo%s%%ss%5%%%%5.3dololo\n", "<FLAG>", 42);
	printf("------------------------------\n");
	print_flags(flags);
	printf("------------------------------\n");
	flags = ft_parse(flags);
	print_flags(flags);

	return (0);
}
