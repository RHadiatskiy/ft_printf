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

int			main(void)
{
//  ft_printf("ololo%s%%ss% 4%%%%5.2sololo\n", "...", "42");
//  printf("ololo%s%%ss% 4%%%%5.2sololo\n", "...", "42");
//	ft_printf("ololo%   %\n%10.5s\n%d\n", "kokoko", 42);
//	printf("ololo%   %\n%10.5s\n%d\n", "kokoko", 42);
//	printf("------------------------------\n");
//	printf("ret ft = %d\n", ft_printf("%*.*d%   3%ololo%5s%0+- #%ss% 4%\n", 5, 3, 42, "..."));
//	printf("ret = %d\n", printf("%*.*d%   3%ololo%5s%0+- #%ss% 4%\n", 5, 3, 42, "..."));
	// printf("\nret = %d\n", printf("%hhu / %hhu", SHRT_MAX - 42, SHRT_MAX - 4200));
	// printf("\nret ft = %d\n", ft_printf("%hhu / %hhu", SHRT_MAX - 42, SHRT_MAX - 4200));
	// printf("\nret = %d\n", printf("%hhO, %hhO", 0, USHRT_MAX));
	// printf("\nret ft = %d\n", ft_printf("%hhO, %hhO", 0, USHRT_MAX));
	// printf("\nret = %d\n", printf("{%-15Z}", 123));
	// printf("\nret ft = %d\n", ft_printf("{%-15Z}", 123));
	// printf("\nret = %d\n", printf("%O", LONG_MIN));
	// printf("\nret ft = %d\n", ft_printf("%O", LONG_MIN));
	printf("\nret = %d\n", printf("{% 03d}", 0));
	printf("\nret ft = %d\n", ft_printf("{% 03d}", 0));

	return (0);
}
