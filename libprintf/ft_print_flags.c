/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:00:26 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/14 17:00:29 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_flags(t_flags flags)
{
	printf("\n%-15s", "ZERO :");
	printf("%15d\n", flags.zero);
	printf("%-15s", "PLUS :");
	printf("%15d\n", flags.plus);
	printf("%-15s", "MINUS :");
	printf("%15d\n", flags.minus);
	printf("%-15s", "SPACE :");
	printf("%15d\n", flags.space);
	printf("%-15s", "HASH :");
	printf("%15d\n", flags.hash);
	printf("%-15s", "WIDTH :");
	printf("%15d\n", flags.width);
	printf("%-15s", "PRECISION :");
	printf("%15d\n", flags.precision);
	printf("%-15s", "GET WIDTH :");
	printf("%15d\n", flags.get_width);
	printf("%-15s", "GET PRECISION :");
	printf("%15d\n", flags.get_precision);
	printf("%-15s", "ASTERIX:");
	printf("%15d\n", flags.asterix);
	printf("%-15s", "h :");
	printf("%15d\n", flags.h);
	printf("%-15s", "hh :");
	printf("%15d\n", flags.hh);
	printf("%-15s", "l :");
	printf("%15d\n", flags.l);
	printf("%-15s", "ll :");
	printf("%15d\n", flags.ll);
	printf("%-15s", "j :");
	printf("%15d\n", flags.j);
	printf("%-15s", "z :");
	printf("%15d\n", flags.z);
	printf("%-15s", "SPECIFICATE :");
	printf("%15c\n", flags.specificate);
	printf("%-15s", "STRING :");
	printf("%15s\n", flags.str);
	printf("%-15s", "ARGUMENT :");
	printf("%15s\n", flags.args);
}
