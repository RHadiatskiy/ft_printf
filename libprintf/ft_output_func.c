/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:49:56 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/14 17:49:58 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_output_func(va_list elem, t_flags flags)
{
	int		n;

	n = ft_strlenchr(SPECIFICATE, flags.str[ft_strlen(flags.str) - 1]);
	func[0] = ft_s_low;
//	func_arr[1] = ft_s_high;
//	func_arr[2] = ft_p;
	func[3] = ft_d_low;
//	func_arr[4] = ft_d_high;
//	func_arr[5] = ft_i;
//	func_arr[6] = ft_o_low;
//	func_arr[7] = ft_s_high;
//	func_arr[8] = ft_u_low;
//	func_arr[9] = ft_u_high;
//	func_arr[10] = ft_x_low;
//	func_arr[11] = ft_x_high;
//	func_arr[12] = ft_c_low;
//	func_arr[13] = ft_c_high;
	func[14] = ft_percent;
	return ((*func[n])(elem, flags));
}
