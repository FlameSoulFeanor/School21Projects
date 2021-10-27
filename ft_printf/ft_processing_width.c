/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:16:27 by hfunctio          #+#    #+#             */
/*   Updated: 2021/01/25 14:43:34 by hfunctio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_base(unsigned long long nbr, int base, int count, char *str)
{
	while (nbr != 0)
	{
		if ((nbr % base) < 10)
			str[count - 1] = (nbr % base) + 48;
		else
			str[count - 1] = (nbr % base) + 55;
		nbr /= base;
		count--;
	}
	return (str);
}

char		*ft_utl_base(unsigned long long nbr, int base)
{
	unsigned long long	tmp;
	int					count;
	char				*str;

	tmp = nbr;
	str = 0;
	count = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr != 0)
	{
		nbr /= base;
		count++;
	}
	if (!(str = malloc(count + 1)))
		return (0);
	str[count] = '\0';
	str = ft_base(tmp, base, count, str);
	return (str);
}

int			ft_processing_width(int width, int len, int zero)
{
	int count;

	count = 0;
	while (width > len)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}
