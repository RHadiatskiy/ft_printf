/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:33:19 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/12 21:54:07 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_to_lowcase(const char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!str || !(s = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			s[j++] = str[i++] + 32;
		else
			s[j++] = str[i++];
	}
	s[j] = '\0';
	return (s);
}

int		sqr(int nb, int sq)
{
	int n;
	int i;

	i = 0;
	n = 1;
	while (sq > i)
	{
		n = n * nb;
		i++;
	}
	return (n);
}


/*
**	char	*fill_base(void)
**	{
**	char	*base;
**	int		i;
**	char	c;
**	int		l;
**
**	i = 0;
**	l = 'a';
**	c = '0';
**	if (!(base = (char *)malloc(sizeof(char) * 17)))
**		return (NULL);
**	while (i < 10)
**		base[i++] = c++;
**	while (i < 16)
**		base[i++] = l++;
**	base[i] = '\0';
**	return (base);
**	}
*/

int		ft_atoi_base(const char *str, int str_base)
{
	int		len;
	int		nb;
	int		convert_nb[64];
	char	base_base;
	int		i;
	int		j;

	if (str_base > 16)
		return (0);
	len = ft_strlen(str) - 1;
	nb = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		while (j < 16)
		{
			if (str[i] == base[j])
				convert_nb[i++] = j;
			else
				j++;
		}
		j = 0;
	}
	while (len >= 0)
		nb = nb + (sqr(str_base, len--) * convert_nb[j++]);
	return (nb);
}
/*
int		main(void)
{
	const char str[] = "42";

	printf("%d\n", ft_atoi_base(ft_to_lowcase(str), 8));
	return (0);
}
*/
