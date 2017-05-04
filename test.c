/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:41:36 by rhadiats          #+#    #+#             */
/*   Updated: 2017/03/06 18:04:11 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char		*ft_itoa_base_x(uintmax_t value, int base);

int		main(void)
{
	// unsigned char c;
 //    c = 0xe1;
 //    write(1, &c, 1);
 //    c = 0x88;
 //    write(1, &c, 1);
 //    c = 0xb4;
 //    write(1, &c, 1);
 //    c = 0x0a;
 //    write(1, &c, 1);
	int				a;
	unsigned int 	b;
	a = 42;
	b = -42;
    printf("42 : %c\n", 42);
    printf("-42 : %c\n", -42);
    printf("a : %c\n", a);
    printf("b : %c\n", b);
    return (0);
}