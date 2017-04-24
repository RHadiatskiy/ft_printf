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
	printf("u : %llu\n", 4294967296);
	printf("U : %llU\n", 4294967296);
	printf("null : %s\n", NULL);
	return (0);
}